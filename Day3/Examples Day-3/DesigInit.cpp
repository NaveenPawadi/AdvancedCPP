#include<iostream>
using namespace std;

/*
    Designated initializers - Any member fields that are not explicitly
    listed in the designated initalizer list are default initialized
*/

struct CA
{
    int x;
    int y;
    int z;
};

int main()
{
    CA ob1 {.x=100, .y=300};   //Designated initializer
    cout <<ob1.x << "," << ob1.y <<"," << ob1.z << endl;
    return 0;
}