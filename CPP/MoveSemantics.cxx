#include <iostream>

/*
    Interesting to Know : Vector Implementation

    Let's say you wrote a Buffer class, right? But you won't use this Buffer alone. Often, you will do something like: std::vector<Buffer> my_buffers;
    Now imagine, a vector has a fixed capacity (for example, 4 elements). When you try to add a 5th element using push_back, the vector runs out of space. When this happens, the vector performs these 3 steps behind the scenes:
    
    1. Allocates a new, larger block of memory (usually double the original size).
    2. Shifts all the old elements from the old memory to the new memory.
    3. Deletes the old memory block.
    
    Here is where the twist happens: When the vector shifts the elements in Step 2, it can choose between two paths:
    • Path A (Copying): If your class does not have the noexcept keyword in front of its move constructor, the vector panics. It thinks, "What if it crashes mid-move? The data will be lost!" To play it safe, it creates a Deep Copy of every single element in the new location first, and only then deletes the old ones. This process is very slow.
    • Path B (Moving): If you have added the noexcept keyword to your move constructor, the vector is happy. It knows it is completely safe. Instead of wasting time copying, it directly Moves the elements using your smart shallow copy.
    
    This is exactly why whenever people talk about Move Semantics, std::vector is always mentioned. It is where you see the biggest performance boost!
*/

int main() {
    //Happy Coding
    std::string a = "Happy Coding !";
    std::string b = std::move(a);

    std::cout<<b<<"\n"; // Happy Coding
    std::cout<<a<<"\n"; //prints nothing
    
    return 0;
}