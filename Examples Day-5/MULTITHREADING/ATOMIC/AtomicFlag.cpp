#include<iostream>
#include<thread>
#include<atomic>
#include<conio.h>
using namespace std;

/*
    std::atomic_flag instances upon defining must and should be initialized 
    with macro ATOMIC_FLAG_INIT
    
    The macro ATOMIC_FLAG_INIT sets the atomic_flag instance to clear state.

    Instances of 'atomic' types are not copy constructable nor assignable

    Member function...
    std::atomic_flag::clear - is a store operation
    std::atomic_flag::test_and_set - is read/write/modify operation
*/

void fun()
{
    std::atomic_flag fg = ATOMIC_FLAG_INIT;
    
    cout <<"Before std::memory_order_release ->" << fg.test_and_set(std::memory_order_release) <<endl;
    
    cout <<"Before std::memory_order_acquire ->" << fg.test_and_set(std::memory_order_acquire) <<endl;
    
    cout <<"Before std::memory_order_relaxed ->" << fg.test_and_set(std::memory_order_relaxed) <<endl;

    cout <<"After std::memory_order_relaxed ->" << fg.test_and_set(std::memory_order_relaxed) <<endl;
}

int main()
{
    fun();
    return 0;
}