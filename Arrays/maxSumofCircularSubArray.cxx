//extension of the Kadane's Algorithm 
//finding the max sum of the circular subArray

#include <iostream>
using namespace std;

void kadanesAlgo(vector<int>&arr,int &max_sum,int &min_sum)
{
    int n = arr.size();
    int curr_sum = arr[0];
     max_sum = curr_sum;

    int curr_min = arr[0];
     min_sum = curr_min;
    for(int i =1;i<n;i++)
    {
        curr_sum = max (arr[i],curr_sum+arr[i]);
        max_sum = max(max_sum , curr_sum);

        curr_min = min ( arr[i], curr_min+ arr[i]);
        min_sum = min(min_sum , curr_min);
    }
    cout<<" Linear Max SubArray Sum : "<<max_sum<<endl;
}

int MaxCircularSubSum(vector<int> &arr)
{
    int n = arr.size();
    int linearMax=0,linearMin=0;
    kadanesAlgo(arr, linearMax ,linearMin);

    //Now , this is imp 
    if(linearMax <0) return linearMax;

    //calculate whole Array Sum 
    int tsum = 0;
    for( int i : arr)
    {
        tsum+=i;
    }

    int circularMax = tsum- linearMin;
    return max(circularMax , linearMax);

}

int main(void)
{
    vector<int>arr = {2,-3,-8,7,-1,8};
    cout<<MaxCircularSubSum(arr);
}