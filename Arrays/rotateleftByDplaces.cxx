#include <iostream>

using namespace std;

void swap ( int &a , int &b)//10 5 
{
    a=a+b;//15 5
    b=a-b;//15 10
    a=a-b;//5 10 
}

void print(vector<int>&arr)
{
    for(auto i : arr)
    {
        cout<<i<<" ";
    }
    cout<<endl;
}

//trickiest function here , Very IMP
void reverse(vector<int>&arr,int start, int end)
{
    for(int i =start; i<start + (end - start + 1) / 2;i++)
    {
        swap(arr[i], arr[end+start-i]);
    }
}
void rotateByDPlaces(vector<int>&arr, int d)
{
    reverse(arr,0,d-1);
    reverse(arr,d,arr.size()-1);
    reverse(arr,0,arr.size()-1);
}
int main() {
    //Happy Coding

    vector<int>arr = { 23,43,64,78,54 };
    print(arr);
    rotateByDPlaces(arr ,3);
    print(arr);

    return 0;
}