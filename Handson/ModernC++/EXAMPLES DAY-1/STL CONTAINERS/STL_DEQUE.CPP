//simple deque example
#include <iostream>
#include <deque>
using namespace std;

int main()
{
//deque container for floating-point elements
//declaration
deque<float> elem, elem1;

//insert the elements each at the front
cout<<"push_front()\n";
for(int i=1; i<=10; ++i) 
//insert at the front
elem.push_front(i*(1.2));

//print all elements separated by a space
for(i=0; i<elem.size(); ++i) 
cout<<elem[i]<<' ';
cout<<endl;

//insert the elements each at the back
cout<<"\npush_back()\n";
//insert at the back
for(i=1; i<=10; ++i) 
elem1.push_back(i*(1.2));

//print all elements separated by a space
for(i=0; i<elem1.size(); ++i) 
cout<<elem1[i]<<' ';
cout<<endl;

return 0;
}