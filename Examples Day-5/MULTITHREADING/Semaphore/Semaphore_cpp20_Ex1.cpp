#include <iostream> 
#include <semaphore>  //C++20
#include <thread> 
using namespace std; 

//synchronization primitive that allows multiple threads to access a shared resource up to a certain limit

  
// Initialize semaphore with a count of 3 
counting_semaphore<10> smp(3); 
  
void Fun() 
{ 
    //By acquiring a lock it decreases the semaphore count
    smp.acquire(); 
  
    // doing some work 
    cout << "Thread " << this_thread::get_id() << " acquired the semaphore." << endl; 
  
    // By releasing a lock it increases the semaphore count
    smp.release(); 
    cout << "Thread " << this_thread::get_id() << " released the semaphore." << endl; 
} 
  
// driver code 
int main() 
{ 
    thread th1(Fun); 
    thread th2(Fun); 
    thread th3(Fun); 

    th1.join(); 
    th2.join(); 
    th3.join(); 

    return 0; 
}