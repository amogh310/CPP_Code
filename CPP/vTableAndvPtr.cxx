/*
Notes: 
Runtime Polymorphism is achieved using the function overriding using the virtual keyword. 
Internally , a vtable ( collection of the function pointers pointing to the virtual functions ) is created for every class

Base* ptr1 = new Base();  // Scenario A
Base* ptr2 = new Child(); // Scenario B

Feature	        Base* ptr1 = new Base();	            Base* ptr2 = new Child();
Object Created	An actual Base object is allocated.	    An actual Child object is allocated.
Internal vptr	Points to the Base vtable.	            Points to the Child vtable.
ptr1->func()	Dispatches to Base::func().	            Dispatches to Child::func() (Overridden).

If we initialise an object of derived class with the pointer of base class (Base* ptr = new Child()),
at the time of destruction only base class destructor will be called hence resulting into undefined behavior
To tackle this , make base class destructor virtual so , first derived destructor and then base destructor

* 1. A Child object is instantiated on the heap. Its internal `vptr` is 
*    initialized by the constructor to point directly to the Child class vtable.
* 2. This object's address is assigned to a Base class pointer (`ptr`).
* 3. When `ptr->func()` is executed, the runtime evaluates the target object's `vptr`,
*    routes to the Child class vtable, and invokes Child::func().

Base* ptr = new Child();
ptr->func();

* 1. A Base reference (`ref`) is bound directly to the Child instance `c`.
* 2. When `ref.func()` is evaluated, the program does not slice the object. 
*    It accesses the true underlying object, follows its `vptr` to the Child vtable,
*    and executes the overridden child implementation.

Base& ref = c;
ref.func();

*/
#include <iostream>


class Base
{
    public:
        virtual void func() { printf("Executing address inside Base::func -> %p\n", (void*)this);}
        virtual ~Base() = default;
};

class Child : public Base
{
public:
    /*
        It is a small C++ trick used to cheat the compiler so it allows us to print a function's real memory address.
        • [](){} (Lambda): This creates a brand-new, unnamed temporary function right inside the code.
        • + (Unary Plus): This forces the compiler to turn that temporary function into a standard, old-school function pointer.
        • (void*): This converts that function pointer into a raw memory address so std::cout can print it as a hex code (like 0x5555...).

    */
    void func() override {    printf("Executing address inside Child::func -> %p\n", (void*)+[](Child* t){ t->func(); });}
};

int main() {
    //Happy Coding

    Child* ptr2 = new Child();
    //this is object slicing 
    //derived object copied into the Base class
    Base * ptr1 = new Child();

    ptr1->func();
    ptr2->func();



    
    return 0;
}