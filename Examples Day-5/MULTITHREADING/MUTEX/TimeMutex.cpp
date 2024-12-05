#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
using namespace std;
/*
    - Attempt's to lock the mutex for a specified period or until a specific point in time.
    - Scenarios where a thread should not wait indefinitely to acquire a lock. 
    - Instead, it can perform other tasks if it fails to acquire the mutex within a given time frame
*/
timed_mutex tmtx;
auto lm = []()
{
    tmtx.lock();
    cout <<"running child 'lm' thread, waiting for 2 seconds" << endl;
    //this_thread::sleep_for(chrono::milliseconds(200));
    this_thread::sleep_for(chrono::seconds(2));
    tmtx.unlock();
};
void try_locking_mutex_for_duration() 
{
    
    if (tmtx.try_lock_for(std::chrono::seconds(1)))
    {
        std::cout << "Acquired lock within 1 second!" << std::endl;
        tmtx.unlock();
    }
    else
    {
        std::cout << "Failed to acquire lock within 1 second!" << std::endl;
    }

    
}

int main()
{
    thread th1(lm);
    thread th2(lm);
    thread th3(lm);

    std::thread t(try_locking_mutex_for_duration);
    t.join();


    th1.join();
    th2.join();
    th3.join();
    return 0;
}
