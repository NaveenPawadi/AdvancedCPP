#include<iostream>
using namespace std;
//An example on user-defined literal

long double operator"" _cm(long double x) { return x * 10.0; }
long double operator"" _m(long double x) { return x * 1000; }
long double operator"" _mm(long double x) { return x ; }
long double operator"" _ft(long double x) { return x * 304.8; }

int main()
{
	double height = 3.4_cm;
	cout << "height:" << height << endl;
	cout << 30.0_cm / 10.0_mm << endl;;
	return 0;
}
