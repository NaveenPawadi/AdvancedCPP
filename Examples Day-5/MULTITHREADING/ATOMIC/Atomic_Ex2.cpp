#include<iostream>
#include<atomic>
using namespace std;

int main()
{
    cout << std::boolalpha << atomic<int>::is_always_lock_free << endl;
    atomic<int> AtomicInt{};
    cout << std::boolalpha << AtomicInt.is_lock_free() << endl;
    return 0;
}