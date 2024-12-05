#include <iostream>
#include <array>
#include <algorithm>
//C++20 - Find minimal value
int main()
{
	namespace rg = std::ranges;

	auto numbers = std::to_array({ 12, 3, 18, 9});
	
	// Find minimal element
	auto minIt = rg::min_element(numbers);
    
	// obtain value:
	auto value = *minIt;
	// find position:
	auto index = std::distance(numbers.begin(), minIt);

	
	std::cout	<< "Min: "			<< value
				<< ", at index: "	<< index
				<< std::endl;
    
    return 0;
}