#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int calculate(int x)
{
    return x*x;
}

int main()
{
    vector<int> v1={10,20,30,40,50,60};
    vector<int> v2;
    
    std::transform(v1.begin(), v1.end(), std::back_inserter(v2), calculate);
    for(auto x:v2)
    {
        cout << x <<",";
    }
    cout << endl;
    return 0;
}