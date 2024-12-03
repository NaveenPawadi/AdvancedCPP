#include<iostream>
using namespace std;

//Overcome the Issues faced by the traditional C++ programmers with regard 
//to generic programming.

template<typename T1,typename T2> void Wrapper(T1&& x, T2&& y)
{
    cout <<"Initially..." << endl;
    cout << "x = " << x <<endl;
    cout << "y = " << y << endl;
   
    cout <<"----------------" << endl;
    x=x+100;
    y=y+100;
    cout <<"After modification inside Wrapper..." << endl;
    cout << "x = " << x <<endl;
    cout << "y = " << y << endl;
}

//***consumer code *********
int main()
{
    int a=10;
    float b=20.23f;
    Wrapper(a,b);         // (int&, float&) 
    cout <<"in main(), a = " << a <<",b=" << b << endl; 
    Wrapper(100,56.21f);  // (int&& , float&&)
    
    Wrapper(a, 56.21f);   // (int&, float&&)
    cout <<"in main(),a = " << a << endl; 
    Wrapper(100, b);      // (int&& , float&)
    cout <<"in main(), b = " << b << endl;
    return 0;
}

/*
template<typename T1,typename T2> void Wrapper(T1&& x, T2&& y)
{  }

T1 <---- int&
T2 <---- float&

T1&& x  ----> int& &&x   ---> int& x
T2&& y  ----> float& &&y ---> float& y

Wrapper(a,b);         // (int&, float&)  
*****************************************************

T1 <---- int&&
T2 <---- float&&

T1&& x  ----> int&& &&x   ---> int&& x   --> int x
T2&& y  ----> float&& &&y ---> float&& y  --> float y

Wrapper(100,56.21f);  // (int&& , float&&)

*/