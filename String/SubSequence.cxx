#include <iostream>
using namespace std;

bool isSubString(string &a, string &b)
{
    int m = a.length();
    int n = b.length();

    int i=0,j=0;
    for(i=0;i<m && j<n ;i++){
        if(a[i] == b[j]) j++;
    }
    return j==n;
}

int main() {
    //Happy Coding
    string src = "HappyCoding";
    string trgt = "pyCo";

    if(isSubString(src,trgt)) cout<<"A SubString !";
    else cout<<"Not a SubString ! ";
    
    return 0;
}