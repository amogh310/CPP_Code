//printing no from 1 to n and reverse using recursion
#include <iostream>
using namespace std;

void printNto1(int n)
{
    if(n==0)return;
    cout<<n<<" ";
    printNto1(n-1);
   
}
void print1ToN(int n)
{
    if(n==0)return;
    print1ToN(n-1);
    cout<<n<<" ";

}

int main (void)
{
    int n =10;
    printNto1( n);
        n=10;
        cout<<endl;
    print1ToN( n);

    return 0;
}