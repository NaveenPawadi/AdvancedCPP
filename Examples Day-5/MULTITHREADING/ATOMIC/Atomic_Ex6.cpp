#include<iostream>
#include<atomic>
using namespace std;

class Counter
{
private:
    std::atomic<unsigned int> Count{0};
public:
    Counter()=default;
    unsigned operator ++(int)
    {
        return Count.fetch_add(1);
    }
    
    unsigned operator --(int)
    {
        return Count.fetch_sub(1);
    }
};

//consumer code
int main()
{
    Counter ob1;
    cout << "Value prior to, ob1++ ..." << ob1++ << endl;
    cout << "Value prior to, ob1++ ..." << ob1++ << endl;
    cout <<"----------------" << endl;
    cout << "Value prior to, ob1-- ..." << ob1-- << endl;
    cout << "Value prior to, ob1-- ..." << ob1-- << endl;

    return 0;
}