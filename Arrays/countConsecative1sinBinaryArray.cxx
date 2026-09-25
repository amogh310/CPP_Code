#include <iostream>
using namespace std;

int countConsecativeOnes(vector<int>&arr){
    int res =0;
    int curr_count=0;

    for(auto i : arr){
        if(i==1){
            curr_count++;
            res = max ( res,curr_count);
        }
        else{
            curr_count =0;
        }
    }
    return res;
}
int main() {
    //Happy Coding
    vector<int>arr = { 0,1,1,0,1,1,1};
    int count = countConsecativeOnes(arr);
    cout<<count;
    return 0;
}