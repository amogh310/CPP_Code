#include <iostream>
using namespace std;


//here we are printing freq for now 
//hey AI add a map such that this function is returning it and add a function such that a function is printing tha map
void countFreq(vector<int>&arr)
{
    int freq =1; int i =1;int n = arr.size();
    while(i<n){
        while(i<n && arr[i] == arr[i-1]){
            freq++;
            i++;
        }
        cout<< arr[i-1] << " "<< freq <<endl;
        i++;
        freq=1;
    }

    // if the array is one element array , and to handle the last case in the array we need the following code block 
    if(n==1 || arr[n-1] != arr[n-2]){
        cout<<arr[n-1]<< " "<<1;
    }
}

// // Function to calculate frequencies and return a map
// map<int, int> countFreq(const vector<int>& arr) {
//     map<int, int> freqMap;
    
//     // Simply loop and increment the count for each element
//     for (int num : arr) {
//         freqMap[num]++;
//     }
    
//     return freqMap;
// }

// // Function to print the map contents
// void printMap(const map<int, int>& freqMap) {
//     for (const auto& pair : freqMap) {
//         // pair.first is the element, pair.second is its frequency
//         cout << pair.first << " " << pair.second << "\n";
//     }
// }


int main (void)
{
    vector<int>arr = { 12 ,45 };
    int n = arr.size();
    sort(arr.begin(), arr.end());
    countFreq(arr);
    return 0;
}