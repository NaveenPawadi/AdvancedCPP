#include<iostream>
#include<functional>
using namespace std;

template <typename FUNC> class Callable
{
private:
    FUNC* fp;

public:
    Callable(FUNC* ff)
        : fp(ff)
    {
    }
    // VAR. ARGS FUNCTOR
    template <typename... pack> decltype(auto) operator()(pack&&... DATA)
    {
        //TRADITIONAL way
        auto fn = bind(fp, (DATA)...);
        return fn();
        
        //MODERN C++17 approach
        //return invoke(fp, forward<pack>(DATA)...);
    }
};

//*********** consumer code***************

auto lm1 =[](int x, int y)
{
    cout <<"lambda, lm1 called" << endl;
    return x+y;
};

int fun(int x, int y)
{
    cout <<"fun called" << endl;
    return x+y;
};

void fun2(){cout <<"fun2 called" << endl; }

int main()
{
    //Callable<decltype(fun)> ob1(lm1);
   // ob1(10,20);
    cout <<"-------------" << endl;
    Callable<decltype(fun2)> ob2(fun2);
    ob2();
    return 0;
}