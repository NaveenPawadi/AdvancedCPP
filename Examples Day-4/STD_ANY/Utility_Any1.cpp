#include <any> 
#include <iostream> 
#include <string> 
using namespace std;
int main() 
{ 
    try 
    { 
        any var = 9.5; 

        if (var.has_value()) 
            cout << " \n Value found of type "
                 << var.type().name(); 
    } 
  
    catch (bad_any_cast& e) { 
        cout << "\n" << e.what(); 
    } 
    return 0; 
} 