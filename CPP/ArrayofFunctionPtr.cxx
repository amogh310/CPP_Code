//make a calculator
//notice parameters and written types are all same , logic differs

#include <iostream>
using namespace std;

typedef int (*operation)(int* , int *); 

int add(int *a , int *b) { return *a+*b;}
int sub(int *a , int *b) { return *a>*b?*a=*b:*b-*a;}
int multiply(int *a ,int *b){ return *a * *b;}
int divide(int *a , int *b){ return *a/ *b;}

int main(void){
    vector<operation>op;

    op.push_back(add);
    op.push_back(sub);
    op.push_back(multiply);
    op.push_back(divide);

    int a ; int b; char c;
    // cout<<"enter character and numbers : ";
    // cin>>c >>a >>b;
    c='*';
    a=10;
    b=5;
    switch(c)
    {
        case '+':cout<<op[0](&a,&b);break;
        case '-':cout<<op[1](&a,&b);break;
        case '*':cout<<op[2](&a,&b);break;
        case '/':cout<<op[3](&a,&b);break;
        
    }

    return 0;
}