#include <iostream>

class predicate
{
public:
  bool operator()(int val) const { return val == 10; }
};
  
int main()
{
  predicate p;
  std::cout << (p(2) ? "true" : "false") << std::endl;     // will output "false"
  return 0;
}

