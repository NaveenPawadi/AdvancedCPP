#include<iostream>
#include<atomic>
#include<thread>
#include<mutex>
#include<boost/asio.hpp>
using namespace std;

std::mutex mtx;

void process_val(int data)
{
    std::lock_guard<mutex> guard(mtx);
    cout <<" Thread Processed data :" 
         << data <<", thread-id ->" 
         << std::this_thread::get_id() <<endl;
}

int main()
{
    boost::asio::thread_pool thread_pool(4);
    for(int i=1;i<=100;i++)
    {
        boost::asio::post(thread_pool, [i](){process_val(i);});
    }
    thread_pool.join();
    return 0;
}