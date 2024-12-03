#include<iostream>
#include<vector>
#include<array>
using namespace std;

void Approach_1()
{
    //**********APPROACH-1********************

    // define a c++14 generic lambda
    auto generic_lambda = [](auto x)
    {
        for (auto val : x)
        {
            cout << val << ",";
        }
        cout << endl;
    };

    vector<int> v1 = {10, 20, 30, 40, 50, 60};
    array<char, 5> ar1 {{'a', 'b', 'c', 'd', 'e'}};
    generic_lambda(ar1);
    generic_lambda(v1);
}

void Approach_2()
{
    //**********APPROACH-2********************

    auto generic_lambda = [](auto x)
    {
        for (auto val : x)
        {
            cout << val << ",";
        }
        cout << endl;
    };

    // auto val1 = 200;
    // auto val2 = 45.12f;
    // generic_lambda(val1);
    // generic_lambda(val2);
}

//**********************
template<typename T> struct is_range_type: std::false_type{};
template<typename T> struct is_range_type<vector<T>>: std::true_type{};
template<typename T> struct is_range_type<array<T, 5>>: std::true_type{};

void Approach_3()
{
    //**********APPROACH-3********************

    /*
        As an author of the lambda expression, we would like to
        ensure or assert during compile time that the formal parameter 
        is a collection type only.
    */

    auto generic_lambda = [](auto x)
    {
        static_assert(is_range_type<decltype(x)>::value);
        for (auto val : x)
        {
            cout << val << ",";
        }
        cout << endl;
    };

    // auto val1 = 200;
    // auto val2 = 45.12f;
    // generic_lambda(val1);
    // generic_lambda(val2);

    vector<int> v1 = {10, 20, 30, 40, 50, 60};
    array<char, 5> ar1 {{'a', 'b', 'c', 'd', 'e'}};
    generic_lambda(ar1);
    generic_lambda(v1);
}

//C++20 - Lambda with template parameter to the foray
void Approach_4()
{
    // A template lambda

    auto temp_lambda1 = []<typename T>(std::vector<T>& x)
    {
        for (auto val : x)
        {
            cout << val << ",";
        }
        cout << endl;
    };

    auto temp_lambda2 = []<typename T>(std::array<T, 5>& x)
    {
        for (auto val : x)
        {
            cout << val << ",";
        }
        cout << endl;
    };
    // auto val1 = 200;
    // auto val2 = 45.12f;
    // temp_lambda1(val1);
    // temp_lambda1(val2);

    // vector<int> v1 = {10, 20, 30, 40, 50, 60};
    // array<char, 5> ar1 {{'a', 'b', 'c', 'd', 'e'}};
    // temp_lambda1(v1);
    // temp_lambda2(ar1);
}
int main()
{
    Approach_1();
    //Approach_2();
    //Approach_3();

    //Approach_4();

    return 0;
}