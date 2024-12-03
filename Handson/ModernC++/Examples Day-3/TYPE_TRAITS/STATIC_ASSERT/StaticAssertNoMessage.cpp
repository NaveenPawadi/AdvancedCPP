#include<iostream>
#include<type_traits>
using namespace std;

    //Earlier C++11/14
	template<typename T> void Add(const T a, const T b)
	{
		static_assert(is_pod<T>::value, "Input parameters must be POD types");
		//....
	}

	//Now C++17
	template<typename T> void Add(const T a, const T b)
	{
		static_assert(is_pod<T>::value);   // Error : static assertion failed
		//....
	}

class CA
{
public:
	CA() {}
};

int main()
{
	Add(CA(), CA());
}