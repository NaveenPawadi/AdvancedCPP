#include<iostream>
#include<thread>
#include<mutex>
#include<condition_variable>

using namespace std;

mutex mx;
condition_variable con_var;

bool ready{false};
auto current_index{0};

void Print(int index, int max_count)
{
    unique_lock<mutex> u_lock(mx);
    //If 'index' does not match 'current_index' the thread waits..
    while(index != current_index || !ready)
    {
        con_var.wait(u_lock);
    }
    current_index++;

    cout <<"Thread: " << index+1 <<"/" << max_count <<endl;
    cout <<"current index is :"<<current_index <<endl;
    cout <<"----------------------------" << endl;
    con_var.notify_all();
}

/* Sets 'ready' flag to true and initiates the 'Print' threads */

void Trigger_Threads()
{
    unique_lock<mutex> ul(mx);
    ready = true;
    con_var.notify_all();
}


int main()
{
    constexpr int threadcount = 10;
    thread thread_array[threadcount];
    //spawn the threads
    for(int index =0;index<threadcount;index++)
    {
        thread_array[index] = thread(Print,index,threadcount);
    }

    cout <<"Parallely spawning " << threadcount << " threads.." << endl;
    Trigger_Threads();

    // Thread Barrier - all child threads fork back to the parent thread
    for(int index =0;index<threadcount;index++)
    {
        thread_array[index].join();
    }
    cout << endl << "Done..." << endl;
    return 0;
}
