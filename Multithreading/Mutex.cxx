#include <iostream>
#include<thread>
#include<mutex>


/*
    Mutex : Mutual Exclusion 
    Race condition : two or more threads\processes trying to access the common resource at the same time and that common resource is the critical section

    Mutex is used to avoid race condition , also semaphors are used //refer semaphor.cxx and oldSemaphor.cxx
    we use lock(), unlock() on mutex 
*/
int count =0;
std::mutex mtx;

void counter ()
{
    //refer to oldSemaphor.cxx for unique_lock and lock_guard implementation
    mtx.lock();
    count++;
    mtx.unlock();
}
int main() {
    //Happy Coding

    std::thread t1(counter);
    std::thread t2(counter);

    t1.join();
    t2.join();

    std::cout<<count;
    return 0;
}