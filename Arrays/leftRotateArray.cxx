#include <iostream>

using namespace std;

void print(vector<int>&arr)
{
    for(auto i : arr)
    {
        cout<<i<<" ";
    }
    cout<<endl;
}

void leftRotate(vector<int>&arr)
{
    int size = arr.size();
    int temp = arr[0];
    for(int i =1;i<size;i++){
        arr[i-1]=arr[i];
    }
    arr[size-1]=temp; 
}

int main() {
    //Happy Coding

    vector<int>arr = { 23,43,64,78,54 };
    print(arr);
    leftRotate(arr);
    print(arr);

    return 0;
}