#include<iostream>
using namespace std;
/*
    CRTP - Curiously Recurring Template Pattern.
    Helps in overcoming the overhead costs involved with run-time polymorphism
*/

template<typename T> class Base
{
    friend T;
private:
    Base(){ }
    T& GetType(){ return static_cast<T&>(*this);}  
public:
    void fun() { GetType().fun();}    
};

class Derived1:public Base<Derived1>
{
public:
    void fun() {cout << "Derived1 fun()" << endl;}
};

class Derived2:public Base<Derived2>
{
public:
    void fun() {cout << "Derived2 fun()" << endl;}
};

//consumer code
template<typename T> void Process1(Base<T>& x)
{
    x.fun();
}

template<typename T> void Process2(Base<T>* x)
{
    x->fun();
}

int main()
{
    Derived1 ob1;
    Derived2 ob2;
    Process1(ob1);
    Process1(ob2);
    cout<<"-----------------------------" << endl;
    Derived1* ptr1 = new(nothrow) Derived1;
    Process2(ptr1);
    delete ptr1;
    return 0;
}