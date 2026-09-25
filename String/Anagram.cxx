//check if string is an Anagram ( permutation arrangement of the characters listen and silent)
//Idea : if the freq of chars is same in both strings then yes . so ,traverse first i++ and traverse second i--.
//BEST Idea: sort the strings and check if they are equal 

#include <iostream>
using namespace std;
const int CHAR = 256;

bool isAnagram(string &a , string &b)
{
    int m = a.length(),n=b.length();
    if(m!=n) return false;

    int count[CHAR] = {0};
    for(int i=0;i<m;i++)
    {
        count[a[i]]++;
        count[b[i]]--;
    }

    for(int i=0;i<CHAR;i++){
        if(count[i] !=0) return false;
    }
    return true;
}

bool isAnagram2(string &a , string &b)
{
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());  
    return a==b;
}

int main(void)
{
    //look how capital char are used
    string a ="listen";
    string b ="silent";

    if(isAnagram2(a,b))cout<<"An Anagram !";
    else cout<<" Not an Anagram";

    return 0;
}