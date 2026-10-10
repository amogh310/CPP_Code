/*
    Notes:
    Longest proper prefix which is also a suffix
    
    Core Idea of KMP: 
    Imagine your source string is "abax..." and your pattern is "abab".
    1. You match index 0 (a), index 1 (b), index 2 (a).
    2. At index 3, you have a mismatch (source[3] == 'x' but pattern[3] == 'b').
    3. Instead of pulling your source pointer all the way back to the beginning (like you did in the Naive approach), KMP looks at the last successfully matched character's LPS value: lps[2] = 1 (which corresponds to the character 'a').
    4. This means 1 character ("a") is guaranteed to match right before the mismatch point.
    5. So, you keep the source pointer exactly where it is ('x'), and you slide the pattern so you can continue matching from index 1 of the pattern (the character 'b').

    Now : What is LPS : 
    • Proper Prefix: A prefix that includes any starting substring except the entire string itself.
	• Proper Prefixes of "CODE": "", "C", "CO", "COD"
    
    • Suffix: Any substring that ends at the very last index of the string.
	• Suffixes of "CODE": "", "E", "DE", "ODE", "CODE"
    
    The LPS Rule: At any given index i, lps[i] stores the length of the longest proper prefix of the substring pattern[0...i] that is also a suffix of that exact same substring.

*/

#include <iostream>
using namespace std;

void fillLps(string &patt,vector<int>&lps)
{
    int len=0; int i=1;
    lps[0]=0; //always

    while(i<patt.length())
    {
        if(patt[i]==patt[len])
        {
            len++;
            lps[i]=len;
            i++;
        }
        else
        {
            if(len==0) {
                lps[i]=0;
                i++;
            }
            else 
            {
                //"Agar mismatch j par hua hai, toh j ko wapas lps[j-1] par bhejo.
                //because characters before lps[j-1] are sured to match
                //Aur i (source pointer) ko apni jagah par hi rehne do."
                len=lps[len-1];
            }
        }
    }

}
using namespace std;

int main() {
    //Happy Coding
    //vecotr only increase its size when used with push_back()
    //wrong :: vector<int> lps; Segmentation fault
    //so initialize it 
    string a = "ababc";
    vector<int> lps(a.length(),0);
    
    fillLps(a,lps);

    for(int i : lps)
    {
        cout<<i<<" ";
    }
    return 0;
}