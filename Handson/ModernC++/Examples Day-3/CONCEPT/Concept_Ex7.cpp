#include<iostream>
using namespace std;

namespace custom_concept
{
    namespace inner
    {
        template<typename T> concept pointer = std::is_pointer_v<T>;
    }

    template<typename T> concept returns_address = requires (T x){ {x()} ->inner::pointer;};
    
}

int fun1(){cout <<"fun1 called " << endl; return 100; }

//global variable
int a=200;
int* fun2(){cout <<"fun2 called " << endl; return &a; }

void Process(custom_concept::returns_address auto callable)
{
    cout << *(callable()) << endl;
}

//consumer code
int main()
{
    //Process(fun1);
    Process(fun2);
    return 0;
}