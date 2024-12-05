#include<iostream>
#include<thread>
#include<mutex>
using namespace std;

std::mutex mtx;

void Init()
{
    //static bool done = false;  //One time initialization of process
    thread_local bool done = false;  // One time initialization per thread
    std::lock_guard<mutex> lock(mtx);
    if(!done)
    {
        done=true;
        cout <<"done..." << endl;
    }
}

void Th_Func()
{
    Init();
    Init();
}

int main()
{
    std::thread th[3];
    for(int i=0; i<3; i++)
    {
        th[i] = thread{Th_Func};
    }

    for(int i=0; i<3; i++)
    {
        th[i].join();
    }

    return 0;
}