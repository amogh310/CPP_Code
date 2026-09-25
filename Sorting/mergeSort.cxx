// //Divide and Conquer approach : Divide array until there are only single elements left and then merge them
//TODO:: Segmentation Fault 

/*
#include <iostream>
using namespace std;

void merge(vector<int>&arr,int l, int m ,int r)
{
    int i=l;int j=m+1;int indx=0;
    while(i<=m && j<=r)
    {
        if(arr[i]<=arr[j]){
            arr[indx]=arr[i];
            i++;indx++;
        }
        else
        {
            arr[indx]=arr[j];
            j++;indx++;
        }
    }

}

void sort(vector<int>&arr,int l,int r,int m)
{
     l=0;  r=arr.size()-1;
    int mid = l+((r-l)/2);
    while(l<r)
    {
        sort(arr,l,mid,mid);
        sort(arr,mid,r,mid);
        merge(arr,l,m,r);
    }
}
void mergeSort(vector<int>&arr)
{
    sort(arr,0,arr.size(),0);
}

int main(void)
{
    //Happy Coding 
    vector<int>arr = { 14,25,36,86,69,57,21};

    for(auto i : arr)
    {
        cout<<i<<" ";
    }
    cout<<endl;

    mergeSort(arr);

    for(auto i : arr)
    {
        cout<<i<<" ";
    }
    cout<<endl;

    return 0;
}

*/

#include <iostream>
#include <vector>
using namespace std;

// Merge two sorted halves back into the main array
void merge(vector<int>& arr, int l, int m, int r) {
    vector<int> temp;
    int i = l;       // Starting index for left subarray
    int j = m + 1;   // Starting index for right subarray

    while (i <= m && j <= r) {
        if (arr[i] <= arr[j]) {
            temp.push_back(arr[i]);
            i++;
        } else {
            temp.push_back(arr[j]);
            j++;
        }
    }

    // Copy remaining elements from left subarray
    while (i <= m) {
        temp.push_back(arr[i]);
        i++;
    }

    // Copy remaining elements from right subarray
    while (j <= r) {
        temp.push_back(arr[j]);
        j++;
    }

    // Transfer sorted elements back to the original array
    for (int k = 0; k < temp.size(); k++) {
        arr[l + k] = temp[k];
    }
}

// Recursive function to divide the array
void mergeSortHelper(vector<int>& arr, int l, int r) {
    if (l >= r) {
        return; // Base case: single element or invalid range
    }

    int mid = l + (r - l) / 2;

    // Divide left half
    mergeSortHelper(arr, l, mid);
    // Divide right half
    mergeSortHelper(arr, mid + 1, r);
    // Merge sorted halves
    merge(arr, l, mid, r);
}

void mergeSort(vector<int>& arr) {
    if (arr.empty()) return;
    mergeSortHelper(arr, 0, arr.size() - 1);
}

int main(void) {
    vector<int> arr = {14, 25, 36, 86, 69, 57, 21};

    cout << "Before sorting: ";
    for (auto i : arr) {
        cout << i << " ";
    }
    cout << endl;

    mergeSort(arr);

    cout << "After sorting:  ";
    for (auto i : arr) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
