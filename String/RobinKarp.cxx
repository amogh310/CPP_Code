/*
    Another Pattern Matching Algo is Robin Karp 
    1.Compute Hash values and match 
    2.If hash matched , match characters
   
    =================================================================================================
   
    The Equation

    For a pattern string \(P\) of length \(m\), an alphabet base \(d\) (radix), and a prime modulus \(q\), the hash function \(H(P)\) is defined as:
    \(H(P)=\left(P[0]\cdot d^{m-1}+P[1]\cdot d^{m-2}+\dots +P[m-1]\cdot d^{0}\right)\mathinner{\;\left(\mod \,q\right)}\)

    Core Component Variables:

    • \(d\) (The Base / Radix): This represents the size of your input character alphabet set. In production C++ string architectures, we use \(d = 256\) to seamlessly accommodate standard extended ASCII character byte values.
    • \(q\) (The Modulo Divisor): A large prime number used as a continuous safety cap. It forces math calculations to cycle gracefully inside bounded memory allocations, avoiding structural hardware crashes.
    • \(h\) (The Most Significant Digit Multiplier): Stored dynamically as \(h = d^{m-1} \pmod q\), it represents the place value of the leftmost character in the tracking window. It allows us to discard the old character efficiently in a single step.

    Rolling hash function is:
    T_next = ( d * ( T_current - W_old * h ) + W_new ) % q

    =================================================================================================
    
    1.d= The Counting Base ( 432 is internally , 4*10^2 + 3*10^1 + 2*10^0) that 10 is d
    here , we will be using 256 :no of characters :unique hashing
    
    2.h= weight of outgoing character , (removing 4 from 432 ,need to remove 4* 10 ^ (3(pos)-1));
    here , h = pow(d, m-1) % q :(m = pattern length (3))
    
    3.t_hash (Rolling hash function ):
    432 -> 325
    1.t_hash=current hash-(old char * h) i.e. 432-4*100=32
    2. t_hash *d , i.e. 32 *10 = 320
    3.t_hash final , i.e. 320+5*10^0
    final equation with all three steps: 
    d * (t_hash - source[i] * h) + source[i + m]
    
    4.q (prime modulus)
    high prime number: helps sotrage constraints : 
    
    =================================================================================================
    
*/
#include <iostream>
#include<vector>
using namespace std;

// d is the number of characters in the input alphabet (Base 256 for standard ASCII)
const int d = 256; 
// q is a prime number used to prevent integer overflow. 101 is simple for testing.
const int q = 101; 

void rabinKarpSearch(string &source, string &pattern, vector<int> &ans)
{
    int n = source.length();
    int m = pattern.length();

    if(m>n)return;

    int p_hash =0; //Hash value for pattern
    int t_hash =0; //Hash value for text
    int h =1;

    //Weight of outgoing character : h 
    //so, we take the pattern d^len-1 (10 ^ 3-1);
    //here , pow(d,m-1) same implemented through loop with %q to match variable size constraint
    for(int i=0;i<m-1;i++)
    {
        h=(h*d)%q;
    }

    //Calculate hash value of pattern and first text
    //notice m here and m-1 on line 66 
    for(int i=0;i<m;i++)
    {
        //think like this: 432 
        //p_hash    expr
        //0         10*0+4
        //4         10*4+3
        //43        10*43+2
        //432
        p_hash = (d * p_hash +pattern[i])%q;
        t_hash = (d * t_hash +source[i])%q;

    }

    //Sliding window 
    for(int i=0;i<=n-m;i++)
    {
        //hash matched
        if(p_hash == t_hash)
        {
            int j;
            for( j=0;j<m;j++)
            {
                if(source[i+j] != pattern[j]) break;
            }
            if(j==m)
                ans.push_back(i); //pattern found
        }

        //Rollling hash : (432-400)*10+5
        if(i<n-m)
        {
            t_hash = (d * (t_hash - source[i]*h)+source[i+m])%q;

            //hash_values may become negative here convert them back 
            if(t_hash<0)
                t_hash = t_hash+q;
        }

    }
}

int main() {
    //Happy Coding

    string source = "ababcababcabcabc";
    string pattern = "abcabc";
    vector<int> ans;

    rabinKarpSearch(source, pattern, ans);

    cout << "Rabin-Karp Match Indices: ";
    for (int idx : ans) {
        cout << idx << " ";
    }
    cout << endl;

    return 0;
}