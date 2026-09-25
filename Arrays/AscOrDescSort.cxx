#include <iostream>

using namespace std;
bool sorted (int arr[],int n)
{
    bool desc = true; 
    bool asc = true;

    for (int i=0;i<n-1;i++)
    {
        if(arr[i]>arr[i+1]){
            asc=false;
        }
        if(arr[i]<arr[i+1]){
            desc=false;
        }
    }
    return asc||desc;
}

int main() {
    //Happy Coding
    int arr[5] = {23,43,64,78,54};
    cout<<sorted(arr,5);
    return 0;
}