#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

void main()
{
	vector<int> v1;
 for( int i = 0; i < 10; i++ ) 
 {
   v1.push_back(i);
   // add a duplicate 7 into v1
   if( i == 7 ) {
     v1.push_back(i);           
   }
 }              

 vector<int>::iterator result;
 result = adjacent_find( v1.begin(), v1.end() );                

 if( result == v1.end() ) {
   cout << "Did not find adjacent elements in v1" << endl;
 }              

 else {
   cout << "Found matching adjacent elements starting at " << *result << endl;
 }              

}