#include<iostream>
#include<complex>
using namespace std;

void main()
{
	complex<int> obj1(1,2), obj2(10,20), obj3;
    cout <<"obj1 = " << obj1 << endl;
	cout <<"obj2 = " <<obj2 << endl;
	obj3 = obj1 + obj2;
	cout <<"obj3 ="<<obj3 << endl;
	obj3 *= 10;
	cout <<"obj3 = " << obj3 << endl;
	obj3.imag(obj3.imag() + 100);
	cout <<"obj3 = " << obj3 << endl;
}