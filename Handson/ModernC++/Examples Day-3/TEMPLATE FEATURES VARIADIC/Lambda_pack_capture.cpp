#include<iostream>
using namespace std;
auto print =[](auto x)
{
    cout << x <<",";
};

template<typename... PACK> void Process_byval(PACK... Args)
{
    //lambda capturing a parameter pack - C++20
    auto lm_value = [Args...]()
    {
        //process the arguments using fold expression
        (print(Args), ...);
        cout << endl;
    };

    lm_value();  //invoking lambda
}
template<typename... PACK> void Process_byref(PACK... Args)
{
    //lambda capturing a parameter pack - C++20
    auto lm_ref = [&Args...]()
    {
        //process the arguments using fold expression
        (print(Args), ...);
        cout << endl;
    };

    lm_ref();  //invoking lambda
}

int main()
{
    Process_byval(10,20,'a', 'v', 45.12f, 89.79, 500);
    Process_byref(10,20,'a', 'v', 45.12f, 89.79, 500);
    return 0;
}