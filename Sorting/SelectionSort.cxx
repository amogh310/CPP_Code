//find out the minimum index in the remaining array and swap it with the position
//We select the rightful element for the position from the array
#include<iostream>
using namespace std;

void swap(int &a , int &b)
{
    int temp = a;
    a=b;
    b=temp;
}

void selectionSort(vector<int>&arr)
{
     for(int i =0;i<arr.size()-1;i++)
     {
        int min_indx =i;
        for(int j=i+1;j<arr.size();j++)
        {
            if(arr[min_indx]>arr[j])
                swap(arr[min_indx],arr[j]);
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

    selectionSort(arr);

    for(auto i : arr)
    {
        cout<<i<<" ";
    }
    cout<<endl;

    return 0;
}