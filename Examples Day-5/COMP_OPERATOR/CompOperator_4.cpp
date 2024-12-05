#include <compare>
#include <iostream>
using namespace std;

class Point {
  int x;
  int y;
  public:
    Point(int x, int y):x(x), y(y){}
  auto operator<=>(const Point&) const = default;
};

int main() {
  Point p1(2, 2), p2(4, 3);
  
  cout << boolalpha << (p1 == p2) << endl; // false
  cout << (p1 != p2) << endl; // true
  
  cout << (p1 <  p2) << endl; // true
  cout << (p1 <= p2) << endl; // true
  cout << (p1 >  p2) << endl; // false
  cout << (p1 >= p2) << endl; // false
  
  return 0;
}
