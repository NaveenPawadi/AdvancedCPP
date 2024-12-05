#include<iostream>
#include<atomic>

using namespace std;
/*
    * std::atomic<T*> type has additional behaviours than atomic<bool> type with
      memory ordering support, the foll: functions carry out a read/modify/write operation.
        - fetch_add()  //atomic addition on the stored address, returns the old address
        - fetch_sub()  //atomic subtraction on the stored address, returns the old address
        
    * Also provides operator overloaded wrappers...[but,memory ordering tags not allowed]
        :  +=
        :  -=
        :  ++
        :  -- 
*/


class CA
{
private:
    int a=0;
public:
    CA()=default;
    CA(int x):a(x){ }
    void print() const{cout <<"a =" << a << endl;}
};

void fun1(std::atomic<CA*> p1)
{
    CA* x = p1.fetch_add(2);
    (*x).print();
    
    x = p1.fetch_add(0);
    (*x).print();
}

void fun2(std::atomic<CA*> p1)
{
    (*p1).print();
    ++p1;
    (*p1).print();
    p1 += 2;
    (*p1).print();
    --p1;
    (*p1).print();

}


//consumer code
int main()
{
    CA arr[5]{{100},{200},{300},{400},{500}};
    fun1(arr);
    cout <<"-----------------" << endl;
    fun2(arr);
   
    return 0;
}