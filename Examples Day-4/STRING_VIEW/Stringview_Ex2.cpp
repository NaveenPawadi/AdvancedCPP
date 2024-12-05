#include <string>
#include <iostream>
#include <vector>
#include<string_view>
using namespace std;
//C++20 - starts_with, ends_with members
int main()
{
    std::string str("the quick brown fox jumps over the lazy dog");
    bool t1 = str.starts_with("the quick"); // const char* overload
    // t1 == true
    bool t2 = str.ends_with('g'); // char overload
    // t2 == true

    std::string_view needle = "lazy dog";
    string_view view2 = str;
    cout <<"string_view view2 " << view2 << endl;
    bool t3 = str.ends_with(needle); // string_view overload
    // t3 == true

    std::string_view haystack = "you are a lazy cat";
    // both starts_with and ends_with also available for string_view
    bool t4 = haystack.ends_with(needle);
    // t4 == false
    return 0;
}
