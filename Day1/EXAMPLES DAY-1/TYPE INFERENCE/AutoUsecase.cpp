#include<iostream>
using namespace std;

//C++11 approach
// template<typename T1, typename T2> auto Add(T1 x, T2 y) ->decltype(x+y)
// {
//     return x+y;
// }

//C++14 approach
template<typename T1, typename T2> auto Add(T1 x, T2 y)
{
    return x+y;
}

//***consumer code****
int main()
{
    float x;
    x = Add(102.34f, 100);
    cout <<"x=" << x << endl;
    cout <<"-------------" << endl;

    x = Add(100, 12.34f);
    cout <<"x =" << x << endl;
    return 0;
}