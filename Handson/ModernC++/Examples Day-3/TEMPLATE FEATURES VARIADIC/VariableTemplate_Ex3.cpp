#include<iostream>
#include<iomanip>
#include<sstream>

using namespace std;

template <typename T> constexpr T Euler_constant = T(2.7182818284590452353602874713527);

template<typename T> auto Euler(int precision=0)
{
    std::stringstream vals;
    vals  << setprecision(precision) << Euler_constant<int>;
    return std::stoi(vals.str());
}

template<> auto Euler<double>(int precision)
{
    std::stringstream vals;
    vals  << setprecision(precision) << Euler_constant<double>;
    return std::stod(vals.str());
}

template<> auto Euler<float>(int precision)
{
    std::stringstream vals;
    vals  << setprecision(precision) << Euler_constant<float>;
    return std::stof(vals.str());
}

//----consumer code--------------------

int main()
{
    auto result1 = Euler<float>(3);
    cout <<"data type of result1=" << typeid(result1).name() <<",its value =" << result1 <<endl;
    
    auto result2 = Euler<double>(5);
    cout <<"data type of result2=" << typeid(result2).name() <<",its value =" << result2 <<endl;

    auto result3 = Euler<int>();
    cout <<"data type of result3=" << typeid(result3).name() <<",its value =" << result3 <<endl;
    return 0;
}