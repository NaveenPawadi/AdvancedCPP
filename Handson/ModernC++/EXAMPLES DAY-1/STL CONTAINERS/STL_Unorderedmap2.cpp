#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;
class CA
{
private:
    int a,b;
public:
    CA(int=0, int=0);
    CA(const CA&);
    CA& operator =(const CA& );
    void print() const;
    ~CA();
};

CA::CA(int x, int y):a(x),b(y){cout <<"CA parameterized constructor" << endl;}
CA::CA(const CA& x):a(x.a),b(x.b){cout <<"CA copy constructor" << endl;}
CA& CA::operator=(const CA& x)
{ 
    cout <<"assignment " << endl; 
    this->a = x.a; this->b = x.b;
    return *this;
}
void CA::print() const { cout <<"a=" << a <<",b=" << b << endl;}
CA::~CA(){ cout <<"CA destructor" << endl;}

//consumer code
int main()
{
    unordered_map<string, CA> mob;
    mob["A"] = CA(1,10);
    mob["B"] = CA(2,20);
    
    // mob.emplace("A", CA(1,10));
    // mob.emplace("B", CA(2,20));

    mob.insert(pair("D",CA(3,30)));
    for(auto& ob:mob)
    {
        cout <<"key =" << ob.first <<",value : " ;
        (ob.second).print();
        cout << endl;
    }
    return 0;
}