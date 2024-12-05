#include<iostream>
#include<variant>
#include<vector>
using namespace std;

template<typename... pack> struct Print:pack...
{
    using pack::operator()...;
};

using var_data = variant<int,float,const char*>;

int main()
{
    vector<var_data> v1 ={10,20,30,45.12f,"hi",200,"cpp",45.21f};

    auto lint =[](int x){cout << x <<",";};
    auto lfloat = [](float x){cout << x <<",";};
    auto lchar = [](const char* x){cout << *x <<",";};
    
    for(auto& x:v1)
    {
        visit(Print<decltype(lint),decltype(lfloat),decltype(lchar)>{lint,lfloat,lchar},x);
        //visit(Print<lint,lfloat,lchar>{lint,lfloat,lchar,x});
    }
    return 0;
}