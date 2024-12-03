#include<unordered_map>
#include<iostream>
#include<string>
using namespace std;

int main()
{
    unordered_multimap<int, string> mul_map{{1,"first"},{2,"Second"},{3,"Third"},{4,"Fourth"},{5,"Fifth"},{6,"Sixth"}};
    cout <<"size of Unordered multi-map :" << mul_map.size() << endl;
    cout <<"Number of buckets :" << mul_map.bucket_count() << endl;
    cout <<"Count of key (2) before duplication:" << mul_map.count(2) << endl;

    mul_map.emplace(2,"Second-Duplicate");

    cout <<"Count of key (2) after duplication:" << mul_map.count(2) << endl;
    
    int key{};
    cout <<"enter key to find :";
    cin >> key;

    auto itr = mul_map.find(key);
    if(itr != mul_map.end())
        cout <<"key " << itr->first <<",found, its value :" << itr->second << endl;
    else
        cout <<"key " << key <<" not found" << endl;
    return 0;
}