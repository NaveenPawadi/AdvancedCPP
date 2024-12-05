#include <condition_variable>
#include <future>
#include <iostream>
#include <mutex>
#include <chrono>
#include<thread>

using namespace std;

enum class thread_state
{
    starting,
    started,
    stopping,
    stopped
};

class thread_state_t
{
public:
    thread_state_t() :
        m_state{ thread_state::starting }
    {
    }

    void stop()
    {
        std::unique_lock<std::mutex> lock{ m_mtx };
        if (m_state == thread_state::started)
        {
            m_state = thread_state::stopping;
            m_cv.notify_all();
        }
    }

    void set_started()
    {
        std::unique_lock<std::mutex> lock{ m_mtx };
        if (m_state == thread_state::starting)
        {
            m_state = thread_state::started;
            m_cv.notify_all();
        }
    }

    void set_stopped()
    {
        std::unique_lock<std::mutex> lock{ m_mtx };
        m_state = thread_state::stopped;
        m_cv.notify_all();
    }

    void wait_for_state(const thread_state state) 
    {
        std::unique_lock<std::mutex> lock{ m_mtx };
        m_cv.wait(lock, [&] {return m_state == state; });
    }

    bool is_running() 
    {
        std::unique_lock<std::mutex> lock{ m_mtx };
        return (m_state == thread_state::started);
    }

private:
    std::mutex m_mtx;
    std::condition_variable m_cv;
    thread_state m_state;
};


int main()
{
    auto thread1_state = std::make_shared<thread_state_t>();

    // important capture thread1_state by value
    // so its lifetime gets extended for the duration of this thread
    auto f1 = std::async(std::launch::async, [thread1_state]
    {
        thread1_state->set_started();
        std::cout << "thread 1 started\n";

        while (thread1_state->is_running())
        {
            // simulate doing some work.
            std::cout << ".";
            std::this_thread::sleep_for(std::chrono::milliseconds(20));
        }
        
        thread1_state->set_stopped();
        std::cout << "thread 1 done\n";
    });

    // important due to thread scheduling we must
    // wait for thread1 to be in a started state so we also know it is ready to receive a 
    // stop signal if we don't do that we can have raceconditions
    std::cout << "main thread waiting for thread 1 to start and be in a stable state\n";
    thread1_state->wait_for_state(thread_state::started);

    // start the second thread
    auto f2 = std::async(std::launch::async, [thread1_state]
    {
        std::cout << "thread 2 started\n";

        // simulate some work before stopping thread 1.
        std::this_thread::sleep_for(std::chrono::milliseconds(500));

        std::cout << "thread 2 asking thread 1 to stop\n";
        thread1_state->stop();

        std::cout << "thread 2 waiting for thread 1 to have stopped\n";
        thread1_state->wait_for_state(thread_state::stopped);

        std::cout << "thread 2 done\n";
    });

    // synchronize with both threads 
    f2.get();
    f1.get();

    return 0;
}

