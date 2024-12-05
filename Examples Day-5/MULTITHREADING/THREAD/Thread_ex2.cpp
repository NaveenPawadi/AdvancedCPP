#include<iostream>
#include<thread>
using namespace std;

//global functions

void fun1()
{
    cout <<"fun1() called, id =" << this_thread::get_id() << endl;
}
/*
    Every thread must be joined if not detached.
*/
int main()
{
    cout <<"parent thread main... id = " << this_thread::get_id() << endl;
    
    thread th1(fun1);
    th1.detach();
    this_thread::sleep_for(chrono::milliseconds(300));

    if(th1.joinable())
    {
        cout <<"thread joined..." << endl;
        th1.join();
    }
        
    
    return 0;
}