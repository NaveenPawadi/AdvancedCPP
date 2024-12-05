#include<iostream>
#include<memory>
using namespace std;

class CA
{
private:
    int a, b;
public:
    CA() :a(0), b(0) { cout << "CA default constructor..." << endl; }
    CA(int x) :a(x), b(x) { cout << "CA one arg. constr." << endl; }
    CA(int x, int y) :a(x), b(y) { cout << "CA two arg. constructor" << endl; }
    ~CA() { cout << "CA destructor " << endl; }

    void print() { cout << "CA-print, a=" << a << ",b=" << b << endl; }
};

//consumer code
int main()
{
    shared_ptr<CA[]> ptr = make_shared<CA[3]>();
    ptr[0].print();
    return 0;
}