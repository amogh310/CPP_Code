#include<iostream>
using namespace std;
//kadanes Algorithm
//The trick is decision whether to start new subArray or add the element to the current one 
//This is not the recursion problem like finding subArrays 

int maxSubArraySum(vector<int>&arr)
{
    int n = arr.size();
    int maxSum= arr[0];
    int res = maxSum;
    for(int i =1;i<n;i++){
        maxSum=max(maxSum+arr[i],arr[i]);
        res = max(res,maxSum);
    }
    return res;
}

int main (void)
{
    vector<int>arr = { 10,20,-2,-1,-4,-20,-5,0};
    std::cout<<maxSubArraySum(arr);
    return 0;
}