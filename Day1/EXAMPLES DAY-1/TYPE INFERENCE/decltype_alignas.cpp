#include<iostream>
using namespace std;

struct CA 
{
    alignas(32) int a[10];
};

int main()
{
    cout <<"size of CA " << sizeof(CA) << " bytes " << endl;
    CA ob1;
    decltype(ob1) ob2;
    cout <<"size of CA " << sizeof(ob2) << " bytes " << endl;
    return 0;
}