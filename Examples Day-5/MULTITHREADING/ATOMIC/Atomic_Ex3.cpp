#include <atomic>
#include <thread>
#include <iostream>

std::atomic<int> counter{0};

void increment_counter() {   counter++; }

int main() {
    std::thread t1(increment_counter);
    std::thread t2(increment_counter);
    std::thread t3(increment_counter);

    t1.join();
    t2.join();
    t3.join();

    // counter should be equal to 3
    std::cout << "counter value is: " <<  counter.load();

    return 0;
}