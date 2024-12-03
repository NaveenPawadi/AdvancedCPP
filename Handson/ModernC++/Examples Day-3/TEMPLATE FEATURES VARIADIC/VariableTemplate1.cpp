#include<iostream>
using namespace std;

template<typename T> T gravity = T(9.80665);  //A template variable

//A generic function that calculates force
template<typename T> T force(T mass)
{
    cout <<typeid(T).name() <<" " << gravity<T> << endl;
    return mass * gravity<T>; // will get instantiated for type 'T'
}

//consumer code
int main()
{
    auto force1 = force<int>(10);
    auto force2 = force<float>(5.0f);
    auto force3 = force<double>(10.0);

    cout <<"force<int>(10) -> " << force1 << endl;
    cout <<"force<float>(5.0f) -> " << force2 << endl;
    cout <<"force<double>(10.0) -> " << force3 << endl;

    return 0;
}