#include<iostream>
#include<atomic>
#include<thread>
using namespace std;

std::atomic<int> Data{5};
std::atomic<bool> start{false};

int main()
{
    int arr1[10], arr2[10];

    auto lm1 =[&arr1]()
    {
        while(!start.load());
        
        for(int i=0;i<10;i++)
        {
            Data.store(3);
            //this_thread::sleep_for(1s);
            arr1[i] = Data.load();
        }

        for(int j=0;j<10;j++)
        {
            cout <<"arr1["<< j <<"] =" << arr1[j] <<endl;
        }
    };

    auto lm2 =[&arr2]()
    {
        while(!start.load());
        
        for(int i=0;i<10;i++)
        {
            Data.store(6);
            //this_thread::sleep_for(1s);
            arr2[i]=Data.load();
        }
        for(int j=0;j<10;j++)
        {
            cout <<"arr2["<< j <<"] =" << arr2[j] <<endl;
        }
    };

    thread t1(lm1);
    thread t2(lm2);

    start.store(true);

    t1.join();
    t2.join();

    return 0;
}