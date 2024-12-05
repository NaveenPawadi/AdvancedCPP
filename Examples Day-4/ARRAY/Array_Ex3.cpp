#include<iostream>
#include <array>
#include <algorithm>
using namespace std;
// C++20 - uses to_array function to create array instance and
// and ranges library for sorting

int main() 
{
	//std::array<int, 4> numbers = {13, 2, 7, 4};
    auto numbers = std::to_array({13, 2, 7, 4});
	// Content: 13,2,7,4

	std::ranges::sort(numbers);
	// Content: 2,4,7,13

    for(auto num:numbers)
    {
        cout << num <<",";
    }
    cout << '\n';
    return 0;
}