#include<iostream>
#include<vector>
#include<array>
using namespace std;

template<auto... values> class CB
{
private:
    inline static vector v={values...};
    
public:
    auto begin(){return v.begin();}
    auto end(){return v.end();}
};

template<auto value, auto... values> class CC
{
private:
    inline static auto field = value;
    typedef decltype(field) type;
    
    std::array<type, sizeof...(values)+1> arr = {value, values...};
public:
    auto begin(){return arr.begin();}
    auto end(){return arr.end();}
};

//consumer code
int main()
{
    CB<10,20,30,40,50> ob1;
    CB<'a','b','c','d','e'> ob2;

    for(auto x:ob1)
    {
        cout << x <<"," ;
    }
    cout << endl;

    for(auto x:ob2)
    {
        cout << x <<"," ;
    }
    cout << endl;
    cout <<"----------------------------" << endl;
    CC<100,200,300> ob3;
    CC<'x', 'y', 'z'> ob4;
    for(auto x:ob3)
    {
        cout << x <<"," ;
    }
    cout << endl;

    for(auto x:ob4)
    {
        cout << x <<"," ;
    }
    return 0;
}