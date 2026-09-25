/*
    JOIN NOTES
    0. Once a thread is started we wait for this thread to finish by calling join() function on thread object.
    1. Double join will result into program termination.
    2. If needed we should check thread is joinable before joining. ( using joinable() function)

    DETACH NOTES
    0. This is used to detach newly created thread from the parent thread.
    1. Always check before detaching a thread that it is joinable otherwise we may end up double detaching and 
    double detach() will result into program termination.
    2. If we have detached thread and main function is returning then the detached thread execution is suspended.
*/

#include <iostream>
#include<thread>
#include<chrono>

using namespace std;
using namespace std::chrono;

void print(int x )
{
    while(x-->0){
        cout<<x<<endl;
    }

    //we are asking the thread executing this function to wait for five seconds here
    std::this_thread::sleep_for(chrono::seconds(5));
    cout<<"t1 End";
}

int main (void)
{
    thread t1(print,11);
  
    cout<<"Main Start !";

    //important note: once you have called either join or detach the another one or same cannot be called as the internal state is changed and the join Upul has turned to false
    

    //detaching the threat T1 from the main thread; this will allow the main thread to execute even if the T1 is not complete yet
    if(t1.joinable())
        t1.detach();
    
    //it is mandatory to check if that thread is joinable before joining and detaching it; if it's not the system will crash
    //joining the thread with the main thread; it ask's main thread to wait till the thread t1 completes
    if(t1.joinable())
    t1.join();


    cout<<"Main End";
    return 0;
}