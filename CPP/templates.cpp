#include<iostream>
using namespace std;

//Generic, reusable code without duplicating logic for every type.
//Eg. one vector class can be used for vector<int> and vector<double>
template < typename t>

class GenericClass
{
    private:
        t value;
    public:
        explicit GenericClass(t value) ;

        t getValue()const
        {
            return value;
        }

        void setValue(t input)
        {
            value = input;
        }
};

template<typename t>GenericClass<t>::GenericClass::GenericClass(t value):value(value){}

int main (void)
{
    GenericClass<int>integerClass(10);

    cout<<integerClass.getValue();
    integerClass.setValue(15);
    cout<<integerClass.getValue();

    return 0;
}