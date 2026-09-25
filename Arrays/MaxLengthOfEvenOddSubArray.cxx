#include<iostream>
using namespace std;

// int maxLength(vector<int> &arr)
// {
//     int n = arr.size();
//     int res = 1; int curr= 1;
//     for(int i =1;i<n;i++)
//     {
//         if((arr[i]%2==0 && arr[i-1]%2 != 0)
//         || ( arr[i]%2 != 0 && arr[i-1]%2 != 0))
//         {
//             curr++;
//             res = max (res,curr);
//         }else
//         {
//             curr=1;
//         }
        
//     }
//     return res;
// }

//now let's make the code print start and end indices of the subArray

int maxLength(vector<int> &arr , int &start , int &end)
{
    int n = arr.size();
    int res = 1; int curr= 1;
    int start =1,end,curr=start;
    for(int i =1;i<n;i++)
    {
        if((arr[i]%2==0 && arr[i-1]%2 != 0)
        || ( arr[i]%2 != 0 && arr[i-1]%2 != 0))
        {
            curr++;
            if(res >curr){

            }
            else{
                res = curr;
                start =
            }
        }else
        {
            curr=1;
            start=i;
        }
        
    }
    return res;
}

int main ( void )
{
    vector<int> arr = { 2,4,1,5,3,4,2,6,8};

    int start =0; int end =0;
    //cout<<"Max length of even odd subArray is "<<maxLength(arr,start,end);
    cout<<"Max length of even odd subArray is "<<maxLength(arr,start,end)<<" with indices "<<start << "and "<<end;
    return 0;
}