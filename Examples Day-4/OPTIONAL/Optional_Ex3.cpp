#include<iostream>
#include<optional>
using namespace std;

//swapping of optional type instances
int main()
{
    std::optional<int> opt1{100}, opt2{200};
    cout <<"before swap," << endl;
    cout <<"opt1 --> " << opt1.value_or((-1)) << endl;
    cout <<"opt2 --> " << opt2.value_or(-1) << endl;
    cout <<"-------------------" << endl;

    std::swap(opt1, opt2);
    //opt1.reset();
    cout <<"After swap," << endl;
    cout <<"opt1 --> " << opt1.value_or(-1) << endl;
    cout <<"opt2 --> " << opt2.value_or(-1) << endl;

    return 0;
}