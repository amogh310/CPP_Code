/*
    Although String Pattern searching famous algorithms KMP and Robin-Karp exists;
    just for the sake of information we are using Naive approach here: 

    Give: Target string and Pattern
    Idea: match the first character , if it matches increment the counters and match the next till last char of the pattern
    return : index of first char

    Imp : String lengths are zero based length of string a ="Hello" is 0
    char : H e l l o \0
    indx : 0 1 2 3 4 5
*/

#include <iostream>
using namespace std;

int NaivePatternMatching(string &source, string &pattern)
{
    int slength = source.length();
    int plength = pattern.length();
    
    if(plength<slength) return -1;
    int ans = INT_MIN;

    int j=0,i=0;
    while(i<slength)
    {
        if(source[i] == pattern[j])
        {
           ans =i;
           while(i<slength && j<plength && source[i]==pattern[j])
           {          
            i++;j++;
           }
           if(j==plength){
            return ans;
           }
           else{
            // Backtracking Rule: Agar match beech mein toota, 
            // toh i ko wapas usi 'ans' index par lao.
            // Niche wala i++ isko automatically agle char (ans + 1) par le jayega.
            i = ans;           
            j=0;
           }
        }
        i++;
    }
    return -1;
}
int main() {
    //Happy Coding

    string target = "happy Coding Amogh";
    string pattern = "Amogh";
    

    cout<<NaivePatternMatching(target,pattern);
    return 0;
}