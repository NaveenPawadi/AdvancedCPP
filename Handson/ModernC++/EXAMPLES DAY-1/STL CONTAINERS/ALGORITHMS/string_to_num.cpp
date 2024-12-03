#include<iostream>
#include<string>
#include<sstream>
using namespace std;

void main()
{
	string n ="54";
	int num;
	istringstream convert(n);
	if(convert >> num)
		cout << num << endl;
	else
		cout <<"could not convert" << endl;
	num = num >> 1;
	cout <<"--int -- " <<num << endl;
}