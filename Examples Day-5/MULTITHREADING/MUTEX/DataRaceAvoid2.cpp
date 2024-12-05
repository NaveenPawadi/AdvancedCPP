#include<iostream>
#include<thread>
#include<mutex>
using namespace std;

std::mutex mlock;
/*
    With lock_guard wrapper class instance, lock and unlock is automatic.
    The call to 'lock' function of the mutex is in the constructor and
    the call to 'unlock' function of the mutex is in the destructor of the class.

    An instance of lock_guard wrapper class is exception safe, even upon an 
    exception it ensures there will be a call to 'unlock' function, and thus
    no waiting thread(s) have to starve or wait infinetly.
*/
void Decrement()
{
	for (int i = -1; i > -100; i--)
	{
        
        lock_guard<mutex> guard(mlock);
		cout << "Decrement :" << i << endl;
        //...
		//this_thread::sleep_for(1s);
        
	}
}

void Increment()
{
	for (int i = 1; i<100; i++)
	{
        lock_guard<mutex> guard(mlock);
		cout <<"Increment :"<< i << endl;
		//this_thread::sleep_for(1s);
	}
}

int main()
{
	thread th1(&Increment);
	thread th2(&Decrement);
	//..
	th1.join();
	th2.join();

	return 0;
}