#include<iostream>
#include<atomic>
#include<thread>
#include<cassert>
using namespace std;
/*
    : Fences are global operations and affect the ordering of other atomic operations 
      in the thread that executed the fence.
    : Fences are also commonly called memory barriers, as certain operations are not permitted
      beyond this line in the code
    : The free reordering of instructions by the compiler or the hardware is 
      totally restricted by 'fence'.
*/
atomic<bool> x,y;
atomic<int> z;

void write_x_then_y()
{
    x.store(true, std::memory_order_relaxed);
    std::atomic_thread_fence(std::memory_order_release);
    y.store(true, std::memory_order_relaxed);
}

void read_y_then_x()
{
    while(!y.load(std::memory_order_relaxed));
    std::atomic_thread_fence(std::memory_order_acquire);
    if(x.load(std::memory_order_relaxed))
        ++z;
}

int main()
{
    x=false;
    y=false;
    z=0;
    thread th1(write_x_then_y);
    
    thread th2(read_y_then_x);   
    thread th3(read_y_then_x);

    th1.join();
    th2.join();
    th3.join();

    cout <<"z = " << z.load() << endl;
    assert(z != 0);
    return 0;
}