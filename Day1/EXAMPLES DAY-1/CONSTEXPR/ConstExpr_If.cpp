#include<iostream>
using namespace std;
class CA
{
public:
	int a;
	float b;
	double c;
public:
	CA(int x, float y, double z) :a(x), b(y), c(z) {}
	//  C++11/14  - will not compile, as all return types should yield same datatype
	/*template<size_t index> auto& get()
	{
		if  (index == 0)
			return a;
		else if (index == 1)
			return b;
		else if (index == 2)
			return c;
	}*/

    //As member function - C++17 onwards
	template<size_t index> auto& get()
	{
		if constexpr (index == 0)
			return a;
		else if constexpr (index == 1)
			return b;
		else if constexpr(index == 2)
			return c;
	}
    
};


//Also as global/free function - C++17 onwards
/*
template<size_t index> auto& get(CA& ob)  
{
	if constexpr (index == 0)
		return ob.a;
	else if constexpr (index == 1)
		return ob.b;
	else if constexpr (index == 2)
		return ob.c;
}
*/

int main()
{
	CA obj1(100, 12.34f, 78.54);
	cout << obj1.get<0>() << endl;
	//cout << get<0>(obj1) << endl;
	return 0;
}