#include<iostream>
#include<vector>
#include<algorithm>
#include<variant>
#include<string>
using namespace std;

template<typename... PACK> void ExtractInfo(PACK... Args)
{
    vector<std::variant<int, char, float, double, const char*>> v1;

    auto data =[&](auto&& ...vals)
    {
        (v1.emplace_back(vals),...);
    };

    data(Args...);
    //*************************
    for(auto& x:v1)
    {
        std::visit([&](auto& x){cout << x << endl;}, x);
    }    
}

//consumer code
int main()
{
    //ExtractInfo(45, 34.21, 89.56f, 300, 'r');
    ExtractInfo(45, 34.21, 89.56f, 300, "raw", 'c');
    return 0;
}