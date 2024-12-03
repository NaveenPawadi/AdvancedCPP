//deque, constructors
#include <deque>
#include <iostream>
using namespace std;

int main() 
{
deque <int>::iterator deq0Iter, deq1Iter, deq2Iter, deq3Iter, deq4Iter, deq5Iter, deq6Iter;

//Create an empty deque deq0
deque <int> deq0;

//Create a deque deq1 with 10 elements of default value 0
deque <int> deq1(10);

//Create a deque deq2 with 7 elements of value 10
deque <int> deq2(7, 10);

//Create a deque deq3 with 4 elements of value 2 and with the 
//allocator of deque deq2
deque <int> deq3(4, 2, deq2.get_allocator());

//Create a copy, deque deq4, of deque deq2
deque <int> deq4(deq2);

//deque deq5 a copy of the deq4[_First, _Last) range
deq4Iter = deq4.begin();
deq4Iter++;
deq4Iter++;
deq4Iter++;
deque <int> deq5(deq4.begin(), deq4Iter);

//Create a deque deq6 by copying the range deq4[_First, _Last) and 
//the allocator of deque deq2
deq4Iter = deq4.begin();
deq4Iter++;
deq4Iter++;
deq4Iter++;
deque <int> deq6(deq4.begin(), deq4Iter, deq2.get_allocator());

//------------------------------------
cout<<"Operation: deque <int> deq0\n";
cout<<"deq0 data: ";
for(deq0Iter = deq0.begin(); deq0Iter != deq0.end(); deq0Iter++)
cout<<*deq0Iter<<" ";
cout<<endl;

cout<<"\nOperation: deque <int> deq1(10)\n";
cout<<"deq1 data: ";
for(deq1Iter = deq1.begin(); deq1Iter != deq1.end(); deq1Iter++)
cout<<*deq1Iter<<" ";
cout<<endl;

cout<<"\nOperation: deque <int> deq2(7, 3)\n"; 
cout<<"deq2 data: ";
for(deq2Iter = deq2.begin(); deq2Iter != deq2.end(); deq2Iter++)
cout<<*deq2Iter<<" ";
cout<<endl;

cout<<"\nOperation: deque <int> deq3(4, 2, deq2.get_allocator())\n";
cout<<"deq3 data: ";
for(deq3Iter = deq3.begin(); deq3Iter != deq3.end(); deq3Iter++)
cout<<*deq3Iter<<" ";
cout<<endl;

cout<<"\nOperation: deque <int> deq4(deq2);\n";
cout<<"deq4 data: ";
for(deq4Iter = deq4.begin(); deq4Iter != deq4.end(); deq4Iter++)
cout<<*deq4Iter<<" ";
cout<<endl;

cout<<"\nOperation1: deq4Iter++...\n";
cout<<"Operation2: deque <int> deq5(deq4.begin(), deq4Iter)\n";
cout<<"deq5 data: ";
for(deq5Iter = deq5.begin(); deq5Iter != deq5.end(); deq5Iter++)
cout << *deq5Iter<<" ";
cout << endl;

cout<<"\nOperation1: deq4Iter = deq4.begin() and deq4Iter++...\n";
cout<<"Operation2: deque <int> deq6(deq4.begin(), \n"
"      deq4Iter, deq2.get_allocator())\n";
cout<<"deq6 data: ";
for(deq6Iter = deq6.begin(); deq6Iter != deq6.end(); deq6Iter++)
cout<<*deq6Iter<<" ";
cout<<endl;
return 0;
}
