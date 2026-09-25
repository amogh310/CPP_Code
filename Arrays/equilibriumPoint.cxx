//An equilibrium point is sum of elements to its left == sum of elements to its right
//1.calculate preSum and postSum of the elements in an Array , where they met is the point (Requires extra space of the two arrays)
//2.calculating the whole sum and subtracting respective element (optimal)

#include<iostream>
using namespace std;

int findEquilibrium(vector<int>&arr)
{   
    int tSum=0; int lSum=0;
    for(int i:arr) tSum+=i;
    for(int i =0;i<arr.size();i++)
    {
        //this sequence is super imp
        //always play around arr[i]
        tSum-=arr[i];
        if(lSum==tSum)return i;
        lSum+=arr[i];
    }
    return -1;
}
int main(void)
{
    vector<int>arr = { 2, 1, 0, 3 };
    int indx = findEquilibrium(arr);
    if(indx != -1) cout<<arr[indx];
    return 0;
}