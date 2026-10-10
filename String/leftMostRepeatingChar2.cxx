/*
    Idea: 
    Have a boolean vector with default values false ; Iterate from right to left , maintain a repeating char as ans , 
    if(visited) update the ans , since iterating right to left last one is the leftmost , 
    run this from left to right and last one is rightmost .
*/
#include <iostream>
using namespace std;

char leftMostRepeatingChar(string &a)
{
    char ans; 
    vector<bool>vec(256,false);
    int indx =0;

    for(int i =a.length()-1;i>=0;i-- )
    {
        char c =a[i];
        indx = c;
        if(vec[indx] == true){
            ans = c;
        }else{
            vec[indx]=true;
        }
    }
    return ans;
}
int main() {
    //Happy Coding
    string a("Happy Coding");
    cout<<leftMostRepeatingChar(a);
    return 0;
}