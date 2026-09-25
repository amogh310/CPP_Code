#include <iostream>
using namespace std;

//wherever IntPtr is written replace it with int*
typedef int* IntPtr;

int main() {
    //Happy Coding

    int i =10;
    IntPtr x = &i;// same as int *x = &i;
    //cout<< *x<<endl;

    //trick question , here if it would (int * a,b):  a is pointer but b is not ,
    //its like int *a,b -> int *a ; int b;
    //but since using typedef
    //its like IntPtr a,b -> IntPtr a , IntPtr b

    IntPtr a,b;   
    //try
    a=&i;
    b=&i;
    cout<<*a<<" "<<*b;
    return 0;
}