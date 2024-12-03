#include<iostream>
#include<concepts>
using namespace std;

//template<typename T> requires std::invocable<T> void Fun(T x)
//template<std::invocable T> void Fun(T x)
void Fun(std::invocable auto x)
{
    //call the function
    x();
}

template<typename T> requires std::integral<T> void Fun(T x)
{
    cout <<"x =" << x << endl;
}

//consumer code 
void fun1(){cout <<"fun1 called" << endl;}
int main()
{
    Fun(100);
    Fun(fun1);

    auto lm =[](){cout <<"lambda called..." << endl;};
    Fun(lm);
    return 0;
}