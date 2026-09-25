#include <iostream>
using namespace std;

int countProfit(vector<int>& arr)
{
    int profit =0;
    for(int i =1;i<arr.size();i++)
    {
        //brilliant idea : we count cumulative profit , that ultimately covers the loss happened in the past
        if(arr[i]>arr[i-1]){
            profit+=arr[i]-arr[i-1];
        }
    }
    return profit;
}

int main(void)
{
    vector<int>arr = { 10 , 20, 30};
    int paisa = countProfit(arr);
    cout<<paisa<<endl;
}