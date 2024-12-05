#include<iostream>
#include<string>
#include<string_view>
#include<vector>

using namespace std;

int main()
{
    string s1 ="C++17 string_view example";
    string_view view1 = s1;
    cout << view1 << endl;

    // Importantly, string_views are not necessarily null terminated
    char s2[3] = {'t', 'h', 'e'};
    std::string_view view2(s2, s2 + 3); // OK
    cout << view2 << endl;

    std::vector<char> s3{'a', 'b', 'c'};
    // Can be constructed from any contiguous range of characters
    std::string_view view3(s3.begin(), s3.end());
    cout << view3 << endl;

    view1.remove_prefix(4);
    cout <<"After remove_prefix(4), view1 = " << view1 << endl;

    view1.remove_suffix(4);
    cout <<"After remove_suffix(4), view1 = " << view1 << endl;

    string_view view4 = view1.substr(6,10);
    cout <<"After view1.substr(6,10), view4 = " << view4 << endl;

    return 0;
}