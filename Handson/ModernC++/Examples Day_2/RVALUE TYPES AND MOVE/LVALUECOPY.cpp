#include<iostream>
using namespace std;

/*
    - A class that only facilitates LVALUE operation, be it copy construction
      or assignment.
*/
class CA
{
public:
    CA(){cout <<"CA default constructor..." << endl;}
    //LVALUE PAIR, supported
    CA(const CA& x) {cout <<"CA LVALUE copy constructor called" << endl;}
    CA& operator = (const CA& x) 
    {
        cout <<"CA LVALUE assignment called" << endl;
        return *this;
    }

    //RVALUE PAIR not supported
    CA(CA&& x)=delete;
    CA& operator = (CA&& x) =delete;
    
};

//****consumer code ***********
int main()
{
    CA obj1;
    CA obj2(obj1);
    obj2 = obj1;
    
    cout <<"-----------------" << endl;
    CA obj3;
    CA obj4(std::move(obj3));  //std::move converts an LVALUE type to an RVALUE type
    obj4 = std::move(obj3);
    
    return 0;
}