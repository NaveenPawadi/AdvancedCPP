#include<iostream>
#include<atomic>
#include<thread>
#include<cassert>
using namespace std;
/*
    - In order to get the advantage of 'memory_order_relaxed and acquire' we need
      to group both the write operations together in one thread and both read operations 
      in one thread.

    - Here during store, the memory order 
        - on 'x' is 'relaxed' and 'y' is 'release'
    - Where as during the load, the memory order
        - on 'y' is 'acquire'  and on 'x' it is 'relaxed'
*/
atomic<bool> x,y;
atomic<int> z;

void write_x_then_y()
{
    x.store(true, std::memory_order_relaxed);
    y.store(true, std::memory_order_release);
}

void read_y_then_x()
{
    while(!y.load(std::memory_order_acquire));
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