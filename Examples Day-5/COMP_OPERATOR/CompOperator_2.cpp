#include<iostream>
#include<vector>
using namespace std;

int main()
{
    //vector v1{10,20,30,40};
    //vector v2{10,20,30,40};

    //vector v1{10,20,30,40};
    //vector v2{10,20,60,40};

    vector v1{50,20,30,40};
    vector v2{10,20,30,40};
    auto result = v1 <=> v2;
    if(result > 0)
    {
        cout <<"v1 is greater than v2" << endl;
    }
    if(result < 0)
    {
        cout <<"v1 is less than v2" << endl;
    }
    if(result == 0)
    {
        cout <<"v1 is equal to v2" << endl;
    }
    return 0;
}