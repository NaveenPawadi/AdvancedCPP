#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void main()
{
	vector<int> from_vector;
 for( int i = 0; i < 10; i++ ) 
 {
   from_vector.push_back( i );
 }              

 vector<int> to_vector(15);               

 copy_backward( from_vector.begin(), from_vector.end(), to_vector.end() );              

 cout << "to_vector contains: ";
 for(i = 0; i < to_vector.size(); i++ ) 
 {
   cout << to_vector[i] << " ";
 }
 cout << endl;            

}