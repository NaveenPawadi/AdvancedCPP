#include<iostream>
#include<chrono>
using namespace std;

//utc-clock - Co-ordinated universal time, measures even seconds

void Busy_func()
{
    for(int i=1;i<=100000;i++)
    {
        //busy work
    }
}

int main()
{
    chrono::time_point start = chrono::utc_clock::now();
    Busy_func();
    chrono::time_point end = chrono::utc_clock::now();
    chrono::duration<double> diff = end - start;
    cout <<"Time taken to complete Business..." << diff << endl;
    return 0;
}