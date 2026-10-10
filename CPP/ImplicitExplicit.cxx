/*
    Notes: 
    Explicit keyword is used to prevent the compiler from performing automatic (implicit) type conversions through constructors or conversion operators. It ensures that object creation and type casting only happen when you specifically request them

*/
#include <iostream>

class MyVector
{
    public: 
        // MyVector(int size)
        // {
        //     std::cout<<"Vector Size "<<size<<std::endl;
        // }

        explicit MyVector(int size)
        {
            std::cout<<"Vector Size "<<size<<std::endl;
        }
        
};

//Null function
void printVector(const MyVector& vecObj){}

int main() {
    //Happy Coding

    // MyVector v = 10;     // Compiles! Implicitly converts 10 -> MyVector(10)
    // printVector(42);     // Compiles! Accidentally allocates a vector of size 42
    
    MyVector v1(10);                // Direct initialization allowed
    MyVector v2 = MyVector(10);     // Explicit construction allowed
    printVector(MyVector(42));      // Allowed

    
    return 0;
}