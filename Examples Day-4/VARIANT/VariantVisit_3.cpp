#include<iostream>
#include<variant>
#include<vector>
using namespace std;

template<typename... Args> struct Variadic:Args...
{
    Variadic(Args...)=delete;
    using Args::operator()...;
};

//template<typename... Args> Variadic(Args...) ->Variadic<Args...>;


using var_data = variant<int,float,const char*>;

int main()
{
    vector<var_data> v1 ={10,20,30,45.12f,"hi",200,"cpp",45.21f};

    for(auto& x:v1)
    {
        visit(Variadic{
            [](int x){cout << x <<",";},
            [](float x){cout << x <<",";},
            [](const char* x){cout << *x <<",";}},
            x);
    }
    return 0;
}