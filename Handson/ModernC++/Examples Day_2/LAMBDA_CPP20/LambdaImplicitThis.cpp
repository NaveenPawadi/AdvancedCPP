#include<iostream>
using namespace std;

/*
    Implicit capture of 'this' with '=' in the capture clause is now
    deprecated in C++20 standards onwards.
*/

//C++11,14,17 class

class CA
{
private:
    int a=10,b=20;  //data members
public:
    void fun()
    {
        int x=100,y=200;  //functions local variables
        //A local lambda defined inside the member function tries 
        //capturing it's outer-scope element(s).
        auto lm = [=]
        {
            //captures 'x', 'y' and also 'this', thereby all 4 elements are accessible
            cout << a << "," << b << endl;
            cout << x << "," << y << endl;
        };

        lm();
    }
};

//consumer code
int main()
{
    CA ob1;
    ob1.fun();
    return 0;
}