#include<iostream>
#include<thread>
#include<atomic>
#include<mutex>
#include<conio.h>
using namespace std;

/*
    std::atomic_flag instances upon defining must and should be initialized 
    with macro ATOMIC_FLAG_INIT
    
    The macro ATOMIC_FLAG_INIT sets the atomic_flag instance to clear state.

    Instances of 'atomic' types are not copy constructable nor assignable

    Member function...
    std::atomic_flag::clear - is a store operation
    std::atomic_flag::test_and_set - is read/write/modify operation
*/
class spinlock_mutex
{
private:
    std::atomic_flag f = ATOMIC_FLAG_INIT;  //flag clear, mutex in un-locked state
public:
    void lock()  //loop and test_and_set until the old value is false
    {
        while(f.test_and_set(std::memory_order_acquire));
    }

    void unlock()
    {
        f.clear(std::memory_order_release);
    }
};

spinlock_mutex Mylock;

void fun1()
{
    Mylock.lock();
    cout << "Thread "<<this_thread::get_id() << " acquired lock..." << endl;
    for(int i = 1;i<=100;i++)
    {
        //cout <<"thread id =" << this_thread::get_id() << endl;
        cout <<"i =" << i << endl;
    }
    cout << "Thread "<<this_thread::get_id() << " unlocks..." << endl;
    Mylock.unlock();
    
}

void fun2()
{
    std::lock_guard<spinlock_mutex> guard(Mylock);
    cout << "Thread "<<this_thread::get_id() << " acquired lock..." << endl;
    for(int i = 1;i<=100;i++)
    {
        //cout <<"thread id =" << this_thread::get_id() << endl;
        cout <<"i =" << i << endl;
    }
    cout << "Thread "<<this_thread::get_id() << " unlocks..." << endl;
}

int main()
{
    thread th1(fun1);
    thread th2(fun1);
    //...
    th1.join();
    th2.join();
   
    return 0;
}