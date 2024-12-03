#include<iostream>
#include<string>
#include<type_traits>
using namespace std;

template<typename T> struct Is_Streamable
{
    static const bool value=false;
};

template<>struct Is_Streamable<char> {  static const bool value=true;};
template<>struct Is_Streamable<int> {  static const bool value=true;};
template<>struct Is_Streamable<float> {  static const bool value=true;};
template<>struct Is_Streamable<double> {  static const bool value=true;};
template<>struct Is_Streamable<std::string> {  static const bool value=true;};

template<typename T> void Print(T x, typename enable_if<Is_Streamable<T>::value,T>::type=0)
{
    cout <<"Enabled for Streamble type, data type of x=" << typeid(T).name() << endl;
    cout <<"its value =" << x << endl;
}
//---consumer code----------
class CA{};
int main()
{
    Print('a');
    Print(100);
    Print(34.12f);
    Print(67.82);
    //CA ob1;
    //Print(ob1);
    return 0;
}