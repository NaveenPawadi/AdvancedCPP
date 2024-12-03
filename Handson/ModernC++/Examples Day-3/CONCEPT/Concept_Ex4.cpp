#include<iostream>
#include<concepts>
using namespace std;

class CA{ };
class CB:public CA{ };
class CC{ };

int main()
{
    if(derived_from<CB,CA>)
    {
        cout <<"CB derives from CA" << endl;
    }
    else
    {
        cout <<"CB does not derive from CA" << endl;
    }
    if(derived_from<CC,CA>)
    {
        cout <<"CC derives from CA" << endl;
    }
    else
    {
        cout <<"CC does not derive from CA" << endl;
    }
    return 0;
}