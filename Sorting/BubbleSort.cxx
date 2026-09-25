#include<iostream>
using namespace std;

void swap(int &a , int &b)
{
    int temp = a;
    a=b;
    b=temp;
}

void bubbleSort(vector<int>&arr)
{
    for(int i=0;i<=arr.size();i++){
        for(int j=i+1;j<arr.size()-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                swap(arr[j],arr[j+1]);
            }
        }
    }
}

int main(void)
{
    //Happy Coding 
    vector<int>arr = { 14,25,36,86,69,57,21};
    for(auto i : arr)
    {
        cout<<i<<" ";
    }
    cout<<endl;

    bubbleSort(arr);

    for(auto i : arr)
    {
        cout<<i<<" ";
    }
    cout<<endl;

    return 0;
}