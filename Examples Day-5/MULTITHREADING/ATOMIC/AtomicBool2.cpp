#include<iostream>
#include<atomic>
using namespace std;

/*
    * Apart from load(), store() and exchange() functions of 'atomic<bool' type,
      it also provides additional function to store a new value, if the current
      value is equal to an expected value called - 'compare_exchange'
    
    * The 'compare_exchange' comes in 2 flavours
        - compare_exchange_weak
        - compare_exchange_strong 
    * memory ordering pairs for success/failure
        - std::memory_order_acquire,  std::memory_order_acquire
        - std::memory_order_seq_cst,  std::memory_order_seq_cst
        - std::memory_order_acq_rel,  std::memory_order_acquire
        - std::memory_order_acq_rel,  std::memory_order_relaxed
*/

int main()
{
    std::atomic<bool> a = true;
    bool expected = false;
    bool success;
    //cout << a.exchange(true) << endl;
    cout <<"before compare_exchange, expected = " << expected << ", success =" << success << endl;

    success = a.compare_exchange_weak(expected, false);

    cout <<"after compare_exchange, expected = " << expected << ", success =" << success << endl;
    return 0;
}