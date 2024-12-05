#include<iostream>
#include<atomic>
using namespace std;

int main()
{
    atomic<int> data1{10};

    auto expected_val{5};
    //auto expected_val{10};

    auto desired_val{5};
    cout <<"Initial value of data1 = " << data1.load() << endl;
    cout <<"expected_val ="<< expected_val << endl;
    cout <<"desired_val ="<< desired_val << endl;
    cout <<"----------------------" << endl;
    bool success = data1.compare_exchange_weak(expected_val,desired_val);
    if(success)
    {
        cout <<"!!! exchange is a success !!!" << endl;
        cout <<" data1 = desired_val; " << endl;
        cout <<"expected_val ="<< expected_val << endl;
        cout <<"data1 = " << data1.load() << endl;
    }
    else
    {
        cout <<"**** exchange failed ***" << endl;
        cout <<"  expected_val = data1; "<< endl;
        cout <<"expected_val ="<< expected_val << endl;
        cout <<"data1 = " << data1.load() << endl;
    }
    return 0;
}