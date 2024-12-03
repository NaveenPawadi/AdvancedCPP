#include<iostream>
#include<functional>
using namespace std;

class CA
{
private:
	int max, min;
public:
	CA(int x = 0, int y = 0) :max(x), min(y) { }
	auto getdata()   ->function<int(void)>
	{
		return  [this](){ return max-min; };   //[this] convention only for non-static mem.
		//return  [=](){ return max-min; };
	}
};

void main()
{
	CA obj1(10,20);
	auto lm = obj1.getdata();
	cout << lm() << endl;
}