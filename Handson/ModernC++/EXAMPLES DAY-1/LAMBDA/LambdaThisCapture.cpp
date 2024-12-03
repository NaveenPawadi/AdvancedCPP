#include<iostream>
using namespace std;

// capture by '*this' in C++17 is a replace for init-capture in C++14 
/*
  auto lm = [ob =*this](){....};  //C++14
  auto lm = [*this](){....};  //now in C++17 onwards...
*/

class CA
{
private:
    int a,b;
public:
    CA(int x=0,int y=0):a(x),b(y){}
    void fun1()
    {
        auto lm =[this](){cout <<"Inside fun1-lambda, a:" << a <<"b:" << b << endl;};
        lm();
        this->a=a+100;
        this->b=b+100;
        lm();
    }
    void fun2()
    {
        auto lm =[*this](){cout <<"Inside fun1-lambda, a:" << a <<"b:" << b << endl;};
        lm();
        this->a=a+100;
        this->b=b+100;
        lm();
    }
};

int main()
{
    CA obj1(10,20);
    obj1.fun2();
    return 0;
}