#include<iostream>
#include<iomanip>
using namespace std;

template <typename T> constexpr T Euler_constant = T(2.7182818284590452353602874713527);


int main()
{
    cout << "Euler_constant<int> :" << setprecision(4) << Euler_constant<int> << endl;
    cout << "Euler_constant<float> :" << setprecision(4) << Euler_constant<float> << endl;
    cout << "Euler_constant<double> :" << setprecision(8) << Euler_constant<double> << endl;
    auto val1 = Euler_constant<float>;
    cout <<  "val1 =" << setprecision(3) << val1 << endl;
    return 0;
}