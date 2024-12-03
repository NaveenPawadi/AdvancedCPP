#include<iostream>
#include <concepts>
using namespace std;
/*
    A constraint that should evaluate to true, only if the return
    type of the function is of type 'int'.
*/
template <typename T> concept invoke_integral = 
                                requires (T a) {
                                                 { a() } -> std::integral;
                                               };
//Note: We have used the concept name in the typename list.                                               };
template <invoke_integral T> void Myfunction(const T& f) 
{
    cout << f() << endl;
};

int main() 
{
    //Myfunction([](){ return 100; }); // OK
    //Myfunction([](){ return 1.0; }); // Fail: doesn't return integral
    Myfunction(1); // Fail: 1() is not a callable entity

    return 0;
}



  
  

  