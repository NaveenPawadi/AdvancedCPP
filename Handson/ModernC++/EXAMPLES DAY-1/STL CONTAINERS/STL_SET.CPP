#include <set>
#include <iostream>

using namespace std ;

typedef set<int> SET_INT;

void main() {
  SET_INT s1;
  SET_INT s2;
  SET_INT::iterator i;
  cout << "s1.insert(5)" << endl;
  s1.insert(5);
  cout << "s1.insert(10)" << endl;
  s1.insert(10);
  cout << "s1.insert(15)" << endl;
  s1.insert(15);
  cout << "s2.insert(2)" << endl;
  s2.insert(2);
  cout << "s2.insert(4)" << endl;
  s2.insert(4);

  cout << "swap(s1,s2)" << endl;
  swap(s1,s2);

  // Displays: 2,4
  for (i=s1.begin();i!=s1.end();i++)
     cout << "s1 has " << *i << " in its set." << endl;

  // Displays: 5,10,15
  for (i=s2.begin();i!=s2.end();i++)
     cout << "s2 has " << *i << " in its set." << endl;

  cout << "s1.swap(s2)" << endl;
  s1.swap(s2);

  // Displays: 5,10,15
  for (i=s1.begin();i!=s1.end();i++)
     cout << "s1 has " << *i << " in its set." << endl;

  // Displays: 2,4
  for (i=s2.begin();i!=s2.end();i++)
     cout << "s2 has " << *i << " in its set." << endl;
  cout <<"Total no of keys with 5 " << endl;
  cout <<s1.count(5)<<endl;

  i = s2.find(2);
  if(i != s2.end())
	  cout << *i << endl;
  
}
