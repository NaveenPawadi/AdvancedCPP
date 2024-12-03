#include<iostream>
using namespace std;

/*
    Unlike 'constexpr' specifier which is applicable to a function or
    a variable or object, 'consteval' is only applicable to functions.

    Any instance or variable defined as 'constexpr' can be initialized 
    with the return result of a function declared 'consteval'.

    Code is not generated for functions declared 'consteval', thereby
    we cannot have a pointer pointing to it, nor declare a reference
    type of the same.
*/

constexpr auto max_1( int i, int j ) 
{
    return i > j ? i : j;
}

consteval auto max_2( int i, int j ) 
{
    return i > j ? i : j;
}

int main()
{
    int a=10,b=20;
    constexpr auto result1 = max_1(30,40);
    auto result2 = max_1(a,b);
    cout <<"------------------" << endl;
    constexpr auto result3 = max_2(30,40);
    //const auto result4 = max_2(a,b);

    cout <<"result1 ="  <<  result1 << endl;
    cout <<"result2 = " << result2 << endl;
    cout <<"result3 = " << result3 << endl;
    return 0;
}