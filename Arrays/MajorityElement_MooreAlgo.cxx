//Element occuring more thann n/2 times :: like winning an election
//Moores voting Algorithm : find an element , check if it wins

#include <iostream>
using namespace std;

bool checkIfwin(vector<int>&arr, int res)
{
    //remember its index
    int candidate = arr[res];
    int count =0;
    int n = arr.size();

    for(int i:arr)
    {
        if(candidate == i) count++;
    }
    if(count>=n/2) return true;
    return false;
}

int findMajority(vector<int> &arr)
{
    //res is the indx of the majority element
    int res =0; int count =1;
    for(int i =1;i<arr.size();i++){
        if(arr[res] == arr[i])
        {
            //this index is in favor
            count++;
        }else{
            //because this index is opposing 
            count--;
        }
        if(count == 0){
            //time to change the candidate and count set to 1
            res=i;
            count=1;
        }
    }
    if( checkIfwin(arr,res) ){ return res; } //confirmation
    return 0; // No winning candidate : Nobody have n/2 votes
}
int main(void)
{
    vector<int>arr = {2, 2, 1, 1, 2, 2, 2};
    int indx = findMajority(arr);
    cout<<arr[indx];
    return 0;
}