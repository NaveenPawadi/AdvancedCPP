#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

std::mutex mx;

class Interrupt:public exception
{
    public:
    const char* what() const noexcept override 
    {return "Interruption requested by thread...";}
};


void fun(int x)
{
    lock_guard<mutex> guard(mx);
    cout <<"************************" << endl;
    cout << "fun execution started...." << endl;

    if (x <= 0)
    {
        cout << "Terminating thread..." << endl;
        throw Interrupt();
    }

    cout << "fun executing statements gracefully without an exception..." << endl;
    cout << "fun execution completed..." << endl;
}

int main()
{
    // try
    // {
    //     fun(0);
    // }
    // catch(const std::exception& e)
    // {
    //     std::cerr << e.what() << '\n';
    // }
    
    // try
    // {
    //     thread th1(&fun, 0);
    //     if (th1.joinable())
    //     {
    //         th1.join();
    //         cout << "Thread 'th1' joined" << endl;
    //     }
    // }
    // catch(const std::exception& e)
    // {
    //     std::cerr << e.what() << '\n';
    // }

    //Wrap the call to 'fun'  in a try-catch block inside of a lambda expression
    //And then spawn the lambda as a seperate thread.

    auto lm =[](int x)
    {
        try
        {
            fun(x);
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
        }
    };

    thread th1(lm, 0);
    cout <<"back in main" << endl;
    
    if(th1.joinable())
        th1.join();

    return 0;
}