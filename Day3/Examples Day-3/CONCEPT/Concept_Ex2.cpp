#include<iostream>
using namespace std;

//dis-able arithmetic operation on non-numeric types by using C++20 concept semantic

//define the CONCEPT that emphasizes constraint

template<typename T> concept NUMERIC = requires(T val1, T val2)
{
    {val1 + val2};
};

//define the generic function that uses the above concept
template<NUMERIC T> T Sum(T x, T y)
{
    return x+y;
}

//***consumer code ****

int main()
{
    cout << Sum(10,20)  << endl;
    cout << Sum("a", "b");
    return 0;
}