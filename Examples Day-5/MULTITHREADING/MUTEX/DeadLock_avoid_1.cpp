#include<iostream>
#include<thread>
#include<mutex>
using namespace std;

class CA
{
private:
	//...
	mutex m1, m2;
public:
	void fun1(int x)
	{
		lock_guard<mutex> guard1(m1);
		lock_guard<mutex> guard2(m2);
		cout << "CA-fun1 called " << x << endl;
	}
	void fun2(int x)
	{
		lock_guard<mutex> guard1(m1);       //apply lock on multiple mutex in the same order across diff. functions.
		lock_guard<mutex> guard2(m2);
		//lock_guard<mutex> guard1(m1);
		cout << "CA-fun2 called " << x << endl;
	}
};

void process(CA& ob)
{
	for (int i = 100; i <= 2000; i++)
	{
		ob.fun1(i);
	}
}
void main()
{
	CA obj1;
	thread th1(process, ref(obj1));
	for (int i = 1; i <= 999; i++)
	{
		obj1.fun2(i);
	}
	th1.join();
}