#include<iostream>
#include<chrono>
using namespace std;

//tai-clock - International Atomic Time, its offset is 10 seconds of UTC

void Busy_func()
{
    for(int i=1;i<=100000;i++)
    {
        //busy work
    }
}

int main()
{
    chrono::tai_time start = chrono::tai_clock::now();
    Busy_func();
    chrono::tai_time end = chrono::tai_clock::now();
    chrono::duration<double> diff = end - start;
    cout <<"start time --> " << start << endl;
    cout <<"end time --> " << end << endl;
    cout <<"Time taken to complete Business..." << diff << endl;
    return 0;
}