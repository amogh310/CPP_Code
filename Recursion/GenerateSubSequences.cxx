//From the given String generate the substrings , From set subsets. print em
#include <iostream>
using namespace std;

void subsets(string s , string curr , int i)
{
    if(i== s.length())
    {
        cout<<i<<" "<<curr;
        return;
    }
    subsets(s,curr,i+1);
    //dont use i++ here to avoid : unsequenced modification and access to 'i'
    subsets(s,curr+s[i],i+1);
}
int main(void)
{
    subsets("abc","",0);
    return 0;
}