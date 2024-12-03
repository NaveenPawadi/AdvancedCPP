#include<iostream>
using namespace std;
/*
    'const' qualifier and 'constexpr' specifier
*/

int fun1()
{
    int a;
    //..
    return a;
}

constexpr int fun2()
{
    int a=100;
    //..
    return a;
}

constexpr int fun3(int x, int y)
{
    return x*y;
}

constexpr int fun4()
{
    return fun1();   //error
}

int main()
{
    const int a=100;           //compile-time initialization - ok
    const int result1 = fun1();  //run-time initialization - ok
    
    //Where as a 'constexpr' element must and should be initialized during compile-time
    constexpr int b=200;            // compile-time initialization - ok
    constexpr int result2 = fun1();  //error, not a constant expression

    constexpr int result3 = fun2();   //ok, a constant expression [ int result3 = 100;]
    
    constexpr int result4 = fun3(30,40); //ok, a constant expression [ int result4 = 1200; ]

    int arr[fun3(10,20)];  //ok, a constant expression

    auto c=10,d=20;
    int result5 = fun3(c,d);

    constexpr int result6 = fun3(c,d);  //error

    constexpr auto result7 = fun4();
    return 0;
}