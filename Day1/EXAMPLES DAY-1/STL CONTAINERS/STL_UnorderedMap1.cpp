#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;

int main()
{
    unordered_map<int, string> mob;
    //populate the map
    mob[1]="string-1";
    mob[2]="string-2";
    mob[3]="string-3";
    mob[4]="string-4";
    mob[5]="Ganesh";
    mob.insert(pair(6,"Prabhu"));
    //iterate
    // unordered_map<int, string>::iterator itr = mob.begin();
    // while(itr != mob.end())
    // {
    //     cout << "key " << itr->first <<", value =" << itr->second << endl;
    //     itr ++;
    // }
    // cout << endl <<"--------------" << endl;
    for(auto x:mob)
    {
        cout <<"key =" << x.first << ", value = " << x.second << endl;
    }
    return 0;
}