
#include <iostream>
using namespace std;

typedef int (*addPtr)(int *, int *);
typedef void(*printPtr)(int);

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
    int b =15;

    //same like saying addPtr = add;
    //one step extra
    addPtr addition;
    addition=add;

    printPtr printer;
    printer =print;

    int ans = addition(&a,&b);
    printer(ans);
    return 0;
}