#include <iostream>
using namespace std;

//global static : has the scope of the file 
/*
 generally used with another file where linker connects that files .o/.out with this files .o/.out (windows/linux)
 used in the pair (static - extern ) 
*/
static int globalStatic =100;

//inline Static 
/* A local static variable is initialized only once the first time 
 control passes through its definition. Its lifetime lasts until 
 the program ends, but its scope remains local to the function.
*/
 void counter(){
    static int count;
    count++;
    cout<<count<<" ";
}

//Class Static : 
/*
 Here, the static variable/function is the attribute of the class and can be called without its object
*/

class student
{
    private:
    // Belongs to the class itself, not to any individual object.
    // There is only one copy shared by all instances of Counter.
    static int studentsCount;

    public:
    student(){studentsCount++;}
    
    //function belonging to class itself : see the declaration 
    static int returnStudentCount(){ return studentsCount;}

};

//before c++11 outside initialization was necessary,now can be initialised while declaring also
int student::studentsCount =0;

int main() {
    //Happy Coding
    //Inline Static
    counter();
    counter();
    counter();

    //global staic in another file 

    //class static and static function 
    student a;
    student b;
    student c;

    cout<< student::returnStudentCount();
    return 0;
}