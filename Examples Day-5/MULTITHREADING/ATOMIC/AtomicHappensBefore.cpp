#include<iostream>
#include<thread>
#include<vector>
#include<atomic>
using namespace std;
/*
    Write HAPPENS_BEFORE Read.
*/
std::vector<int> v1;
std::atomic<bool> data_ready = false;

void Read()
{
    while(!data_ready.load())
    {
        std::this_thread::sleep_for(1ms);  
    }
    cout <<"data available..." << endl;
    for(auto x: v1)
    {
        cout << x <<",";
    }
    cout <<endl;
}

void Write(int x)
{
    v1.push_back(x);
    data_ready = true;
}

int main()
{
    thread th1(Read);
    thread th2(Write,300);

    thread th3(Write, 100);
    thread th4(Write, 200);

    th1.join();
    th2.join();
    th3.join();
    th4.join();

    return 0;
}