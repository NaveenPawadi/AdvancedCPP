#include<iostream>
using namespace std;

class CA
{
private:
    int a,b;
public:
    CA():a(0),b(0){cout <<"CA default constructor" << endl;}  
    CA(int x):a(x),b(x){cout <<"CA one arg constructor" << endl;}    
    CA(int x, int y):a(x),b(y){cout <<"CA two arg. constructor" << endl;}    
    //...    
};


//***class consumer ****
int main()
{
    //Traditional approach - every object will only call def. constructor.
    //CA* p = new(nothrow) CA[5];
    //....
    //Modern approach, using brace initialization syntax we can
    //provide each object part of the array with parameter(s).

    CA* p = new(nothrow) CA[5]{{10},{},{100,200},{300},{}};
    //....
    delete [] p;
    return 0;
}