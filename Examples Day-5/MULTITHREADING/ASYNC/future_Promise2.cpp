#include<iostream>
#include<thread>
#include<future>
#include<exception>
using namespace std;

void Write_info(std::promise<int>& pm)
{
    int x;
    cout <<"Enter an integer value " << endl;
    try
    {
        cin >> x;
        if (x <= 0)
        {
            throw std::runtime_error("value not positive");
        }
        else
        {
            pm.set_value(x);
        }
    }
    catch(const std::exception& e)
    {
       pm.set_exception(std::current_exception());
    }
}

void Read_info(std::future<int>& ft)
{
    try
    {
        int x = ft.get();
        cout <<"value :" << x << endl;
    }
    catch(const std::exception& e)
    {
        std::cerr <<"Exception caught: "<< e.what() << '\n';
    }
    
}

int main()
{
    std::promise<int> prm;
    std::future<int> ftr = prm.get_future();

    thread th1(Write_info,std::ref(prm));
    thread th2(Read_info, std::ref(ftr));

    th1.join();
    th2.join();

    return 0;
}