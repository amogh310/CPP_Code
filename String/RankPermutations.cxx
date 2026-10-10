/*
    Given a string s consisting of distinct lowercase characters, determine its rank among all its permutations when those are arranged in lexicographically sorted order.
    Note: The rank of a string is its position (starting from 1) in the sorted list of all its permutations.

    Examples:

    Input: s = "abc"
    Output: 1
    Explanation: All permutations of "abc" arranged in lexicographical order are: [abc, acb, bac, bca, cab, cba]. Since "abc" appears first in this list, its rank is 1.

*/
#include <bits/stdc++.h> 
using namespace std; 
 
const int CHAR=256; 
int fact(int n) 
{ 
    return (n <= 1) ? 1 : n * fact(n - 1); 
} 
 
int lexRank(string &str) 
{ 
    int res = 1; 
    int n=str.length();
    int mul= fact(n);
    int count[CHAR]={0};
    for(int i=0;i<n;i++)
        count[str[i]]++;
    for(int i=1;i<CHAR;i++)
        count[i]+=count[i-1];
    for(int i=0;i<n-1;i++){
        mul=mul/(n-i);
        res=res+count[str[i]-1]*mul;
        for(int j=str[i];j<CHAR;j++)
            count[j]--;
    }
    return res; 
} 
  
 
int main() 
{ 
    string str = "STRING"; 
    cout << lexRank(str); 
    return 0; 
}