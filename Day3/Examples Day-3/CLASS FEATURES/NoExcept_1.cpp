#include<iostream>
#include<stdexcept>
using namespace std;

void fun1() noexcept
{
    cout <<"fun1 designed not to throw exception" << endl;
}

void fun2() noexcept(true)
{
    cout <<"fun2 designed not to throw any exception, yet does..." << endl;
    throw std::runtime_error("Exception from fun2");
}

void fun3() noexcept(false)
{
    cout <<"fun3 designed to throw exception..." << endl;
    throw std::runtime_error("Exception from fun3");
}

//consumer code
int main()
{
    fun1();  //fine
    //A call to 'fun2' is likely to throw exception though noexcept is true,
    //as such this exception can be ignored, by wrapping the function call in 'noexcept()'
    //noexcept(fun2());
    fun2();
    cout <<"--------------------------" << endl;
    //noexcept(fun3());
    return 0;
}