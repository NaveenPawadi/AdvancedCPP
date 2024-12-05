#include<iostream>
#include<tuple>
using namespace std;

class CA
{
private:
    int a=10,b=20;
public:
    auto Get_format(); 

    class CB
    {
        friend class CA;

        private:
        float c=12.34f;
        double d=78.52;
        public:
        auto Get_format();
    };
};

//---------------

auto CA::Get_format()
{
    CB ob2;
    return make_tuple(this->a, this->b, ob2.c,ob2.d);
}

auto CA::CB::Get_format()
{
    CA ob1;
    return make_tuple(ob1.a, ob1.b, this->c, this->d);
}
//------consumer code ----------
int main()
{
    CA obj1;
    CA::CB obj2;

    auto[x1,x2,x3,x4]=obj1.Get_format();
    auto[y1,y2,y3,y4]=obj2.Get_format();
    cout <<"[" << x1<<"," << x2<<"," << x3 <<"," <<x4 << "]" << endl;
    cout <<"[" << y1<<"," << y2<<"," << y3 <<"," <<y4 << "]" << endl;
    return 0;
}
