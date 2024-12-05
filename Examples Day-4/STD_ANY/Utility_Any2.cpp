#include <any> 
#include <iostream> 
#include <string> 
using namespace std;
int main() 
{ 
    try 
    { 
        any var;

        if (var.has_value())
        {
            auto result = *(var.type().name());
            switch (result)
            {
                case 'i': cout <<any_cast<int>(var);
                break;
                case 'c': cout <<any_cast<char>(var);
                break;
                case 'f': cout <<any_cast<float>(var);
                break;
                case 'd': cout <<any_cast<double>(var);
                break;
                case 'b': cout <<any_cast<bool>(var);
                break;
            }
        }
        else
        {
            cout <<"void / no value" << endl;
        }
    } 
  
    catch (bad_any_cast& e) 
    { 
        cout << "\n" << e.what(); 
    } 
    return 0; 
} 