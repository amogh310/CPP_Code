#include <iostream>

using namespace std;

void swap(int &a , int &b)
{
    int temp =a ;
    a=b;
    b=temp;
}

int moveZerosToEnd(vector<int>&arr)
{
    // i=0 count=0
    int count =0;
    int size = arr.size();
    for(int i =0;i<size;i++){
        if(arr[i]!=0){
            swap(arr[i],arr[count]);
            count++;
        }
    }
    return count;
}

void print(vector<int>&arr,int n)
{
    for(int i =0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void print(vector<int>&arr)
{
    for(auto i : arr)
    {
        cout<<i<<" ";
    }
    cout<<endl;
}


int main() {
    //Happy Coding

    vector<int>arr = { 1, 0, 0, 1, 0 };
    print(arr);
    int n = moveZerosToEnd(arr);
    print(arr,n);

    return 0;
}