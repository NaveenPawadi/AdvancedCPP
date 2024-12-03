#include<iostream>
#include<type_traits>
using namespace std;

template<typename T> struct is_char
{
    static const bool value = false;
};

template<> struct is_char<char>
{
    static const bool value = true;
};

template<typename T> void fun(T x)
{
    static_assert(is_char<T>::value, "Parameter must be char");
    cout <<"fun called, x=" << x << endl;
}

int main()
{
    fun('a');
    //fun(100);
    return 0;
}