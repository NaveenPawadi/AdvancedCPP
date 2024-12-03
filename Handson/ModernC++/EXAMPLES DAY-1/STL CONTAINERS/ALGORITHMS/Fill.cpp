#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void main()
{
vector<int> v1;
 for( int i = 0; i < 10; i++ ) 
 {
   v1.push_back( i );
 }              

 cout << "Before, v1 is: ";
 for(i = 0; i < v1.size(); i++ ) 
 {
   cout << v1[i] << " ";
 }
 cout << endl;            

 fill( v1.begin(), v1.end(), -1 );              

 cout << "After, v1 is: ";
 for(i = 0; i < v1.size(); i++ ) 
 {
   cout << v1[i] << " ";
 }
 cout << endl;     
}