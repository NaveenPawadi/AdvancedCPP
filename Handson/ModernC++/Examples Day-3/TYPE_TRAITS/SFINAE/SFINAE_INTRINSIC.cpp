#include <iostream>
using namespace std;

struct CA
{
    using type = int;
};

template<typename T> void print(T x)
{
    cout <<"print(T x) called" << endl;
}

template<typename T> void print(typename T::type)
{
    cout <<"print(typename T::type ) called" << endl;
}

int main() 
{
    print<int>(50);
    print(50);
    print<CA>(100);
    
    return 0;
}

