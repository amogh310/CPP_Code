#include<iostream>
#include<thread>
#include<mutex>
#include<chrono>

int counter =0;
//notice here : timed_mutex
std::timed_mutex tmtx;

/*
    0.Unlike the try_lockcontinuously trying to lock the critical section , try_lock_for tries to lock the section for given time .
    1.On successful lock acquisition returns true, otherwise returns false.
*/

void count(int i)
{
    if(tmtx.try_lock_for(std::chrono::seconds(1)))
    {
        ++counter;
        std::cout<<"Thread "<<i<<" Entered "<<counter<<std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(2));
        tmtx.unlock();
    }
    else
    {
        std::cout<<"Thread "<<i<<" Couldn't enter"<<std::endl;
    }
}

int main (void)
{
    std::thread t1(count ,1);
    std::thread t2(count ,2);

    t1.join();
    t2.join();

    std::cout<<counter<<std::endl;
    return 0;
}