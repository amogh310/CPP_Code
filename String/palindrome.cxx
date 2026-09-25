#include <iostream>
using namespace std;

bool checkPalindrome(string &str)
{
    int n = str.length();
    for(int i =0;i<n;i++){
        if(str[i] != str[n-i-1]) return false;
    }
    return true;
}
int main() {
    //Happy Coding
    string str = "tattarrattat";//(sound of someone knocking on a door (Oxford))
    if(checkPalindrome(str)) cout<<"A Palindrome";
    else cout<<"Not a Palindrome.";
    return 0;
}