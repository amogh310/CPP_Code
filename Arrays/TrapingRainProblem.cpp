#include <iostream>
using namespace std;
//Good Question
//Given an array arr[] of size n consisting of non-negative integers, where each element represents the height of a bar in an elevation map and the width of each bar is 1, determine the total amount of water that can be trapped between the bars after it rains.

int getWaterStored(vector<int>&arr)
{
    int n= arr.size();
    int res=0;
    //idea is to have precomputed left max and right max arrays
    int lmax[n], rmax[n];
    //this for sure
    lmax[0]= arr[0];
    rmax[n-1] = arr[n-1];

    //populate lmax and rmax from left to right and one from right to left
    for(int i=1;i<n-1;i++){
        lmax[i]=max(arr[i],lmax[i-1]);
    }
    for(int i=n-2;i>-1;i--){
        rmax[i]=max(arr[i],rmax[i+1]);
    }

    //now final count
    for(int i =0;i<n;i++){
        res+=(min(lmax[i],rmax[i])-arr[i]);
    }
    return res;
}
int main() {
    //Happy Coding
    vector<int>arr = { 3, 0,1,2,5};
    int water = getWaterStored (arr);
    cout<<water<<endl;
    return 0;
}
