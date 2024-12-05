#include <string>
#include <iostream>
#include <any>
#include <map>
using namespace std;

/*  NOTE:
	- 'any' does not facilitate conversion to other types on the value held by him.
	- 'any' object might be empty.
	- 'any' shouldn't use any dynamically allocated memory, but it's not guaranteed by the spec.
*/

int main()
{
	map<string, any> m;
	m["integer"] = 10;
	m["string"] = string("Hello World");
	m["float"] = 1.0f;
	for (auto &[key, val] : m)   //uses structured binding
	{
		if (val.type() == typeid(int))
			cout << "int: " << any_cast<int>(val) << endl;
		else if (val.type() == typeid(string))
			cout << "string: " << any_cast<string>(val) << endl;
		else if (val.type() == typeid(float))
			cout << "float: " << any_cast<float>(val) << endl;
	}

	return 0;
}