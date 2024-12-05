#include<iostream>
#include<chrono>
using namespace std;
using namespace std::chrono;

//C++11 - System clock and C++20 - utc clock [conversion]
int main()
{
    sys_time systime = chrono::system_clock::now();

    utc_time utctime = chrono::utc_clock::from_sys(systime);

    cout << "system-clock time :- " << systime << endl;
    cout << "utc-clock time :- " << utctime << endl;
    return 0;
}

