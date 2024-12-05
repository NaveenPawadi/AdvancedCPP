#include<iostream>
#include <array>
#include <algorithm>
using namespace std;
//C++17
int main() 
{
	std::array<int, 4> numbers = {13, 2, 7, 4};
	// Content: 13,2,7,4
	std::sort(numbers.begin(), numbers.end());
	// Content: 2,4,7,13
    for(auto num:numbers)
    {
        cout << num <<",";
    }
    cout << '\n';
    return 0;
}