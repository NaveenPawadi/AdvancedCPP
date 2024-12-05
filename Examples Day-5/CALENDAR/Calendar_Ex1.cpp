#include<iostream>
#include<chrono>
using namespace std;

int main()
{
    chrono::day d{1};
    chrono::month m{12};
    chrono::year y{2024};

    cout << std::format("{}/{}/{}\n",d,m,y);
    cout <<"-------------------"<<endl;

    chrono::month m2{chrono::June};   
    chrono::year y2{2024};

    chrono::year_month_day ym{y2/m2/chrono::last};
    cout <<"ym = " << ym << endl;
    return 0;
}