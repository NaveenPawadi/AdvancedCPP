#include<iostream>
using namespace std;

struct PlanA
{
    int a=10;
    float b=20.32f;
};

struct PlanB
{
    struct PlanC
    {
        double d=56.21;
    };
    int a=10;
    float b=20.32f;
    
};

//***consumer code****
int main()
{
    cout <<"size of PlanB:" << sizeof(PlanB) << endl;
    cout <<"size of PlanC:" << sizeof(PlanB::PlanC) << endl;
    PlanA pl;
    auto[x,y] = pl;
    cout << x <<"," << y << endl;
    cout <<"------------------" << endl;
    PlanB pl2;
    auto[x1,y1] = pl2;
    PlanB::PlanC pl3;
    auto[z1] = pl3;
    cout << x1 <<"," << y1 <<"," << z1 << endl;
    return 0;
}