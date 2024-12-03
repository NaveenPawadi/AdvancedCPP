#include<iostream>
#include<string>
using namespace std;

void main()
{
	string str1, str2;
	cout <<"enter a string ";
	cin >> str1;
	int len = str1.length();
	for(int i=len;i>=0; i--)
	{
		string str = str1.substr(i, 1);
		str2 = str2 + str;
	}
	cout <<"original string " << str1 << endl;
	cout <<"reversed string " << str2 << endl;
	int pos = str1.find(str2, 0);
	if(pos ==0)
		cout <<"string is palindrome"<<endl;
	else
		cout <<"string is not a palindrome"<<endl;
}