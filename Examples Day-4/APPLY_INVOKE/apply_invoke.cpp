#include<iostream>
#include<functional>
#include<tuple>
#include<array>
using namespace std;

int fun1(int num1, int num2, int num3)
{
    cout <<"fun1 called..." << endl;
    return num1+num2+num3;
}

class CA
{
public:
    int mem_fun(int x, int y, int z)
    {
        cout <<"CA::mem_fun called" << endl;
        return x+y+z;
    }
};

//consumer code
int main()
{
    //Global function invocation
    //Approach-1
    auto result1 = fun1(1,2,3);
    //Approach-2
    auto fp1 = &fun1;
    auto result2 = (*fp1)(10,20,30);
    cout <<"----------------" << endl;
    //Approach-3
    auto result3 = std::invoke(&fun1, 100,200,300);
    cout <<"----------------" << endl;
    //Class member function invoation
    //Approach-1a
    CA ob1;
    int(CA::*fp)(int, int, int) = &CA::mem_fun;
    auto result4 = (ob1.*fp)(11,12,13);
    cout <<"----------------" << endl;
    //Approach-2a
    auto result5 = std::invoke(&CA::mem_fun, ob1, 22,23,24);
    cout <<"------OUTPUT----------" << endl;
    cout <<"result1 -->" << result1 << endl;
    cout <<"result2 -->" << result2 << endl;
    cout <<"result3 -->" << result3 << endl;
    cout <<"result4 -->" << result4 << endl;
    cout <<"result5 -->" << result5 << endl;
    cout <<"--------------------------------" << endl;
    std::array<int, 3> arr{1000,2000,3000};
    std::tuple<int,int,int> t1{50,60,70};
    /*
        Though the above collection types are holding 
        3 integers each, they cannot be passed as a parameter
        to 'fun1' function.

        This is where "std::apply" helps in overcoming this hurdle.
        The collection type parameter can either be
            - std::tuple
            - std::pair
            - std::array
    */
    //auto result6 = std::invoke(&fun1, arr);  
    //auto result7 = std::invoke(&fun1, t1);

    auto result6 = std::apply(&fun1, arr);  
    auto result7 = std::apply(&fun1, t1);

    cout <<"result6 -->" << result6 << endl;
    cout <<"result7 -->" << result7 << endl;
    cout <<"----------------------" << endl;
    auto result8 = std::apply(fp, tuple_cat(make_tuple(&ob1), arr));
    auto result9 = std::apply(fp, tuple_cat(make_tuple(&ob1), t1));
    cout <<"result8 -->" << result8 << endl;
    cout <<"result9 -->" << result9 << endl;
    return 0;
}

