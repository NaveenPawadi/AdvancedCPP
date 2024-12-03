#include<iostream>
using namespace std;

class CA 
{
private:
    int a,b;
public:
    constexpr CA(int = 0, int = 0);
    void print() const;
};

constexpr CA::CA(int x, int y):a(x),b(y){ }
void CA::print() const {cout <<"a=" << a <<",b= " << b;}
//consumer code
int main()
{
    CA ob1(10,20);

    int a=10,b=20;
    CA ob2(a,b);

    ob1.print();
    ob2.print();
    return 0;
}