#include <iostream> 
#include <semaphore> 
#include <thread> 
using namespace std; 

//signaling between two threads

// Initialize with a count of 1 (binary) 
binary_semaphore smp(1); 
  
void Fun() 
{ 
    //acquire
    smp.acquire(); 

    cout << "Thread " << this_thread::get_id() << " acquired the semaphore." << endl; 
    // Do some busy work 

    smp.release(); 
    // release 
    cout << "Thread " << this_thread::get_id() << " released the semaphore." << endl; 
} 
  
// driver code 
int main() 
{ 
    thread th1(Fun); 
    thread th2(Fun); 
    th1.join(); 
    th2.join(); 

    return 0; 
}