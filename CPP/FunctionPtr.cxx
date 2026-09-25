#include <iostream>
using namespace std;

int add(int *a , int *b)
{
    return *a + *b;
}

void print (int a)
{
    cout<<a;
}

int main(void)
{
    int a =10;
    int b =5;

    //Assigning a function to a ptr 
    //ptr p of type returning int to a function with param's int*, int * 
    int (*p)(int *, int *);
    p=add;

    int ans = p(&a,&b);

    void(*printPtr)(int);
    printPtr=print;

    printPtr(ans);

    return 0;
}