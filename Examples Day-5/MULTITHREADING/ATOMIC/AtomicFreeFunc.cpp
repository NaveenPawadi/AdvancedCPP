#include<iostream>
#include<atomic>

using namespace std;

/*
    * Global functions that operate on atomic types...without memory ordering
        - atomic_load()
        - atomic_store()
        - atomic_is_lock_free()
        - atomic_compare_exchange_weak()
    * Global functions that operate with memory ordering
        - atomic_load_explicit()
        - atomic_store_explicit()
        - atomic_compare_exchange_weak_explicit()
*/

int main()
{
    atomic<bool> ob = false;
    auto result = atomic_is_lock_free(&ob);
    cout <<"Is atomic<int> lock free ? " << std::boolalpha <<  result << endl;
    cout <<"----------------------" << endl;
    //with memory ordering....
    result = atomic_load_explicit(&ob, std::memory_order_acquire);
    cout <<"Value obtained upon load ? " << std::boolalpha <<  result << endl;
    return 0;
}