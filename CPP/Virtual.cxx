#include <iostream>
using namespace std;


/*
Virtual keyword logic table : 

Pointer	    Actual_object	Virtual?	Result
Animal*	    Animal	        ❌	       Animal
Animal*	    Animal	        ✅          Animal
Animal*	    Dog	            ❌	       Animal
Animal*	    Dog	            ✅	       Dog 

*/
class Animal 
{
    public:
    virtual void speak()
    {
        cout<<"Animal";
    }
    void walk(){
        cout<<"Animal";
    }
};

class Dog:public Animal
{
    public: 
    void speak() override{
        cout<<"Dog";
    }
    void walk(){
        cout<<"Dog";
    }
};

int main() {
    //Happy Coding

    //logic from dog is called : virtual 
    //pointer used here 
    Animal *a = new Dog();
    a->speak();

    cout<<endl;

    //logic from animanl is called : No virtual
    //reference used here 
    Dog d;
    Animal& x= d;
    x.walk();

    cout<<endl;

    //Normal object used
    Dog i;
    Animal j =i;
    j.walk();
    return 0;

    /* 
    Little extra down_casting example :Dog* d = dynamic_cast<Dog*>(a);
    this is also possible 
    */
}