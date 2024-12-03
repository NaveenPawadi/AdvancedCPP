#include<iostream>
#include<vector>
using namespace std;

int main()
{
    vector<int> vt ={10,20,30,40,50};

    //C++11,14,17 approach
    int i=1;  //here 'i' is declared outside of the range-for scope
    for(auto& x:vt)
    {
        x += i++;
    }
    cout << endl <<"------------------" << endl;

    //C++20 approach- Range based loop with initializer
    // for(int j=1; auto& x:vt)
    // {
    //     x += j++;
        
    // }

    for(auto x:vt)
    {
        cout <<x <<",";
    }
    return 0;
}