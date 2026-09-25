//Fill another array of prefix as : 
//lets say arr[] = { 10,20,30} so preArr[]={10,30,60} 
//as preArr[i]=arr[0]+arr[1]+....+arr[i]
#include <iostream>
using namespace std;

int main(void)
{
    int arr[] = {2,8,3,9,6,5,4};
    int n = sizeof(arr)/sizeof(arr[0]);

    int ps[n];
    ps[0]=arr[0];
    for(int i=1;i<n;i++){
        ps[i]=ps[i-1]+arr[i];
    }

    for(int i : ps)
    {
        cout<<i<<" ";
    }
}
