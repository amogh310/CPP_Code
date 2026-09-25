//Find the maximum sum of the k consecative elements in an Array , here the size of window is k (fixed)
#include <iostream>
using namespace std;

int maxSum(vector<int>& arr,int k)
{
    //first window sum
    int currSum =0;
    for(int i =0;i<k;i++) currSum += arr[i];
    int maxSum = currSum;

    //now slide window , we add the next element (k)th and remove first (i-k)th
    for(int i=k;i<n;i++)
    {
        currSum+=arr[i]-arr[i-k];
        maxSum = max(maxSum,currSum);
    }
    return maxSum;   
}

int main() 
{
    //Happy Coding
    vector<int>arr = {1,4,2,19,23,3,1,0,20}
    int k =4;
    cout<<maxSum(arr,k);
    return 0;
}