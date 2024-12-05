#include<iostream>
#include<atomic>
#include<thread>
using namespace std;

std::atomic<int> Data{10};

int main()   //parent thread
{
    auto lm =[]()
    {
        cout << "Before Exchange in child thread - Data.load() =" << Data.load()<< endl;
        int value=Data.exchange(4);
    };
 
    thread t1(lm);  //child thread
    //A load and exchange in the parent thread...
    cout << "Before Exchange in parent thread - Data.load() =" << Data.load()<< endl;
    Data.exchange(200);
    cout << "After Exchange in parent thread - Data.load() =" << Data.load()<< endl;
    cout << "After Exchange in parent thread - Data.load() =" << Data.load()<< endl;
    cout << "After Exchange in parent thread - Data.load() =" << Data.load()<< endl;
    cout << "After Exchange in parent thread - Data.load() =" << Data.load()<< endl;

    t1.join();
    return 0;
}