#include<iostream>
#include<thread>
#include<vector>
#include<chrono>
#include<semaphore> //introduced in the c++20 , before needed manual implementation //refer OldSemaphor

/*
A semaphore is a signaling variable used in multi-threaded programming to manage resource sharing. Unlike a mutex, which acts like a strict individual lock, a semaphore behaves like a bouncer managing a headcount or a counter for available tokens.
It tracks a specific number of available resources using an integer value.like executing lock on multiple critical sections at once ..
eg: Renting a car from 3 cars , 3 critical sections can be accessed at once here . 

std::counting_semaphore<N> – A semaphore whose internal counter can go up to 'N'. It is used to limit access to a pool of identical resources.(No. of cars here)
std::binary_semaphore – An alias for std::counting_semaphore<1>. It alternates strictly between 0 and 1.

.acquire() – Decrements the semaphore counter. If the counter is 0, the calling thread blocks (goes to sleep) until the count increases.
.release() – Increments the semaphore counter. If threads are blocked, it wakes one up.

*/

std::counting_semaphore<3> cars(3);

void allocate_car(int id)
{
    //Car acquired : available car counter decremented : blocked if counter =0 
    cars.acquire();

    std::this_thread::sleep_for(std::chrono::seconds(5));

    //Car returned : counter incremented : wakes up next waiting customer
    cars.release();
}

int main()
{
    std::vector<std::thread>customers;

    for(int i =1;i<=5;i++)
    {
        customers.push_back(std::thread(allocate_car,i));
    }

    for(auto& th : customers)
    {
        th.join();
    }
}
