#include<iostream>
#include<tuple>
#include<string>
using namespace std;

class Myclass1
{
    int x;
    string s;
public:
    //Myclass1()=default;
    Myclass1(int a, string str):x(a), s(move(str)){}
    void print() const{cout <<"Myclass1 - x:" << x <<",s=" << s << endl;}
    decltype(auto) Get(){return make_tuple(x,s);}
};


class Myclass2
{
    int x;
    string s;
public:
    //Myclass2() = default;
    Myclass2(int a, string str):x(a), s(move(str)){}
    void print() const{cout <<"Myclass2 - x:" << x <<",s=" << s << endl;}
    decltype(auto) Get(){return make_tuple(x,s);}
};

int main()
{
    Myclass1 ob1(100,"First");
    Myclass2 ob2(200,"Second");
    auto tup_info = make_tuple(ob1,ob2);
    //Myclass1 obj1; Myclass2 obj2;
    //std::tie(obj1,obj2) = tup_info;
    //obj1.print();
    //obj2.print();
    const auto& [a,str1] = ob1.Get();
    const auto& [b,str2] = ob2.Get();
    cout <<"a:" << a <<",str1:" << str1 << endl;
    cout <<"b:" << b <<",str2:" << str2 << endl;
    return 0;
}