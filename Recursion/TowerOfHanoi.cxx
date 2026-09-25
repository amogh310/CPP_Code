//counting no of steps 
#include <iostream>
using namespace std;

// no of discs , source , support/pivot , destination
int stepCounter(int n, int a , int b , int c)
{
    if(n==0) return 0;
    int steps =0;
    steps+=stepCounter(n-1 , a,c,b);
    steps++;
    steps+=stepCounter(n-1 , a ,b,c);
    return steps;
}

int main(void)
{
    int a =0, b =0,c =0;
    cout<<stepCounter(3,a,b,c);
    return 0;
}