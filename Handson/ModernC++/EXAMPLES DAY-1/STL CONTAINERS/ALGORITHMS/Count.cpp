#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void main()
{
vector<int> v;
 for( int i = 0; i < 10; i++ ) 
 {
   v.push_back( i );
 }              

 int target_value = 3;
 int num_items = count( v.begin(), v.end(), target_value );             

 cout << "v contains " << num_items << " items matching " << target_value << endl;     
}