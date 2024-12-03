#include<iostream>
#include<vector>
using namespace std;

template<int... Args> class CA
{
private:
    const vector<int> v1={Args...};
public:

    auto begin() {return v1.begin();}  
    auto end(){return v1.end();}  
};

//****consumer code *****
int main()
{
    CA<10,20,30,40,50,60> obj1;
    for(auto x:obj1)
    {
        cout << x <<" ";
    }
    cout << endl;
    return 0;
}