#include<iostream>
using namespace std;

class Data
{
private:
    int a,b;
public:
    Data(int x=0, int y=0):a(x),b(y){cout <<"Data constructor" << endl;}
    ~Data(){cout <<"Data destructor" << endl;}
    void print() const { cout <<"a =" << a <<",b=" << b << endl;}
    void fun1(){cout <<"Data fun1 called" << endl;}
    void fun2(){cout <<"Data fun2 called" << endl;}
};

class MemoryManager
{
private:
    Data* ptr;   //PIMPL - pointer implementation model
public:
//RAII - Resource acquisition is initialization
    MemoryManager(int x=0, int y=0)
    {
        ptr = new(nothrow) Data(x,y);
    }
    //RULE OF 3
    //custom copy constructor and
    //custom assignment function to be defined
    ~MemoryManager()
    {
        delete ptr;
    }
    Data *operator->()
    {
        return ptr;
    }
    Data *operator&()
    {
        return ptr;
    }
    Data& operator*()
    {
        return *ptr;
    }
};

void fun1(Data* pt)
{
    pt->fun1();
}

void fun2(Data& pt)
{
    pt.fun2();
}


//consumer code
int main()
{
    MemoryManager ob1(10, 20);
    ob1->fun1();
    fun1(&ob1);     // fun1(ob1.operator &())
    fun2(*ob1);     // fun2(ob1.operator*())

    return 0;
}