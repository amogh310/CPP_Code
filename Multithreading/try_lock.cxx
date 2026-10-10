#include <iostream>
#include<thread>
#include<mutex>
#include<chrono>

/*
    Not the object of mutex::try_lock() , It is std::try_lock(). 
    0. std::try_lock() tries to lock all the mutex passed in it one by one in given order.
    1. On success this function returns -1 ( Success ) otherwise it will return 0-based mutex index number ( Index of obj for which CPU failed to lock starting indx from 0 ) which it could not lock.
    2. If it fails to lock any of the mutex then it will release all the mutex it locked before.
    3. If a call to try_lock results in an exception, unlock is called for any locked objects before re-throwing.

*/

void increment (int &x , std::mutex &m)
{
    // m.lock(); 
    // x++;
    // m.unlock();

    for(int i =0;i<5;i++)
    {
        m.lock();
        x++;
        m.unlock();
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
    
    //we will make it wait here: 
}

void consume (int &a , int &b, std::mutex &m1, std::mutex &m2)
{
    int maxConsume =5;
    int sum =0;
    while(1)
    {
        //passw the lockable objects to try lock
        int res = std::try_lock(m1,m2);

        //Success = -1 ,otherwise 0 for m1 and 1 for m2 (indices)
        if( res == -1 )
        {
            if(a!=0 && b!=0 )
            {
                --maxConsume;
                sum += a+b;
                a=0;
                b=0;
                std::cout<<sum<<std::endl;
            }
            //If success : manually remove the lock 
            m1.unlock();
            m2.unlock();
            if(maxConsume ==0 )break;
        }
    }
}
int main() {
    //Happy Coding
    std::vector<std::thread>threadVec;
    int a =0; int b=0;
    std::mutex m1,m2;

    threadVec.push_back(std::thread(increment,std::ref(a),std::ref(m1)));
    threadVec.push_back(std::thread(increment,std::ref(b),std::ref(m2)));
    threadVec.push_back(std::thread(consume,std::ref(a),std::ref(b),std::ref(m1),std::ref(m2)));

    // Use a reference to avoid copying std::thread objects, which are non-copyable. Fails with auto(std:thread t1) use '&'.
    for ( std::thread &t : threadVec)
    {
        t.join();
    }

    return 0;
}