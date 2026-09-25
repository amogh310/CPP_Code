#include <iostream>
using namespace std;

bool isPalindrome(string str , int s , int e){
    if( s>=e ) return true;
    //look here , The values never change for the next call, creating an infinite recursive loop that crashes your program with a Stack Overflow.
    //return str[s]==str[e] && isPalindrome(str, s++, e--);
    return str[s]==str[e] && isPalindrome(str, ++s, --e);
}
int main(void) {
    // Happy Coding Amogh !!
    string x = "aabbaa";
    int start =0; int end = x.size()-1;
    if(isPalindrome(x,start,end))
    {
        cout<<"yes";
    }
    else{
        cout<<"NO";
    }
    return 0;
}