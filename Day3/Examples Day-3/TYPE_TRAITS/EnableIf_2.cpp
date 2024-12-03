#include<iostream>
#include<type_traits>
using namespace std;

template<typename T> struct Is_Numeric
{
    static const bool value=false;
};

template<>struct Is_Numeric<int> {  static const bool value=true;};
template<>struct Is_Numeric<float> {  static const bool value=true;};
template<>struct Is_Numeric<double> {  static const bool value=true;};

template<typename T> void Print(T x, typename enable_if<Is_Numeric<T>::value,T>::type=0)
{
    cout <<"Enabled for Numeric type, data type of x=" << typeid(T).name() << endl;
    cout <<"its value =" << x << endl;
}

void Print(char x)
{
    cout <<"Specialized for char, called" << endl;
}
int main()
{
    Print('a');
    Print(100);
    Print(34.12f);
    Print(67.82);
    return 0;
}