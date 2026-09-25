#include<iostream>
using namespace std;

void swap(int &a , int &b)
{
    a=a+b; //15 5
    b=a-b; // 15 10
    a=a-b; //5 10
}
void traverse(int arr[], int n)
{
    for(int i =0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
void reversed(int arr[], int n)
{
    int limit=n/2;
    for(int i =0;i<limit;i++)
    {
        swap(arr[i], arr[n-i-1]);
    }
}

int main() {
    //Happy Coding
    int arr[5] = {23,43,64,78,54};
    traverse(arr,5);
    reversed(arr,5);
    traverse(arr,5);
    return 0;
}