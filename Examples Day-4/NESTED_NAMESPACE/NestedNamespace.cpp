#include<iostream>
using namespace std;

//C++98,11,14 approach for nested namespace declarations.

// namespace One
// {
//     namespace Two
//     {
//         class CA{public: void fun(){cout <<"CA fun called" << endl;}};

//         namespace Three
//         {
//             void fun1(){ cout <<"fun1 from namespace Three" << endl;}
//         }
//     }
// }

//C++17 approach for nested namespaces
namespace One::Two { class CA{public: void fun(){cout <<"CA fun called" << endl;}};}
namespace One::Two::Three{void fun1(){ cout <<"fun1 from namespace Three" << endl;} }

//consumer code
int main()
{
    One::Two::CA ob1;
    ob1.fun();
    One::Two::Three::fun1();
    return 0;
}