#include <iostream>
#include <array>
#include <algorithm>

template <typename T, size_t N1, size_t N2>
auto concat(std::array<T, N1> const& lhs, std::array<T, N2> const& rhs)
{
	namespace rg = std::ranges;

	std::array<T, N1 + N2> result;

	rg::copy(lhs, result.begin());    // lhs array --> beginning of result array
	rg::copy_backward(rhs, result.end());  // rhs array --> end of result array

	return result;
}

int main()
{
	auto left	= std::to_array({10, 20, 30});   //C++20
	auto right	= std::to_array({40, 50, 60,70});
	
	auto both	= concat(left, right);

	for (int elem : both)
	std::cout << elem << ' ';
  /*
  int a[] ={10,20,30,40,50};
  auto arr = to_array(a);         // std::array arr<int, 5> =...;
  */
  return 0;
}