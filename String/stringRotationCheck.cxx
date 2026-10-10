/*
    Given two strings s1 and s2, of equal lengths. The task is to check if s2 is a rotated version of the string s1.
    Input: s1 = "abcd", s2 = "cdab"
    Output: true
    Explanation: After 2 right rotations, s1 will become equal to s2.

*/
#include <iostream>
using namespace std;

bool areRotations(string &s1, string &s2) 
{
       
    return (s1+s1).find(s2)!=string::npos;
}
int main() {
    //Happy Coding
    string a ="abcd";
    string b ="cdab";

    if(areRotations(a,b))cout<<"Rotations";
    
    return 0;
}