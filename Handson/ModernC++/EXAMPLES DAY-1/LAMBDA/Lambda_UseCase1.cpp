#include<iostream>
#include<list>
#include<algorithm>
using namespace std;
/*
    Now all STL algorithms have been tweaked to support lambda handles as 
    parameters as against a global function address or a functor member function of a class.

    Since, lambda are supposed to highly optimized code by the compiler, any function call
    employed its body, can be hypothetically seen as a direct call to the desired 
    member function.

*/
class CA
{
private:
    int a,b;
public:
    CA(int x=0, int y=0):a(x),b(y)
    {cout <<"parameterized int constructor "<< endl;}
    CA(const CA& x):a(x.a),b(x.b)
    {cout <<"CA-copy constructor "<< endl;}
    ~CA(){cout <<"CA destructor.."<< endl;}
    /*
        These member functions can be invoked directly thru the lambda functions,
        without depending a global wrapper function or a FUNCTOR
    */
    void print() const{cout <<"a ="<< a <<",b="<< b << endl;}
    void fun1(){cout <<"CA fun1 called" << endl;}
    void fun2(){cout <<"CA fun2 called" << endl;}
};
//***************************


//consumer code
int main()
{
    list<CA> ls1;
    //populate the list
    for(int i=1;i<=5;i++)
    {
        ls1.push_back(CA(i, i+10));
    }
    //**************TRADITIONAL APPROACHES**************
    /*
    //******************* APPROACH-1 ***************************
    //traverse the list
    list<CA>::iterator itr = ls1.begin();
    while(itr != ls1.end())
    {
        itr->print();
        itr ++;
    }
    cout << endl;
    //*************** APPROACH-2 *************************
    for_each(ls1.begin(), ls1.end(), Print);
    cout << endl;
    //*************** APPROACH-3 *************************
    //directly map to the functor member function of the class thru algorithm's
    CA ob1;
    for_each(ls1.begin(), ls1.end(), ob1);
                                 //, ob1.operator()(object_from_ls1)
    cout << endl;
    */

   //************* MODERN APPROACH *******************
    auto print = [](CA &ob)
    {
        ob.print();
    };

    auto fun1 = [](CA &ob)
    {
        ob.fun1();
    };

    auto fun2 = [](CA &ob)
    {
        ob.fun2();
    };

    for_each(ls1.begin(), ls1.end(), print);
    cout <<"------------------------" << endl;
    for_each(ls1.begin(), ls1.end(), fun1);
    cout <<"------------------------" << endl;
    for_each(ls1.begin(), ls1.end(), fun2);
    cout <<"------------------------" << endl;
    //an alternate approach, defining the lambda directly as a parameter to for_each
    for_each(ls1.begin(), ls1.end(),[](CA &ob){ ob.fun2();});
    
    return 0;
}