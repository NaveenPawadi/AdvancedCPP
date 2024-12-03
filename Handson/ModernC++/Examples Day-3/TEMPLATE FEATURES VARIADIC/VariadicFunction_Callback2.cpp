#include<iostream>

using namespace std;

/*
    RET_TYPE        - Indicates the return-type of the function
    FUNCTION_FORM      - stands for the function form
    PARAMETERS ...  - represent the input arguments the function is supposed to take
*/

template<typename FUNCTION_FORM, typename... PARAMETERS> void U_Callback(FUNCTION_FORM x, PARAMETERS ...Args)
{
    cout <<"Common business started..." << endl;
    (*x)(Args...);
    cout <<"Common business completed..." << endl;
    cout <<"---------------------" << endl;
}

template<typename RET_TYPE, typename FUNCTION_FORM, typename... PARAMETERS> RET_TYPE U_Callback(FUNCTION_FORM x, PARAMETERS ...Args)
{
    cout <<"Common business started..." << endl;
    auto result = (*x)(Args...);
    cout <<"Common business completed..." << endl;
    cout <<"---------------------" << endl;
    return result;
}
//***consumer code***********
void fun1(float x, double y){cout <<"fun1(float,double) called, x="<< x << ",and y=" << y<< endl;}
void fun2(int x){cout <<"fun2(int) called, x=" << x << endl;}
int  fun3(){cout <<"fun3() called" << endl; return 500; }

int main()
{
    U_Callback(&fun1, 56.12f, 88.34);     // U_Callback(void(*x)(float,double),56.12f, 88.34);
    U_Callback(&fun2, 200);               // U_Callback(void(*x)(int),200);
    cout << U_Callback<int>(&fun3) << endl;     // U_Callback(int(*x)(void));

    return 0;

}

