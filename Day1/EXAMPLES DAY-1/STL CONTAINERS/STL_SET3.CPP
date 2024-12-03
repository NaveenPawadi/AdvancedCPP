#include <set>
#include <iostream>
#include <string>

int main( )
{
   using namespace std;
   set <int>::iterator s1_pIter, s2_pIter;

   set <int, less<int> > s1, s2;
   s1.insert( 10 );
   s1.insert( 20 );
   s1.insert( 30 );
   s1.insert( 40 );

   cout << "The original s1 =";
   for ( s1_pIter = s1.begin( ); s1_pIter != s1.end( ); s1_pIter++ )
      cout << " " << *s1_pIter;
   cout << "." << endl;

   pair< set<int>::iterator, bool > pr;
   pr = s1.insert( 10 );

   if(pr.second == true)   
   {
      cout << "The element 10 was inserted in s1 successfully."
           << endl;
   }
   else   
   {
      cout << "The element 10 already exists in s1 and"
           << " *( pr.first ) = " << *( pr.first ) << "." << endl;
   }

   s1.insert( --s1.end( ), 50 );

   cout << "After the insertions, s1 =";
   for ( s1_pIter = s1.begin( ); s1_pIter != s1.end( ); s1_pIter++ )
      cout << " " << *s1_pIter;
   cout << "." << endl;

   s2.insert( 100 );
   s2.insert( ++s1.begin( ), --s1.end( ) );

   cout << "s2 =";
   for ( s2_pIter = s2.begin( ); s2_pIter != s2.end( ); s2_pIter++ )
      cout << " " << *s2_pIter;
   cout << "." << endl;

   // Construct by moving
   set<string> s3, s4;
   string str1("a"), str2("b");

   s3.insert(move(str1));
   cout << "After the move insertion, s3 contains: "
      << *s3.begin() << endl;

   s4.insert(s4.begin(), move(str2));
   cout << "After the move insertion, s4 contains: "
      << *s4.begin() << endl;
 }