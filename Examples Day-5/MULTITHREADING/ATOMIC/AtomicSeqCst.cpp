#include<iostream>
#include<thread>
#include<atomic>
#include<cassert>
using namespace std;
/*
    - Though 'std::memory_order_seq_cst' is the most straight forward and intutive, but
      it is also the most expensive one, as it requires a global synchronization between
      threads. On a multi-processor systems this would require extensive time consuming
      communication between threads.
*/
std::atomic<bool> x_flag, y_flag;
std::atomic<int> z;

void write_x_flag()
{
    x_flag.store(true, std::memory_order_seq_cst);
}

void write_y_flag()
{
    y_flag.store(true, std::memory_order_seq_cst);
}

void read_xflag_then_yflag()
{
    while(!x_flag.load(std::memory_order_seq_cst));
    if(y_flag.load(std::memory_order_seq_cst))
        ++z;
}

void read_yflag_then_xflag()
{
    while(!y_flag.load(std::memory_order_seq_cst));
    if(x_flag.load(std::memory_order_seq_cst))
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