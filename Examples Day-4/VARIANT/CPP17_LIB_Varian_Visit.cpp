#include<iostream>
#include<variant>
#include<vector>
using namespace std;

//Un-Related classes, ideally expected to have same behaviours in their classes

class c_One
{
public:
    c_One(){cout <<"c_One constructor called" << endl;}
    void fun() const {cout <<"c_One fun() called" << endl;}
    ~c_One(){cout <<"c_One destructor called" << endl;}
    
};
class c_Two
{
public:
    c_Two(){cout <<"c_Two constructor called" << endl;}
    void fun() const {cout <<"c_Two fun() called" << endl;}
    ~c_Two(){cout <<"c_Two destructor called" << endl;}
};
//....

//A callable entity
class Callable
{
public:
    void operator()(const c_One& x)
    {
        x.fun();
    }
    void operator()(const c_Two& x)
    {
        x.fun();
    }
};

int main()
{
    vector<variant<c_One, c_Two>> vect ={move(c_One()), move(c_Two())};
    for(auto &x: vect)
    {
        visit(Callable(), x);
    }
    
    return 0;
}
