#include<iostream>
#include<atomic>
using namespace std;
/*
    CPP-17, macros that help in identifying whether the various integral types
            are lock-free during compile-time on a given hardware.
    Never lock free  --> 0
    Lock free status is run-time property  --> 1
    Always lock free --> 2
*/

int main()
{
    cout <<"bool type : "<< ATOMIC_BOOL_LOCK_FREE << endl;
    cout << "char type :"<<ATOMIC_CHAR_LOCK_FREE << endl;
    cout << "char16 type:"<<ATOMIC_CHAR16_T_LOCK_FREE << endl;
    cout << "char32 type :"<<ATOMIC_CHAR32_T_LOCK_FREE << endl;
    cout << "wchar type :" <<ATOMIC_WCHAR_T_LOCK_FREE << endl;
    cout <<"short type :"<< ATOMIC_SHORT_LOCK_FREE << endl;
    cout << "int type :"<< ATOMIC_INT_LOCK_FREE << endl;
    cout << "long type :"<<ATOMIC_LONG_LOCK_FREE << endl;
    cout << "long long type :"<<ATOMIC_LLONG_LOCK_FREE << endl;
    cout << "pointer type :" <<ATOMIC_POINTER_LOCK_FREE << endl;
    
    return 0;
}