#include<iostream>
#include<algorithm>
using namespace std;

int removeDuplicates(int arr[], int n)
{   
    int size=1;
    for(int i=0;i<n;i++)
    {
        if(arr[i]!=arr[size-1]){
            arr[size]=arr[i];
            size++;
        }
    }
    return size;
}

int main() {
    //Happy Coding
    int arr[5] = {23,43,23,43,54};

    //main idea is sorting here:
    sort(arr,arr+5);

    for(int i=0;i<5;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    int n = removeDuplicates(arr,5);

    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    
    return 0;
}
