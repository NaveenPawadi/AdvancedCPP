#include<iostream>
#include<atomic>
#include<thread>
#include<cassert>
using namespace std;

atomic<bool> x{false},y{false};
atomic<int> z;

void write_x_then_y()
{
    x.store(true, std::memory_order_relaxed);
    y.store(true, std::memory_order_relaxed);
}

void read_y_then_x()
{
    while(!y.load(std::memory_order_relaxed));

    if(x.load(std::memory_order_relaxed))
        ++z;
}

int main()
{
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