#include<unordered_map>
#include<iostream>
#include<string>
using namespace std;

int main()
{
    unordered_multimap<int, string> mul_map{{1,"first"},{2,"Second"},{3,"Third"},{4,"Fourth"},{5,"Fifth"},{6,"Sixth"}};
    auto bkt_count = mul_map.bucket_count();
    cout <<"mul_map objects contains " << bkt_count <<" buckets" << endl;
    
    cout <<"Initial contents of the unordered multi-map" << endl;
    for(int b_count{1}; auto& x:mul_map)
    {
        cout << "bucket ->" << b_count <<", contains " << x.first <<"," << x.second << endl;
        b_count++;
    }
  
    cout << endl;
    //Insert a duplicate
    mul_map.emplace(2,"Second-Duplicate");
    cout <<"-- Traversing the unordered multi-map after duplicate entry --" << endl;
   
    for(int b_count{1}; auto& x:mul_map)
    {
        cout << "bucket ->" << b_count <<", contains " << x.first <<"," << x.second << endl;
        b_count++;
    }
    return 0;
}