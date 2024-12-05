#include<iostream>
#include<chrono>
using namespace std;


//Print all the second saturdays for a given year

void saturdays_in_Year(chrono::year& y)
{
    for(int i=1;i<=12;i++)
    {
        chrono::year_month_weekday second_sat{i/chrono::Saturday[2]/y};
        chrono::year_month_day ymd{chrono::sys_days{second_sat}};

        cout << ymd.month() <<"-->" << ymd.day() << endl;
    }
    
}

int main()
{
    chrono::year yr{2024y};
    saturdays_in_Year(yr);

    return 0;
}