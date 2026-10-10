/*
    Isogram strings are ones where every character occurs exactly ones.
    Simple : Just traverse through string , map it to a vector with default values -1,
    If new char ++1 , if not -1 , then false, return true at end.
*/
#include <iostream>
using namespace std;

bool isIsogram(string &a)
{
    vector<int>vec(26,-1); 
    int indx =0;
    for ( char c : a)
    {
        indx=c-'a';
        if(vec[indx] == -1 )
        {
            vec[indx]++;
        }
        else return false;
    }

    return true;
}
int main() {
    //Happy Coding

    string a = "abcdefghijklmnopqrstuvwxyz";
    if(isIsogram(a)){cout<<"Yes Isogram !! ";}
    else { cout<<"Non isogram ";}
    
    return 0;
}