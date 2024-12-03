#include<iostream>
#include<vector>
using namespace std;

//an example on C++20 'concept' keyword

//We introduce the 'C++20 concept' to provide a much more concise error message.
//Define the concept
template<typename T> concept Is_Streamable = requires(std::ostream& st, const T& msg)
{
    {st << msg};
};

//Let us re-define the traditional function template, that uses the above define concept.
template<Is_Streamable T> void PrintModern(const T& msg)
{
    cout << msg << endl;
}
//***consumer code**************
int main()
{
    PrintModern(100);
    PrintModern(45.12f);
    PrintModern("a string");
    // The foll: statement should issue an error, 
    //no 'operator >>' support for 'v1' in a concise fashion on the consumer end.
    vector<int> v1 ={10,20,30,40};
    PrintModern(v1);
    return 0;
}