#include<iostream>
using namespace std;

void intersection ( vector<int> &a , vector<int> &b)
{
    vector<int>ans;
    int m = a.size();
    int n = b.size();
    
    int i=0 , j=0;
    while(i<m && j<n)
    {
        if(i>0 && a[i]==a[i-1]) { i++; continue;}
        else if(a[i] < b[j]) { i++;}
        else if(a[i] > b[j]) { j++;}
        else if(a[i] == b[j]) { cout<<a[i]<<" "; i++;j++;}
    }
    
}
int main (void)
{
    vector<int> arr1 = {15,20,35,40,55,87,98};
    vector<int> arr2 = {15,20,36,40,57,84,98};

    intersection(arr1,arr2);
    return 0;
}