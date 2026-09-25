#include <iostream>
#include<chrono>
#include<thread>

using namespace std;
using namespace std::chrono;//time related
typedef long long int ull;

void findEven(ull start, ull end,ull& evenSum)
{
    for(ull i=start;i<=end;i++)
    {
        if(!(i & 1) ){
            evenSum+=i;
        }
    }
}
void findOdd(ull start, ull end,ull& oddSum)
{
    for(ull i=start;i<=end;i++)
    {
        if((i & 1) ){
            oddSum+=i;
        }
    }
}

int main()
{

  ull start =0;
  ull end = 1900000000;
  
  ull oddSum =0;
  ull evenSum=0;

  //Normal execution :: time recordings
  auto startTime = high_resolution_clock::now();

  findEven(start,end,evenSum);
  findOdd(start ,end,oddSum);

  auto endTime = high_resolution_clock::now();
  auto duration = duration_cast<seconds>(endTime-startTime);

  cout<<" Even Sum "<<evenSum<<endl;
  cout<<" Odd Sum "<<oddSum<<endl;;

  //In C++, duration is a complex object (a structure/class), not a plain number.
  //we need its component::count here 
  cout<<"Time Required for normal Execution : "<<duration.count()<<endl;

  cout<<"Thread execution : "<<endl;

  evenSum=0;oddSum=0;
  startTime=high_resolution_clock::now();

  // Launches a separate thread to run findEven and findOdd concurrently with the main program.
  //To pass a reference to a thread, you must wrap the variable in std::ref() when creating the thread object.
  //By default thread constructor copies all arguments by value to protect against memory corruption.
  thread t1(findEven,start,end,ref(evenSum));
  thread t2(findOdd,start,end,ref(oddSum));

  //You must join() a thread because it forces your main program to wait until that thread finishes its work before moving forward.
  t1.join();
  t2.join();

  endTime = high_resolution_clock::now();
  duration = duration_cast<seconds>(endTime-startTime);
  cout<<" Even Sum "<<evenSum<<endl;
  cout<<" Odd Sum "<<oddSum<<endl;;
  cout<<"Time required for threaded execution : "<<duration.count()<<endl;

  return 0;

}