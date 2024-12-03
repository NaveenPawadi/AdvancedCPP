#include<iostream>
using namespace std;

template<typename T> void Fun(T& x)
{
    cout <<"Fun-LVALUE called, x =" << x << endl;
}

template<typename T> void Fun(T&& x)
{
    cout <<"Fun-RVALUE called,  =" << x << endl;
}

auto pft_forward1 =[](auto&& x)
{
    Fun(std::forward<decltype(x)>(x));
};

//C++20 Lambda with template parameter
auto pft_forward2 =[]<typename T>(T&& x)
{
    Fun(std::forward<T>(x));
};
//consumer code
int main()
{
    auto x = 100;
    auto y = 78.21;
    pft_forward1(x);
    pft_forward1(y);
    //----------------------
    pft_forward1(200);
    pft_forward1(98.12);
    // cout <<"***********************" <<endl;
    // pft_forward2(x);
    // pft_forward2(y);
    // //----------------------
    // pft_forward2(200);
    // pft_forward2(98.12);

    return 0;
}