#include<iostream>
using namespace std;

template<typename T> T pi = T(3.14159265359);  //A template variable

//A generic function that calculates force
template<typename T> T Area_of_Circle(T radius)
{
    cout <<typeid(T).name() <<" " << pi<T> << endl;
    return pi<T> * radius * radius; // will get instantiated for type 'T'
}

//consumer code
int main()
{
    auto area1 = Area_of_Circle<int>(10);
    auto area2 = Area_of_Circle<float>(5.0f);
    auto area3 = Area_of_Circle<double>(10.0);

    cout <<"Area_of_Circle<int>(10) -> " << area1 << endl;
    cout <<"Area_of_Circle<float>(5.0f) -> " << area2 << endl;
    cout <<"Area_of_Circle<double>(10.0) -> " << area3 << endl;

    return 0;
}