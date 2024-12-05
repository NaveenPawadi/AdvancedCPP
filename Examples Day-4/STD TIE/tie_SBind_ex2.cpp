#include<iostream>
#include<tuple>
#include<set>
using namespace std;

int main()
{
    set<int> v1={10,20,30,40,50};
    cout <<"contents of set, before insertion:" << endl;
    for(auto& x:v1){cout << x <<",";}; cout << endl;

    set<int>::iterator itr;
    bool success; 
    std::tie(itr,success) = v1.insert(500);
    if(success)
    { 
        cout <<"Inserted successfully" << *itr << endl;
    }

    //****************************
    const auto&[position,insert_ok] = v1.insert(600);
    if(insert_ok)
    {
        cout <<"successfully inserted:" << *position << endl;
    }
}

