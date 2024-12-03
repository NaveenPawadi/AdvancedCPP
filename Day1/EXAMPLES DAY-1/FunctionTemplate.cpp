#include<iostream>
using namespace std;

//template<typename T1, typename T2, typename T3> T3 Add(T1 x, T2 y)
template<typename T1, typename T2, typename T3> T1 Add(T2 x, T3 y)
{
    return x+y;
}

//consumer code
int main()
{
    float x;
    //x = Add<float, int, float> (12.34f, 100);
     x = Add<float> (12.34f, 100);
    cout << x << endl;
    return 0;
}