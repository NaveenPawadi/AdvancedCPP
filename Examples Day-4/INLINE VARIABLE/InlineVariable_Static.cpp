#include<iostream>
using namespace std;

//An example on inline variables

class CA
{
private:
    int a;
    static inline int b = { 0 };

public:
    CA(int x = 0)
        : a(x)
    {
        b = b + 1;
    }
    void print() const
    {
        cout << "a:" << a << ",b:" << b << endl;
    }
    static void count()
    {
        cout << "b:" << b << endl;
    }
};

int main()
{
    CA ob1(100), ob2(200), ob3(300);
    CA::count();
    return 0;
}