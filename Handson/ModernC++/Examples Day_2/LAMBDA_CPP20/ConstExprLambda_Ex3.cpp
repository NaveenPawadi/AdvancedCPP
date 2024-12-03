#include<iostream>
using namespace std;

template<typename T> constexpr auto Compute1(T x)
{
	return [=](auto y) constexpr
	{
		return x + y;
	};
}


int main()
{
    constexpr auto lm1 = Compute1(100);
    constexpr auto result1 = lm1(200);
    cout <<"result1 = " << result1 << endl;

    int a=100;
    auto lm2 = Compute1(a);   //Run-time evaluation
    auto result2 = lm2(400);
    cout <<"result2 = " << result2 << endl;


    constexpr auto lm3 = Compute1(100);
    cout << lm3(500) << endl;
	// static_assert(lm1(10) == 110);

    return 0;
}