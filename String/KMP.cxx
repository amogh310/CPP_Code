/*
    Knuth-Morris-Pratt algorithm
    Chaliye aapke hi example (source = "abc", pattern = "aa") par bilkul step-by-step dry-run karke dekhte hain ki KMP kaise kaam karta hai aur iska magic asli hai ya fake.

    Step 1: Pehle Setup Dekhte Hain

    • Source: "abc" (Indices: 0='a', 1='b', 2='c')
    • Pattern: "aa" (Indices: 0='a', 1='a')
    • LPS for "aa": [0, 1]
    Hum do pointers lenge:
    • i (Source ke liye) \(\rightarrow \) Shuruat mein 0
    • j (Pattern ke liye) \(\rightarrow \) Shuruat mein 0

    Step 2: KMP Algorithm Kaise Chalega (Live Tracking)


    Iteration 1 (i=0, j=0):

    • source[0] hai 'a' aur pattern[0] hai 'a'.
    • Match ho gaya! Dono pointers aage badhenge: i++ aur j++.
    • Ab i = 1 aur j = 1.

    Iteration 2 (i=1, j=1):

    • source[1] hai 'b' aur pattern[1] hai 'a'.
    • Mismatch hua! ('b' != 'a').

    Step 3: Yahan Aata Hai KMP ka Asli Rule (Dhyan se Dekhiye)

    Jab j = 1 par mismatch hua, toh KMP algorithm ka standard rule yeh hota hai:
    "Agar mismatch j par hua hai, toh j ko wapas lps[j-1] par bhejo. Aur i (source pointer) ko apni jagah par hi rehne do."
    • Mismatched index j = 1 hai.
    • Toh hum lps[j-1] yaani lps[0] check karenge.
    • lps[0] ki value kya hai? 0.
    • Iska matlab, j wapas badalkar 0 ho jayega.
    • Aur i abhi bhi 1 (yaani 'b') par hi ruka hua hai!

    Step 4: Agli Iteration (i=1, j=0)

    Ab loop dobara chalega naye j ke sath:
    • source[1] hai 'b' aur pattern[0] hai 'a'.
    • Firse Mismatch hua! ('b' != 'a').
    KMP Rule if j == 0:
    Agar j pehle se hi 0 par hai aur fir bhi mismatch ho jaye, toh breaks apply hote hain. Iska matlab is character par koi ummeed nahi hai, toh hum simply i++ kar dete hain taaki source mein agle char par jaa sakein.
    • i badhkar 2 ho gaya (pointing to 'c').
    • j abhi bhi 0 par hai.

    Step 5: Agli Iteration (i=2, j=0)

    • source[2] hai 'c' aur pattern[0] hai 'a'.
    • Mismatch! ('c' != 'a').
    • Kyunki j == 0 hai, isliye firse i++ hoga. Ab i = 3.
    • Loop khatam kyunki i source ki length (3) tak pahunch gaya. Return -1.

*/

#include <iostream>
using namespace std;
using vec = vector<int>; 


void fillLps(string &pat,vec &lps)
{
    int len=0; int i=1;lps[0]=0;
    while(i<pat.length())
    {
        if(pat[i]==pat[len])
        {
            len++;
            lps[i]=len;
            i++;
        }
        else
        {
            if(len==0)
            {
                i++; //lps[i] value here is 0 
            }
            else
            {
                len=lps[len-1]; //lps[len-1] characters are guranteed to match
            }
        }
    }
}

void kmp(string &source, string& pat, vec &ans)
{
    vec lps(pat.length(),0);
    fillLps(pat,lps);
    
    //printing lps:
    for(int i:lps){cout<<i<<" ";}
    cout<<endl;
    
    //continue with logic : 
    int i=0; int j=0;
    while(i<source.length())
    {
        if(source[i]==pat[j])
        {
            i++;j++;
            if(j==pat.length()) 
            {
                ans.push_back(i-j);
                j=lps[j-1]; //setting j back to check for other entries
            }
        }
        else
        {
           if(j!=0)
           {
            j=lps[j-1]; //lps[j-1] elements are guranteed to match
           }
           else
           {
            i++; //if j==0 i.e. no char matched , no point in checking at ith position , continue
           }
        }
    }
}

int main() {
    //Happy Coding

    string source = "ababcababcabcabc";
    string pat = "abcabc";

    vec ans;
    
    kmp(source,pat,ans);

    for(int i: ans)
    {
        cout<<i<<" ";
    }
    return 0;
}