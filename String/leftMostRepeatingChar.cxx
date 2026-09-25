#include<iostream>
using namespace std;

const int CHAR =256;

//approach one 
//with the array sized 256
int leftMost(string &s,char &c)
{
    int count[CHAR]= {0};
    for(char c : s)
    {
        count[c]++;
    }
    for(int i=0;i<s.length();i++)
    {
        if(count[s[i]>1]){
            c=s[i];
            return 1;
        } 
    }
    return -1;
}
int main(void)
{
    string s = "HelloAmogh!";
    char ans = NULL;
    leftMost(s,ans);
    cout<<ans;
    return 0;
}