//print characters and frequencies of a string in ascending order
//look how char(i+'a') is used 

#include <iostream>
using namespace std;

int main() {
    string str = "happy coding";
    int arr[26]={0};
    for(char c : str)
    {
        arr[c-'a']++;
    }
    for(int i=0;i<26;i++){
        if(arr[i]>0)
            cout<<char(i+'a')<<" "<<arr[i]<<endl;
    }
    return 0;
}