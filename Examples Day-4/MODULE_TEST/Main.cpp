#include<iostream>
using namespace std;

import Test_module;



int main()
{
    int result1, result2;
    result1 = Add(10,20);
    result2 = Diff(100,40);
    cout <<"result1 =" << result1 << ", result2 =" << result2 << endl;

    return 0;
}