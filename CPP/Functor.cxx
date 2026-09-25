/*
    Functor : Function Pointer 
/ A functor (function object) is created by overloading the parenthesis operator '()'.
// This allows an instance (object) of a class or struct to be called just like a regular function.struct Square {
// Overloading the parenthesis operator '()' using the 'operator' keyword.
// The first '()' specifies the operator being overloaded.
// The second '(int x)' defines the input parameter.int operator()(int x) const {return x * x;}};
*/

#include <iostream>
using namespace std; 

struct Square
{
    //const is added to preserve the read only status of the functor if called with const 
    //const indicates that the internal state of the struct is unchanged
    
    int operator()(int x) const
    {
        return x*x;
    }

    int operator()(int x , int y) const
    {
        return x*y;
    }
};
int main(void){
    Square mySquare;
    int area = mySquare(5);
    cout<<area<<endl;

    area = mySquare(5,10);
    cout<<area<<endl;

    //read-only state of struct 
    const Square myConstSquare;
    area=myConstSquare(7);
    cout<<area<<endl;

    return 0;
}