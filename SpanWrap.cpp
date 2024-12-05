#include<iostream>
#include<vector>
#include<span>

using namespace std;

template<typename T> class SpanWrap:public std::span<T>  //Bounds check for subspan() member function
{
  
public:
    using std::span<T>::span;  //Inherit the base class std::span constructors - C++11

   std::span<T> sub_span(size_t start, size_t element_count)
    {
        if (element_count >= start)
        {
            size_t requested_span = this->size();
            size_t limit = requested_span - start;
            if ((start < requested_span) && (element_count <= limit))
            {
                return this->subspan(start, element_count);
            }
            else
            {
                cout <<"Element count "<< element_count <<"-Invalid, max available :"  << limit << endl;
                return this->subspan(0,0);
            }
        }
        else
        {
            cout <<"start index " << start << " is invalid..." << endl;
            return this->subspan(0,0);
        }
    }
    
    
//consumer code
int main()
{
    vector<int> v1{10, 20, 30, 40, 50, 60, 70, 80, 90, 100};

    // SpanWrap<int> sw1(v1);
    // auto result = sw1.sub_span(4, 70);
    // for(auto x: result)
    // {
    //     cout << x <<",";
    // }
    // cout << endl;

    

    int arr[]={1,2,3,4,5,6,7,8,9,10};
    
    SpanWrap<int> sw2(arr);
    auto s2 = sw2.sub_span(30,6);
    for(auto x: s2)
    {
        cout << x <<",";
    }

    cout << endl;
    return 0;
}