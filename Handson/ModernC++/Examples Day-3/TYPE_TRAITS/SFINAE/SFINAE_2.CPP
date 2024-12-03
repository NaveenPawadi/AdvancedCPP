#include<iostream>
#include<type_traits>
using namespace std;

//Instantiate the generic class for a specific type only, if the type is something different
//ignore instantiation. [Conditional instantiation]

template<typename T1, typename T2=void> class CA;

//partially specialize the above generic class for supporting integral types only.


template<typename T1> class CA <T1, typename std::enable_if<std::is_integral<T1>::value, T1>::type>
{
public:
    void fun()
    {
        cout <<"CA-integral fun called" << endl;
    }
};

//partially specialize the above generic class for supporting floating types only.

template<typename T1> class CA<T1, typename enable_if<std::is_floating_point<T1>::value,T1>::type>
{
public:
    void fun()
    {
        cout <<"CA-floating_point fun called" << endl;
    }
};

int main()
{
    CA<int> ob1;
    CA<float>ob2;
    ob1.fun();
    ob2.fun();
    return 0;
}