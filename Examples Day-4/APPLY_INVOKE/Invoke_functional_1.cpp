#include<iostream>
#include<functional>
using namespace std;

//replace 'mem_fun' with 'invoke' as it is likely to be deprecated in C++20

class CA
{
public:
    CA(){cout <<"CA constructor" << endl;}
    void fun(int x){cout <<"CA-fun(int x) called" << endl;}
    void operator()(int x){cout <<"CA-operator()(int) called" << endl;}
};

//global/free function

void global_fun(float x){cout <<"global_fun(float x) called" << endl;}

int main()
{
    //Invoke the global function
    std::invoke(global_fun, 45.32f);

    //Invoke the class member function 'CA::fun'
    std::invoke(CA::fun, CA(), 100);

    //Invoke the functor of CA class
    std::invoke(CA(),300);
    return 0;
}