/*
Notes: C++ Copy and Move Semantics

Lvalue and rvalue:** These are expression categories in C++. An lvalue identifies an object, while an rvalue is an expression that can be used as an rvalue, often representing a temporary value. They help determine which overloaded functions or constructors can be called.

Shallow copy:** Copies member values directly. If a class contains an owning raw pointer, this copies the address, so both objects may point to the same allocation. Incorrect ownership can cause double deletion or dangling pointers.

Deep copy:** Duplicates the underlying resource so the destination owns an independent copy.

Copy constructor:** Initializes a new object from an existing object. Typical signature: `T(const T& other)`.

Copy assignment operator:** Copies data into an already-existing object. Typical signature: `T& operator=(const T& other)`.

Move constructor:** Initializes a new object by transferring resources from another object. Typical signature: `T(T&& other) noexcept`.

Move assignment operator:** Transfers resources into an already-existing object, handling its previously owned resources first. Typical signature: `T& operator=(T&& other) noexcept`.

`std::move`:** Casts an expression to an rvalue reference type appropriate for its underlying type. It does not itself transfer resources; a selected move operation performs the transfer.

Rule of 3/5/0:** Resource-managing classes may need coordinated copy and move operations and a destructor. Prefer resource-managing standard-library types so the compiler-generated operations can usually be used (Rule of 0).

*/
#include <iostream>

class Buffer 
{
    private: 
        int * data;
    public:
    //Regular explicit constructor : new int value is assgined while creating object
        explicit Buffer (int value) : data ( new int (value))
        {
            std::cout<<"Constructor ca;?" << *data <<std::endl; // Fixed typo in output for alignment
        }

    //copy constructor : Ab yeh sach mein DEEP COPY karega
        Buffer(const Buffer& BufferObj) : data (new int(*BufferObj.data))
        {
            std::cout<<"Copy Constructor call " <<*data << std::endl;
        }

    //copy assignment operator : deep copying from existing object into existing object
        Buffer& operator = (const Buffer& other)
        {
            //overwriting the existing objects data
            if(this != &other)
            {
                int * newData = new int (*other.data);
                delete data;
                data = newData;
            }

            std::cout<<"Copy Assignment Operator "<<"\n";

            //this object is returned 
            //see its call in main : you will understand why
            return *this;
        }

    //Move constructor: transfer ownership 
    //noexcept : tells compiler "This function will never throw an exception" :makes moving fast
    //&& : rvalue reference : temp 
        Buffer(Buffer && otherObj)noexcept : data(otherObj.data)
        {
            otherObj.data = nullptr;
            std::cout<<" Move constructor call"<<"\n";
        }

    //Move assignment operator : transfer ownership
        Buffer& operator=(Buffer&& otherObj) noexcept
        {
            if(this != &otherObj)
            {
                delete data;
                data=otherObj.data;
                otherObj.data = nullptr;
            }

            std::cout<<"Move assignment. \n";
            return *this;
        }
    
    //destructor
        ~Buffer()
        {
            delete data;
            std::cout<<"Destructor\n";
        }
    
    //getter
        int get() const
        {
            if(data==nullptr)
            {
                return -1; //after std::move(obj)
            }
            return *data;
        }

};


int main() {
    //Happy Coding
    
    Buffer a(100);

    Buffer b = a;  //Copy Constructor : new object
    
    Buffer c(200);
    c=a;           //copy assignment operator : value overwritten

    Buffer d = std::move(a); //move constructor:new object

    Buffer e(300);
    e=std::move(b);  //Move assignment : value moved

    std::cout << "a = " << a.get() << '\n';
    std::cout << "b = " << b.get() << '\n';
    std::cout << "c = " << c.get() << '\n';
    std::cout << "d = " << d.get() << '\n';
    std::cout << "e = " << e.get() << '\n';

    return 0;
}
