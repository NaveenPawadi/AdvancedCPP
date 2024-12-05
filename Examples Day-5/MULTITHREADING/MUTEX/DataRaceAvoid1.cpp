#include<iostream>
#include<thread>
#include<mutex>
using namespace std;

std::mutex mlock;

void Decrement()
{
	for (int i = -1; i > -100; i--)
	{
        mlock.lock();
		cout << "Decrement :" << i << endl;
        //...
		//this_thread::sleep_for(1s);
        mlock.unlock();
	}
}

void Increment()
{
	for (int i = 1; i<100; i++)
	{
        mlock.lock();
		cout <<"Increment :"<< i << endl;
		//this_thread::sleep_for(1s);
        mlock.unlock();
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