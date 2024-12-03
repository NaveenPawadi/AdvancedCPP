#include<iostream>
#include<functional>
using namespace std;
using namespace std::placeholders;

void Process(int a, int b, int c)
{
    cout <<"Process called, a =" << a <<",b=" << b <<",c =" << c << endl;
}

//consumer code
int main()
{
    auto handle1 = std::bind(Process, _1, 200,300);
    auto handle2 = std::bind(Process, 100, _1, 300);
    auto handle3 = std::bind(Process, _1, _2, 300);
    auto handle4 = std::bind(Process, _1, 300, _2);
    handle1(10);
    handle2(10);
    handle3(5,6);
    handle4(5,6);
    
    return 0;
}