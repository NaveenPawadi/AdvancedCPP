#include<iostream>
using namespace std;

template<typename T> struct is_VOID
{
    static const bool value = false;
};

template<> struct is_VOID<void>
{
    static const bool value = true;
};

int main()
{
    cout << boolalpha << is_VOID<int>::value << endl;
    cout << boolalpha << is_VOID<void>::value << endl;
    return 0;
}