#include<iostream>
#include<vector>
#include<thread>
#include<future>

using namespace std;

class ThreadCollection
{
private:
    vector<thread> v1;
public:
    ThreadCollection(){}    
    ~ThreadCollection()
    {
        for(auto& x:v1)
        {
            if(x.joinable())
                x.join();
        }
    }

    template<typename... PACK> void AddTask(PACK&& ...Args)
    {
        (v1.push_back(thread(std::move(Args))),...);
    }
};

//**consumer code*****************
int main()
{
    ThreadCollection MyThreads;
    auto lm1 = []()
    {
        auto x=100;
        cout << "task-1 ";
        return x;
    };

    auto lm2 = []()
    {
        auto x=200;
        cout << "task-2 ";
        return x;
    };

    packaged_task<int(void)> task1(lm1);
    auto result1 = task1.get_future();

    packaged_task<int(void)> task2(lm2);
    auto result2 = task2.get_future();

    MyThreads.AddTask(task1, task2);
    cout << result1.get() << endl;
    cout << result2.get() << endl;

    return 0;
}