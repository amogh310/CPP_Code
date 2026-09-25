#include <iostream>

using namespace std;
int jos (int n , int k){
    if(n==1)return 0;
    return (jos(n-1,k)+k)%n;
}
int main() {
    //Happy Coding
    cout<<jos(7 , 3);
    return 0;
}