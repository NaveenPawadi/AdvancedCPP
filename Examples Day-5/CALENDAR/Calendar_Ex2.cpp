#include<iostream>
#include<chrono>
using namespace std;

//weekday_indexed
int main()
{
    chrono::day d{24};
    chrono::month m{06};
    chrono::year y{2024};

    chrono::year_month_day dt = d/m/y;

    chrono::weekday wday{dt};
    cout << std::format("weekday of {} is {}\n",dt,wday);
    
    cout <<"----------------" << endl;

    chrono::weekday_indexed wdi = chrono::Saturday[4];
    chrono::year_month_day dt2{2024y/chrono::June/wdi} ;
   
    cout << format("{} of June 2024 is {}",wdi, dt2) << endl;
    
    cout <<"------------------" << endl;
    //Different ways to initialize a year_month_day objects
    chrono::year_month_day date_1{2024y/chrono::February/21d};
    chrono::year_month_day date_2{chrono::March/20d/2024y};

    cout << "date_1 =" << date_1 << endl;
    cout << "date_2 =" << date_2 << endl;

    //Last day of a particular year and month
    chrono::year_month ym{2024y/chrono::June};
    chrono::year_month_day_last ylast{ym/chrono::last};
    cout <<"ylast =" << ylast << endl;
    return 0;
}