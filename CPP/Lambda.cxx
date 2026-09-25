/*
    Lambdas allow you to write quick, disposable blocks of code directly where they are needed without defining a separate struct or class
    Anatomy of a Lambda Function: [ capture_clause ] ( parameters ) -> return_type { body }
*/

/*
    Interview Cheat Sheet
        Lambda kya hai?
        A lambda expression is an anonymous callable object that allows defining small functions inline.

        [] kya hai?
        Capture list. It specifies which variables from the surrounding scope the lambda can access.

        [x] vs [&x]?
        [x] captures by value; [&x] captures by reference.

        [=] vs [&]?
        [=] captures required variables by value; [&] captures them by reference.

        [this]?
        Captures the current object's this pointer, allowing access to members inside the lambda.

        Lambda ka use kahan hota hai?
        STL algorithms, callbacks, threads, condition variables, event handling, filtering and custom comparison logic.

        auto kyun?
        Every lambda has a unique unnamed closure type, so auto is commonly used to store it.
*/
#include <iostream>
using namespace std;

int main(void)
{
    //1. Basic inline lambda assigned to a variable
    auto add = [](int a ,int b){ return a+b;};
    cout<<add(5,10)<<endl;

    //2. Using a lambda with a capture clause to filter a vector
    vector<int> numbers = {10, 45, 82, 23, 90, 5};
    int thresholdLimit =40;

    // std::remove_if rearrangements elements based on a boolean predicate (the lambda function).
    // It shifts all elements that match the condition (items > thresholdLimit) to the end of the vector.
    // It returns an iterator pointing to the beginning of this "garbage/unwanted" section.
    
    // Since std::remove_if does not physically delete elements or change the vector's size,
    // we use numbers.erase(). This frees up memory by wiping out everything from the
    // 'separator' memory location all the way to the end of the vector.

    auto seprator = remove_if (numbers.begin(),numbers.end(),[thresholdLimit](int n)->bool {return n>thresholdLimit;});
    numbers.erase(seprator,numbers.end());

    //3.Print remaining items using an inline lambda
    //another STL function 'for_each'
    for_each(numbers.begin(),numbers.end(),[](int n)->void {cout<<n<<" ";});

    return 0;
}