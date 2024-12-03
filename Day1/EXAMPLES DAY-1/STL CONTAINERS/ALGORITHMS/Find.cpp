#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void main()
{
	int num_to_find = 3;           

 vector<int> v1;
 for( int i = 0; i < 10; i++ ) 
 {
   v1.push_back(i);
 }              

 vector<int>::iterator result;
 result = find( v1.begin(), v1.end(), num_to_find );            

 if( result == v1.end() ) 
 {
   cout << "Did not find any element matching " << num_to_find << endl;
 }              
 else 
 {
   cout << "Found a matching element: " << *result << endl;
 }              

}