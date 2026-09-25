//We insert the next element in its rightful place in the sorted array 
//start with 1st indx element as: single element array is always sorted

#include<iostream>
using namespace std;


void insertionSort(vector<int>&arr)
{
    for(int i=1;i<arr.size();i++){
        int key =arr[i];
        int j=i-1;
        while(j>=0 && arr[i]<arr[j]){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}

int main(void)
{
    //Happy Coding 
    vector<int>arr = { 25,14,36,86,69,57,21};
    for(auto i : arr)
    {
        cout<<i<<" ";
    }
    cout<<endl;

    insertionSort(arr);

    for(auto i : arr)
    {
        cout<<i<<" ";
    }
    cout<<endl;

    return 0;
}