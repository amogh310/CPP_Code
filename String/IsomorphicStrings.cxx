/*
    What are Isomorphic strings ?

    Every occurrence of a specific character must map to the same character in the other string, and no two characters can map to the exact same target character.
    
    String 1	String 2	Isomorphic?	Why / Why Not?
    egg	        add	        Yes 	    e → a, and g → d. The structural pattern is ABB for both.
    paper	    title	    Yes 	    p → t, a → i, e → l, r → e. The pattern is ABACD.
    foo	        break   	No          cannot map to both a and r at the same time.
*/

#include <iostream>
using namespace std;

bool AreIsomorphic (string& a, string& b)
{
    int x = a.length();
    int y = b.length();

    //no 1:1 character mapping exists if they are of different lengths
    if(x !=y) return false;

    vector<int>m1(26,-1);
    vector<int>m2(26,-1);
    int indx1 =0,indx2=0;

    for(int i =0;i<x;i++)
    {
        indx1=a[i]-'a';
        indx2=b[i]-'a';

        if(m1[indx1] == -1 && m2[indx2] == -1) //check empty
        {
            //map them to each other
            m1[indx1]=indx2;
            m2[indx2]=indx1;
        }
        else //if already filled
        {
            if(m1[indx1]!=indx2 || m2[indx2] != indx1) //either of them is mapped with another
            {
                return false;
            }
        }
    }
    return true;
}

int main() {
    //Happy Coding
    string a = "foo";
    string b = "abc";

    if(AreIsomorphic(a,b)){cout<<"Isomorphic Strings !! ";}
    else {cout<<"Non Isomorphic Strings !!" ;}
    return 0;
}