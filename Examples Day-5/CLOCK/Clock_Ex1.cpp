#include<iostream>
#include<chrono>
using namespace std;
using namespace std::chrono;

//C++11 - System clock

int main()
{
    auto systime = chrono::system_clock::now();
    
    time_t tt = chrono::system_clock::to_time_t(systime);

    cout << ctime(&tt) << endl;
    //c++20 only
    cout << systime << endl; 
    cout << std::format("{0:%Ec}", systime) << endl;
    cout << std::format("{0:%p},{0:%T}, {0:%D}", systime) << endl;
    return 0;
}