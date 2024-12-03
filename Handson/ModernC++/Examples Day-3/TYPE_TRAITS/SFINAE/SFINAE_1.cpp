#include<iostream>
#include<typeinfo>
#include<type_traits>
using namespace std;


//A generic function 'print' expected to work for any types, integral, enum or class type

template<typename T> void print(T x, typename enable_if<is_integral<T>::value,T>::type=0)
{
    cout <<"print-is integral called"  << endl;
}

template<typename T> void print(T x, typename enable_if<is_enum<T>::value,T>::type* =0)
{
    cout <<"print-is enum called" << endl;
}


//A print for class types only
template<typename T> void print(T x, typename enable_if<is_class<T>::value,T>::type* =0)
{
    cout <<"print, class version called" << endl;
}



enum COLOR {RED, BLUE, GREEN};

class CA
{
    
};
int main()
{
    int x=100;
    COLOR c=RED;
    
    print(x);
    print(c);
    
    CA obj1;
    print(obj1);
}

