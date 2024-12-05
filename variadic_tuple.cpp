#include<iostream>
#include<tuple>
#include<vector>
using namespace std;

template<typename... PACK> void fun(PACK... Args)
{
    auto tp = make_tuple(Args...);
    
    auto print =[&](auto&... values)
    {
        ((std::cout << values << ','), ...);
    };

    std::apply(print, tp);
}

//consumer code
int main()
{
    //fun(10,30.23,'c');
    fun(50,21.56f, 'b', "tuple");
    return 0;
}