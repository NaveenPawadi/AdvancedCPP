#include<iostream>
using namespace std;

int main()
{
    constexpr auto sum =[](int x, int y)
	{
		auto lambda_x = [=](){return x;};
		auto lambda_y = [=]() {return y;};

		return [=]() {return lambda_x() + lambda_y(); };
	};

	static_assert(sum(10,20)() == 30);

	// int a,b;
	// cout <<"enter 2 nos" << endl;
	// cin >> a >> b;
	// static_assert(sum(a,b)() == 30);
    return 0;
}