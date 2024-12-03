#include<iostream>
#include<vector>
using namespace std;

void main()
{
	vector<int> v1;
	vector<double> v2;
	cout <<"max elements of type int" << v1.max_size()<< endl;
	cout <<"max elements of type double " << v2.max_size()<< endl;
	cout <<"initial size of the vector " << v1.size() << endl;
	//add some integers into the vector container
	for(int i=1;i<=10;i++)
	{
		v1.push_back(i);
	}
	cout <<"size of the vector after pushing..." << v1.size() << endl;
	//traverse the vector 
	vector<int>::iterator itr = v1.begin();
	while(itr != v1.end())
	{
		cout << *itr << ",";
		itr ++;
	}
	//insert nodes at a specific location
	itr = v1.begin();
	itr +=2;
	v1.insert(itr,100);
	//itr++;
	v1.insert(itr,200);
	itr = v1.begin();
	cout <<"contents of the vector after insertion" << endl;
	while(itr != v1.end())
	{
		cout << *itr << ",";
		itr ++;
	}
	cout << endl;
}