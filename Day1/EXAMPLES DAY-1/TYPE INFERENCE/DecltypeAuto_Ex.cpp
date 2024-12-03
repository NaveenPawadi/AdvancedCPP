
#include <iostream>
using namespace std;

class CA
{
public:
   void fun()
    {
        cout <<"CA::fun1() non-const called" << endl;
    }
    
    void fun() const
    {
        cout <<"CA::fun1() const called" << endl;
    }
};

auto Business1()
{
    CA obj1;
    //...
    return obj1;
}

decltype(auto) Business2() //auto Business2()
{
     const CA obj1;
     //..
     return obj1;
}


int main(int argc, char** argv) 
{
    //(Business1()).fun();
    //(Business2()).fun();

    auto x =Business1();
    decltype(auto) y = Business2();  //auto y = Business2();
    x.fun();
    y.fun();
    return 0;
}

