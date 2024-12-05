#include<iostream>
using namespace std;

int main()
{
    //int a=10,b=20;
    //int a=20,b=10;
    int a=10,b=10;
    auto result1 = a<=> b;
    if(result1 > 0)
    {
        cout << a <<" is greater than "<< b << endl;
    }
    if(result1 < 0)
    {
        cout << a <<" is lesser than "<< b << endl;
    }
    if(result1 == 0)
    {
        cout << a <<" is equal to "<< b << endl;
    }
    return 0;
}