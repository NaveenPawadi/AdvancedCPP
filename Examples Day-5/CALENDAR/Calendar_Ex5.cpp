#include <iostream>
#include <chrono>

using namespace std;
//using namespace std::chrono;

int main()
{
    const auto& timeZoneDatabase = chrono::get_tzdb();
    const auto& currentZone = timeZoneDatabase.current_zone();
    
    auto systime = chrono::system_clock::now();
    chrono::local_time<chrono::system_clock::duration> lt = currentZone->to_local(systime);

    cout << "local_time: " << lt << "\n";
    cout << "system_time: " << systime << "\n";
    return 0;
}