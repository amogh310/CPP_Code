#include<iostream>
#include<thread>
#include<mutex>
#include<vector>
#include<chrono>
#include<condition_variable>

/*
    Implementing manual Semaphore (refer to Semaphore.cxx) using mutex and condition_variable
*/

class OldSemaphore
{   private:
        int count;
        std::mutex mtx;
        //condition variable allows threads to suspend execution (go to sleep) until notified by another thread that a specific condition has been met.
        /* IMP
            cv.wait(unique_lock) puts threads to sleep and cv.notify_one() wakes up exactly one thread, cv.notify_all() wakes up EVERY SINGLE THREAD currently sleeping on that specific condition variable.
            LOST WAKE-UP DEADLOCK : problem with cv.notify_one() : f that thread wakes up, checks the condition, realizes it still can't proceed, and goes back to sleep without notifying anyone else, all your other threads stay asleep forever. Your program freezes completely. 
            hence cv.notify_all exists.
        */
        /*
        If without condition_variable : CPU MELTDOWN
        void acquire() {
            while (true) 
            {
                mtx.lock();
                if (count > 0) 
                {
                    count--;
                    mtx.unlock();
                    break; 
                }
                mtx.unlock(); // Release lock so others can update count
                // Thread immediately loops back up and locks again!
            }
        }
        */
        std::condition_variable cv;
    public:
        OldSemaphore(int resources):count(resources){};
        
        //std::lock_guard is a simple tool that only knows how to lock and unlock automatically, while std::unique_lock is a heavy-duty tool that allows you to manually lock, unlock, and temporarily hand over control to a std::condition_variable.

        void acquire();
        void release();

};

OldSemaphore::acquire()
{
    //Inside acquire(), the thread checks if a resource is available. If count == 0, the thread must go to sleep and wait.
    //lock the resource state
    std::unique_lock<std::mutex> lock(mtx);

    /*
        CRUCIAL CODE : If count == 0, the thread must go to sleep and wait.
        
        IMP:
        The thread realizes it has to wait.
        It must unlock the mutex before it goes to sleep. 
        If it doesn't unlock it, no other thread can ever call release() to add resources, creating a permanent deadlock.
        When the thread is finally woken up, it must re-lock the mutex before checking the condition again.
        Because cv.wait() needs to constantly unlock and re-lock the mutex behind the scenes, it only accepts a std::unique_lock. 
        A std::lock_guard cannot be manually unlocked, so the compiler will throw an error if you try to pass it to a condition variable.
    */
    while(count == 0)
    {
        cv.wait(lock);
    }

    count--; //decrement availability

    // Unique_lock automatically unlocks here when going out of scope
}

OldSemaphore::release()
{
    //straight forward lock_guard
    std::lock_guard<std::mutex>lock(mtx);
    count++; // Free up a resource
    // Lock is released here immediately so waiting threads can proceed
    cv.notify_one(); //Signal ONE sleeping thread to wake up and check the count
}

OldSemaphore cars(3);

void assign_car(int id)
{
    cars.acquire();

    std::this_thread::sleep_for(std::chrono::seconds(5));

    cars.release();
}
int main()
{
    std::vector<std::thread>customers;
    for(int i =1;i<=5;i++)
    {
        customers.push_back(std::thread(assign_car,i));
    }

    //joining or detaching is IMP as always 
    //Must catch elements by reference '&' to avoid copying thread objects!
    for(auto &t : customers)
    {
        t.join();
    }
}