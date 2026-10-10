#include<iostream>
#include<mutex>
#include<thread>

/*
    0. try_lock() Tries to lock the mutex. Returns immediately. On successful lock acquisition returns true otherwise returns false.
    1. If try_lock() is not able to lock mutex, then it doesn't get blocked that's why it is called non-blocking.
    2 . If try_lock is called again by the same thread which owns the mutex, the behaviour is undefined.
    It is a dead lock situation with undefined behaviour. (if you want to be able to lock the same mutex by same thread more than one time the go for recursive_mutex)
    
    std::mutex::try_lock
    std::recursive_mutex::try_lock
 */

std::mutex mtx;

void counter(int& count)
{
    for(int i =0;i<100000;++i)
    {
        //sometimes CPU is able to place a lock to critical section in one thread and sometimes not
        //here behaviour is undefined
        if(mtx.try_lock())
        {
            ++count;
            mtx.unlock();
        }
        
        //Instead of dialogue if we use normal lock (thread waits until unlocking ) then we would see the expected output
        // mtx.lock();
        // count++;
        // mtx.unlock();

        // std::lock_guard<std::mutex>lock(mtx);
        // count++;    
        
        // std::unique_lock<std::mutex>lock(mtx);
        // count++;
    }
}

int main ()
{
    //std::cout<<" Happy Coding !!"<<std::endl;

    int count=0;

    std::thread t1(counter ,std::ref(count));
    std::thread t2(counter, std::ref(count));

    t1.join();
    t2.join();

    std::cout<<count<<std::endl;

    return 0;
}