#include<iostream>
#include<chrono>
using namespace std;

int main()
{
    std::chrono::year_month ym=2024y/06;
    
    ym+=chrono::months(12);
    cout << ym << endl;
    cout <<"ym+=chrono::months(12) --> " << ym << endl;
    cout << ym << endl;
    ym+=chrono::years(10);
    cout <<"ym+=chrono::years(10) --> " << ym << endl;
    cout <<"----------------------" << endl;
    cout <<"---All days---------" << endl;
    for (int i = 1; i < 8; i++)
    {
        /* code */
        cout << chrono::weekday(i) << endl;
    }
    cout <<"---All months---------" << endl;
    for (int i = 1; i < 13; i++)
    {
        /* code */
        cout << chrono::month(i) << endl;
    }
    
    
    return 0;
}