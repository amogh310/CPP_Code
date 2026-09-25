#include<iostream>
#include<thread>

using namespace std;

void funct(int x)
{
    cout<<x<<" ";
    while(x-->0)
        cout<<x<<" ";
    cout<<endl;
}

struct Functor{
    void operator()(int x){
         cout<<x<<" ";
        while(x-->0)
        cout<<x<<" ";
        cout<<endl;
    }
};

class FunctionClass
{
    public:
    void run (int x)
    {
        cout<<x<<" ";
        while(x-->0)
        cout<<x<<" ";
        cout<<endl;
    }
};

int main(void)
{
    //1.Function Pointer : Normal thread creation
    //Note: If we create multiple threads at the same time it doesn't gurantee which one will start first
    // You are passing instructions only. The thread gets a raw memory pointer to code.
    thread t1(funct,10);
    thread t2(funct,10);
    t1.join();
    t2.join();

    //2.Lambda function : 
    auto funct=[](int x )
    {
        cout<<x<<" ";
        while(x-->0)
        cout<<x<<" ";
        cout<<endl;
    };

    thread tLambda1(funct,10);
    tLambda1.join();

    //Or Insert Lambda function directly in thread creation: 
    thread tLambda2([](int x )
    {
        cout<<x<<" ";
        while(x-->0)
        cout<<x<<" ";
        cout<<endl;
    } , 10);
    tLambda2.join();

    //3.Functer (Function Object)
    //In fact, under the hood, the C++ compiler actually converts your lambda functions into functors.
    //ou are passing data + instructions combined. The thread gets a copy of an independent object instance, which contains its own variables and executes via its overloaded operator().
    
    Functor functor;
    thread FunctorThread(functor,10);

    //4.Non Static member function

    FunctionClass obj;
    thread classThread(&FunctionClass::run ,&obj,10);


    return 0;
}