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
    void print()
    {
        ptr->print();
    }
};

void fun()
{
     MemoryManager ob1(10,20);
    throw 10;
     ob1.print();
}

//consumer code
int main()
{
   try
   {
    fun();
   }
   catch(const int e)
   {
    cout <<"Exception from fun " << endl;
   }
   
    
    return 0;
}