#include<iostream>
#include<thread>
#include<atomic>
#include<memory>
using namespace std;

class CA
{
private:
    int a=0;
public:
    CA()=default;
    CA(int x):a(x){ cout <<"CA constructor..." << endl;}
    void print() const {cout <<"a = " << a << endl;}
    ~CA() {cout <<"CA destructor.." << endl;}
    int operator->(){return a;}
};

//global shared_ptr instance to be shared across functions and threads
std::atomic<shared_ptr<CA>> global_ptr;

void Func_store(int x)
{
    std::shared_ptr<CA> local_ptr(new CA(x));
    global_ptr.store(local_ptr);
    cout <<"Func_store, is local_ptr lock free ?" << std::boolalpha << local_ptr.is_lock_free() << endl;
}

void Func_load()
{
    std::atomic<shared_ptr<CA>> local_ptr = global_ptr.load();
    cout <<"Func_load, is local_ptr lock free ?" << std::boolalpha  << local_ptr.is_lock_free() << endl;
    (global_ptr.load())->print();
}
int main()
{
    Func_store(100);
    Func_load();

   
    return 0;
}