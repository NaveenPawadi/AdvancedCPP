#include<iostream>
#include<thread>
#include<atomic>
#include<cassert>
using namespace std;
/*
    - Though 'std::memory_order_acquire and release' is one step ahead of 
      'std::memory_order_seq', but still there is no order between threads, 
      but does introduce some synchronication between threads

    - Under this model, loads are 'acquire' and stores are 'release'
    - Synchronization between pairs is between 'acquire' operation and 'release' operation
*/
std::atomic<bool> x_flag, y_flag;
std::atomic<int> z;

void write_x_flag()
{
    x_flag.store(true, std::memory_order_release);
}

void write_y_flag()
{
    y_flag.store(true, std::memory_order_release);
}

void read_xflag_then_yflag()
{
    while(!x_flag.load(std::memory_order_acquire));

    if(y_flag.load(std::memory_order_acquire))
        ++z;
}

void read_yflag_then_xflag()
{
    while(!y_flag.load(std::memory_order_acquire));
    
    if(x_flag.load(std::memory_order_acquire))
        ++z;
}

int main()
{
    x_flag = false;
    y_flag = false;
    z=0;

    thread th1(write_x_flag);
    thread th2(write_y_flag);

    thread th3(read_xflag_then_yflag);
    thread th4(read_yflag_then_xflag);

    th1.join();
    th2.join();
    th3.join();
    th4.join();

    assert(z.load() != 0);
    cout <<"z =" << z.load() << endl;
    return 0;
}