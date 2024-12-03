#include<iostream>
#include<array>
using namespace std;

template<size_t... PACK> class CA
{
private:
    std::array<size_t, sizeof...(PACK)> arr = {PACK...};
public:
    CA()//:arr{PACK...}
    {
        cout <<"No: of arguments received..." << sizeof...(PACK) << endl;
    }
    auto begin(){return arr.begin();}
    auto end(){return arr.end();}
};

int main()
{
    CA<10,20,30,40,50,60> ob1;
    for(auto x:ob1)
    {
        cout << x <<",";
    }
    cout << endl;
    return 0;
}