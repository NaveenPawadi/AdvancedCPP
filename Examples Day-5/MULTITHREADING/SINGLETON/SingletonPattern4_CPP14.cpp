#include<iostream>
#include<thread>
#include<mutex>
#include<memory>
using namespace std;
//C++14 approach - A LOCK-FREE singleton

std::once_flag Flag;
class Singleton
{
private:
	static shared_ptr<Singleton> ptr;
	Singleton();

public:
	Singleton(const Singleton &) = delete;
	Singleton(Singleton &&) = delete;
	Singleton &operator=(const Singleton &) = delete;
	Singleton &operator=(Singleton &&) = delete;
	static auto GetInstance();
	void Destroy();
	~Singleton();
};

// static data member definition
shared_ptr<Singleton> Singleton::ptr;

Singleton::Singleton()
{
	cout << "Singleton Constructor, thread id :" << this_thread::get_id() << endl;
}
auto Singleton::GetInstance()
{
	//---lambda definition begins....
	auto Single_Instance = []()
	{
		Singleton *p = new (nothrow) Singleton();
		if (p)
		{
			shared_ptr<Singleton> pt(p);
			ptr.swap(pt);
		}
		else
		{
			ptr = nullptr;
		}
		return ptr;
	};
	//---lambda definition ends...
	call_once(Flag, Single_Instance); // Invoke the lambda
	return ptr;
}
void Singleton::Destroy() { ptr.reset(); }
Singleton::~Singleton()
{
	cout << "Singleton destructor..." << this_thread::get_id() << endl;
}

//******************
void client1()
{
	auto tm = Singleton::GetInstance();
	if(tm)
		cout << "Singleton_handle : " << tm.get() << endl;
}

void client2()
{
	auto tm = Singleton::GetInstance();
	if(tm)
		cout << "Singleton_handle : " << tm.get() << endl;
}

int main()
{
	auto tm = Singleton::GetInstance();
	if(tm)
		cout << "Singleton_handle : " << tm.get() << endl;

	thread th1(client1);
	thread th2(client2);
	
	th1.join();
	th2.join();

	return 0;
}