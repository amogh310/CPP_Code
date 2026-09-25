#include <iostream>

using namespace std;
//leaders are those elements in an Array , who does not have greater or equal elemets to their right

void print(vector<int>&ans)
{
    for(auto i : ans)
    {
        cout<<i<<" ";
    }
    cout<<endl;
}
void leadersArray(vector<int>&arr)
{
    //smart : start from right actually then
    //rightmost element is always a leader
    vector<int>ans;
    int n = arr.size();
    int curr_leader= arr[n-1];
    ans.push_back(curr_leader);

    for(int i = n-2; i>-1;i--)
    {
        if(arr[i]>curr_leader)
        {
            curr_leader=arr[i];
            ans.push_back(curr_leader);
        }
    }
    
    print(ans);
}
int main() {
    //Happy Coding
    vector<int>arr = { 7,10,4,10,6,5,2};
    leadersArray(arr);

    return 0;
}