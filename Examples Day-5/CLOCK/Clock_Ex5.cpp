#include<iostream>
#include<chrono>
using namespace std;

//gps-clock - Global Positioning System (GPS) time.

void Busy_func()
{
    for(int i=1;i<=100000;i++)
    {
        //busy work
    }
}

int main()
{
    chrono::gps_time start = chrono::gps_clock::now();
    Busy_func();
    chrono::gps_time end = chrono::gps_clock::now();
    chrono::duration<double> diff = end - start;
    cout <<"start time --> " << start << endl;
    cout <<"end time --> " << end << endl;
    cout <<"Time taken to complete Business..." << diff << endl;
    return 0;
}

