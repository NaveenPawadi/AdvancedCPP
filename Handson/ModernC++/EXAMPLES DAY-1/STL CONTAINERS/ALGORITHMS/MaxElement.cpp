#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void main()
{
	int array[] = { 3, 1, 4, 1, 5, 9 };
 unsigned int array_size = 6;
 cout << "Max element in array is " << *max_element( array, array+array_size) << endl;              

 vector<char> v;
 v.push_back('a'); v.push_back('b'); v.push_back('c'); v.push_back('d');
 cout << "Max element in the vector v is " << *max_element( v.begin(), v.end() ) << endl;        
}