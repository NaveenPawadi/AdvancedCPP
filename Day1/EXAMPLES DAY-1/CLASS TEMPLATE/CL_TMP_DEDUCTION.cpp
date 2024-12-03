#include <iostream>
using namespace std;

//An example class template typename deduction.

template <typename T = double>
class CA
{
private:
    T a, b;

public:
    CA() : a(0), b(0) {}
    CA(T x) : a(x), b(x) {}
    ~CA() {}
    void print() const
    {
        cout << "CA-print, data-type of a:" << typeid(a).name() << ", its value:" << a << endl;
        cout << "CA-print, data-type of b:" << typeid(b).name() << ", its value:" << b << endl;
    }
};

//C++ 98,03,11,14 approach

void fun1()
{
    /*
    To state the type, what is 'T' at the time of object definition by the class
    consumer is compulsory, if it is any other type other than default type.
    */
    CA<int> obj1(10);
    CA<float> obj2(43.12f);
    /*
        <> empty brace mandatory though type not mentioned. 
        Compiler would assume default type i.e. 'double'
    */
    CA<> obj3;    
    cout<<"-------------------------" << endl;
    obj1.print(); 
    cout<<"-------------------------" << endl;
    obj2.print();
    cout<<"-------------------------" << endl;
    obj3.print();
}

//C++17 - Class template Args deduction.
void fun2()
{
    
    CA obj1{10};      //The compiler would implicitly presume typename 'T' as 'int'
    CA obj2{43.12f};  //The compiler would implicitly presume typename 'T' as 'float'
    /*
        no '<>' empty brace nor type nor parameter mentioned. 
        Compiler would assume default type i.e. 'double'
    */
    CA obj3;    
    cout<<"-------------------------" << endl;
    obj1.print(); 
    cout<<"-------------------------" << endl;
    obj2.print();
    cout<<"-------------------------" << endl;
    obj3.print();
}
int main()
{
    //fun1();
    fun2();
    return 0;
}