#include<iostream>
using namespace std;
//C++17 feature
int main()
{
	auto lm2 = [](int n) constexpr
	{
		return n;
	};

	auto result1 = lm2(10);          // auto result1 = 10;
	cout <<"result1 =" << result1 << endl;
	int a;
	cout <<"enter a value:" << endl;
	cin >> a;
	auto result2 = lm2(a);          // A lambda call, with input 'a'
	cout <<"result2 =" << result2 << endl;
	static_assert(lm2(250) == 250);
	
	//static_assert(lm2(a) == 250);

	return 0;
}