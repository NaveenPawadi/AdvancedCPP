#include<iostream>
#include<chrono>
#include<iomanip>
using namespace std;

int main()
{
    auto zone_names = 
    {
        "Asia/Tokyo",
        "Asia/Hong_Kong",
        "Europe/Bucharest",
        "Europe/London",
        "America/New_York",
        "Pacific/Honolulu"
    };

    for(auto const& name:zone_names)
    {
        const chrono::zoned_time zt{name, chrono::system_clock::now()};
        cout <<setw(25) << name << " - zoned time : " << zt << endl;
    }
    return 0;
}