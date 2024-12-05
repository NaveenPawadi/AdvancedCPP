#include<iostream>
#include<thread>
#include<mutex>
#include<condition_variable>
#include<vector>
#include<algorithm>
using namespace std;

class Semaphore
{
private:
    int Current_index{0};
    bool ready{false};

    std::mutex mx;
    std::condition_variable con_var;
public:
    void Wait_on_Condition(int index, int max_count)
    {
        unique_lock<mutex> u_lock(mx);
        //If 'index' does not match 'current_index' the thread waits..
        cout <<"Waiting on index... " << index+1 << endl;
        while(index != Current_index || !ready)
        {
          con_var.wait(u_lock);
        }
        
        Current_index++;
        cout <<"Received Notification for index ..." << Current_index << endl;
        cout <<"Thread: " << index+1 <<"/" << max_count <<endl;
        cout <<"----------------------------" << endl;
        con_var.notify_all();
    }

    void operator()()
    {
        unique_lock<mutex> ul(mx);
        ready = true;
        con_var.notify_all();
        cout <<"Initiating Notification for waiting threads..." << endl;
    }
};

//****consumer code **************
int main()
{
    Semaphore S_obj1;

    constexpr int threadcount = 10;
    auto lm = [&](int n) {S_obj1.Wait_on_Condition(n, threadcount); };
    
    vector<thread> v1;
    
    for(int index =0; index < threadcount; index++)
    {
        v1.push_back(thread(lm,index));
    }

    cout <<"Parallely spawning " << threadcount << " threads.." << endl;
    S_obj1();

    for_each(v1.begin(),v1.end(),[](thread &th){th.join();});  //thread barrier...
    
    cout << endl << "Done..." << endl;
    
    return 0;
}