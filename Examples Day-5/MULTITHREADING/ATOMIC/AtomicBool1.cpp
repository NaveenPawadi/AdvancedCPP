#include<iostream>
#include<atomic>

using namespace std;
/*

    * atomic<bool> type behaviours
        -store()   --> Does a write, equivalent to 'clear' in atomic_flag
        -load()    --> Does a read, 'atomic_bool' specific member
        -exchange()--> Does read/modify/write, equivalent to 'test_and_set'in atomic_flag
*/

int main()
{
    atomic<bool> b;
    
    cout <<"Is atomic<bool> b lock free ? " << b.is_lock_free() << endl;
    bool x = b.load();  //memory order defaults to ... std::memory_order_seq_cst
    //bool x = b.load(std::memory_order_acquire);
    
    cout <<"upon b.load, x =" << x << endl;
    b.store(true);
    cout <<"b.store(true) =" << b << endl;
    
    x = b.exchange(false);
    //x = b.exchange(false, std::memory_order_acq_rel);
    
    cout <<"upon exchange, x = " << x << " and b =" << b  <<endl;

    return 0;
}