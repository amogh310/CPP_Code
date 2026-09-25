//next part of the sliding window <- maxSumOfKConsecative_SlidingWindow.cxx
//idea is to add from second end if the given sum is smaller and subtract from first end if given sum is greater

#include <iostream>
using namespace std;

bool findSubArray(vector<int>&arr , int sum , int &start , int&end)
{
    int n = arr.size();
    start =0;end =0;
    int cSum = arr[0];
    if(cSum == sum ) return true;
    for(int i =1;i<n;i++)
    {
        if(cSum == sum ) return true;
        if(cSum<sum){
            cSum += arr[i];
            end++;
        }
        if(cSum>sum){
            cSum-=arr[start];
            start++;
        }
    }
    return false;
}

int main ( void )
{
    
    vector<int>arr = { 10,4,5,1,2,3,8,9,4 };
    int sum = 99,start=0,end=0;
    bool found = findSubArray(arr,sum,start,end);
    
    if(found)cout<<"Found! " <<arr[start] << " " <<arr[end];
    else cout<<"Alas! ";
    return 0;
}