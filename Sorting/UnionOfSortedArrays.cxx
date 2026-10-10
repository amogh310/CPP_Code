#include <iostream>
using namespace std;

using vec = vector<int>;

void unionOfSorted(vec &a , vec &b)
{
    int i=0, j=0;
    while( i<a.size() && j <b.size())
    {
        if(i>0 && a[i]==a[i-1]) { i++; continue;}
        if(j>0 && b[j]==b[j-1]) { j++; continue;}

        if( a[i]<b[j] ) { cout<<a[i]<<" "; i++;}
        else if(a[i]>b[j] ) { cout << b[j]<<" "; j++;}
        else if( a[i] == b[j] ) { cout<<a[i]<<" "; i++; j++;}

    }
    while(i<a.size())
    {
        if(a[i] != a[i-1]) { cout<<a[i]<<" ";}
        i++;
    }

    while(j<b.size())
    {
        if(b[j] != b[j-1]) { cout<<b[j]<<" ";}
        j++;
    }
}

int main() {
    //Happy Coding
    vec a = {10,20,20};
    vec b = {5,20,40,40};

    unionOfSorted(a,b);
    return 0;
}