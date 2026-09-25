/*
Given a rope of length N meters, the rope can be cut only in three fixed lengths A, B, and C.
The task is to maximize the number of pieces such that the total length of all pieces is exactly equal to N.

If it is not possible to cut the rope exactly using the given lengths, return -1.
*/
#include <iostream>

using namespace std;

int maxPieces(int size , int a , int b, int c)
{
    if(size==0) return 0;
    if(size<=0) return -1;

    //result
    int res = max ( maxPieces(size-a,a,b,c), max (maxPieces(size-b,a,b,c),maxPieces(size -c,a,b,c)));
    //focus on res == -1 not res <=0 , it fails: 
    //heres why : जब नीचे से 0 (सक्सेस) लौटकर ऊपर आता है, तो आपका कोड if(res <= 0) वाली कंडीशन में फंस जाता है (क्योंकि 0 <= 0 सच है)। आपका कोड उस सही रास्ते को भी जबरदस्ती -1 (फेलियर) में बदल देता है।
    if(res==-1) return -1;
    //if you make two cuts it makes 3 pieces 
    //res = cuts 
    return res+1;
}
int main() {
    //Happy Coding
    cout<<maxPieces(5,2,1,5);
    return 0;
}