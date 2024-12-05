#include<iostream>
using namespace std;

class CA
{
private:
    int a;
public:
    CA(int x=0):a(x) {}
    bool operator <(CA& x)   {  return this->a < x.a;    }
    bool operator >(CA& x)    { return this->a > x.a;    }
    bool operator ==(CA& x) { return this->a == x.a;}
    bool operator <=(CA& x) {return this->a <= x.a;}
    bool operator >=(CA& x) {return this->a >= x.a;}
    bool operator !=(CA& x) {return this->a != x.a;}
};

class CB
{
private:
    int a;
public:
    CB(int x=0):a(x){ }
    auto operator <=>(const CB& x) 
    {
        return this->a <=> x.a;
    }
    //auto operator <=>(const CB &x) const = default;    
};
//consumer code
int main()
{
    CA ob1(10),ob2(20);
    if(ob1 < ob2)
    {
        cout <<"ob1 is less than ob2"<< endl;
    }
    if(ob1 > ob2)
    {
        cout <<"ob1 is greater than ob2"<< endl;
    }
    if(ob1 == ob2)
    {
        cout <<"ob1 is equal to ob2"<< endl;
    }
    cout <<"=====================" << endl;
    CB ob3(40), ob4(20);
    auto result2 = ob3 <=> ob4;
    if(result2 < 0)
    {
        cout <<"ob3 is less than ob4"<< endl;
    }
    if(result2 > 0)
    {
        cout <<"ob3 is greater than ob4"<< endl;
    }
    if(result2 == 0)
    {
        cout <<"ob3 is equal to ob4"<< endl;
    }
    cout <<"--------------------" << endl;
    auto result3 =  (ob3 <= ob4);
    cout << std::boolalpha << result3 << endl;
    return 0;
}