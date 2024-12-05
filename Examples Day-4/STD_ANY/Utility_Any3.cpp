#include <string>
#include <iostream>
#include <any>
using namespace std;

/*  
	An instance that can hold any data-type
- 'any' does not facilitate conversion to other types on the value held by it.
- 'any' object might be empty.
- 'any' shouldn't use any dynamically allocated memory, but it's not guaranteed by the spec.
*/
class CA
{
private:
	int a=10;
public:
	CA(){cout <<"CA constructor" << endl;}	
	CA(const CA& x):a(x.a) {cout <<"CA copy constructor" << endl;}
	~CA(){cout <<"CA destructor" << endl;}
};
int main()
{
	auto a = any(12);
	// set any value:
	a = string("Hello!");
	cout << any_cast<string>(a) << endl;   //OK
	a = 16;
	// we can read it as int
	cout << any_cast<int>(a) << endl;   
	//will throw exception as it is not a string:
	try
	{
		cout << any_cast<string>(a) << endl;
	}
	catch (const bad_any_cast& e)
	{
		cout << e.what() << endl;
	}
	// reset and check if it contains any value:
	a.reset();
	if (!a.has_value())
	{
		cout << "any object 'a' is empty!" << endl;
	}
	cout <<"-------------------------" << endl;

	std::any ob = CA();
	cout <<"-----------" << endl;
	return 0;
}