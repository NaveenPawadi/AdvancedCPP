#include<iostream>
#include<thread>
using namespace std;

//global functions

void fun1()
{
    cout <<"fun1() called, id =" << this_thread::get_id() << endl;
}

void fun2(int x)
{cout <<"fun2(int x) called, x=" << x <<", id = "<< this_thread::get_id() << endl;}

void fun3(float &x)
{
    cout <<"fun3(float x) called, id =" << this_thread::get_id() << endl;  
    x=x+x;
    cout <<"x = " << x << endl;
}

//class 
class CA
{
private:
    int a,b;
public:
    //non-static methods
    void input(int x, int y)
    {
        cout <<"CA-input, id =" << this_thread::get_id() << endl;
        cout <<"enter 2 nos..." << endl;
    }

    void print()
    {
        cout <<"CA-print, id =" << this_thread::get_id() << endl;
        cout <<"a = " << a <<",b =" << b << endl;
    }

    //static member function
    static void fun(){ cout <<"CA static fun called, id =" << this_thread::get_id() << endl;}

    void operator()(int x)
    {
        cout <<"CA-operator(), id =" << this_thread::get_id() << endl;
        cout <<"CA operator()(int x) called, x=" << x<< endl;
    }
};

int main()
{
    auto lm =[](){cout <<"lambda called" << endl;};

    cout <<"parent thread main ...id = " << this_thread::get_id() << endl;

    thread th1(&fun1);
    th1.join();

    thread th2(&fun2, 100);
    th2.join();

    float x = 56.12f;
    thread th3(&fun3, std::ref(x));
    th3.join();

    CA ob1;
    thread th4(&CA::input, ob1, 20,30);
    th4.join();

    thread th5(&CA::print, ob1);
    th5.join();

    thread th6(&CA::fun);
    th6.join();

    thread th7(ob1, 10);            //thread th7(CA::operator(), ob1, 10);
    th7.join();

    thread th8(lm);
    th8.join();

    cout <<"parent thread completes..." << endl;
    return 0;
}
