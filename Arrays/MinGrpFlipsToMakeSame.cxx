//Minimum group flips To make same 
//IP : arr: { 1,1,0,0,0,1}
//OP : 2 to 4

#include <iostream>
using namespace std;

void findGroup(vector<int>&arr)
{
    int n = arr.size();
    //starting from indx 1
    for(int i =1;i<n;i++)
    {
        if(arr[i] != arr[i-1])
        {
            //starting from the different element than arr[0]
            if(arr[i] != arr[0]){
                cout<<"From the index "<<i<<"to ";
            }
            else
            {
                //to the last different element than arr[0]
                cout<<i-1<<endl;
            }
        }
    }
    //this line is necessary to close the last group
    if(arr[n-1] != arr[0]) cout<<n-1<<endl;
}
int main() {
    //Happy Coding

    vector<int>arr = { 1,1,0,0,0,1,0,0};
    findGroup(arr);
    return 0;
}