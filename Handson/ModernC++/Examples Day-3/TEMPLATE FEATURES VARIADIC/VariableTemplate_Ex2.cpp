#include<iostream>
#include<iomanip>
#include<sstream>

using namespace std;

template <typename T> constexpr T Euler_constant = T(2.7182818284590452353602874713527);

int main()
{
    std::stringstream vals;

    vals  << setprecision(3) << Euler_constant<float>;
    auto value = std::stof(vals.str());

    cout <<"data type of value=" << typeid(value).name() <<",its value =" << value <<endl;
    
    return 0;
}