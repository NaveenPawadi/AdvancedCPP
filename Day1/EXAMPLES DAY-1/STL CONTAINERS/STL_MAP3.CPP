
#include <map>
#include <iostream>

int main()
{
    using namespace std;
    map<int, int> m1, m2, m3;
    map<int, int>::iterator pIter, Iter1, Iter2;
    int i;
    map<int, int>::size_type n;
    typedef pair<int, int> Int_Pair;

    for (i = 1; i < 5; i++)
    {
        m1.insert(Int_Pair(i, i));
        m2.insert(Int_Pair(i, i*i));
        m3.insert(Int_Pair(i, i-1));
    }

    // The 1st member function removes an element at a given position
    Iter1 = ++m1.begin();
    m1.erase(Iter1);

    cout << "After the 2nd element is deleted, the map m1 is:";
    for (pIter = m1.begin(); pIter != m1.end(); pIter++)
        cout << " " << pIter->second;
    cout << "." << endl;

    // The 2nd member function removes elements
    // in the range [_First, _Last)
    Iter1 = ++m2.begin();
    Iter2 = --m2.end();
    m2.erase(Iter1, Iter2);

    cout << "After the middle two elements are deleted,"
         << " the map m2 is:";
    for (pIter = m2.begin(); pIter != m2.end(); pIter++)
        cout << " " << pIter->second;
    cout << "." << endl;

    // The 3rd member function removes elements with a given _Key
    n = m3.erase(2);

    cout << "After the element with a key of 2 is deleted,\n"
         << "the map m3 is:";
    for (pIter = m3.begin(); pIter != m3.end(); pIter++)
        cout << " " << pIter->second;
    cout << "." << endl;

    // The 3rd member function returns the number of elements removed
    cout << "The number of elements removed from m3 is: "
         << n << "." << endl;

    // The dereferenced iterator can also be used to specify a key
    Iter1 = ++m3.begin();
    m3.erase(Iter1);

    cout << "After another element with a key equal to that"
         << endl;
    cout  << "of the 2nd element is deleted, "
          << "the map m3 is:";
    for (pIter = m3.begin(); pIter != m3.end(); pIter++)
        cout << " " << pIter->second;
    cout << "." << endl;
}