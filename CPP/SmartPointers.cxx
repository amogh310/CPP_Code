#include <iostream>
/*

    A. std::unique_ptr (Exclusive Ownership)

    • Design Purpose: Modeled for strict 1:1 exclusive ownership topologies where a resource belongs to exactly one manager at any given moment.
    • Mechanics: It carries zero memory or performance overhead compared to a raw pointer. Copy semantics are explicitly deleted (non-copyable). Ownership can only be transferred using move semantics (std::move).

    B. std::shared_ptr (Shared Ownership)

    • Design Purpose: Modeled for non-deterministic resource lifetimes where multiple subsystems must read/write to the exact same memory context.
    • Mechanics: Manages a hidden heap-allocated Control Block containing a Reference Counter.
        • Copying increases the reference count by 1.
        • Destruction decreases the reference count by 1.
        • The managed object is deleted when the reference counter hits exactly 0.

    C. std::weak_ptr (Non-Owning Observer)

    • Design Purpose: Introduced as a non-owning companion to std::shared_ptr to safely inspect an object's existence without preventing its destruction. Crucial for breaking circular dependencies (memory cycles).
    • The .lock() Rule: A std::weak_ptr cannot access data directly. To prevent data from being deleted mid-operation by a separate thread, you must invoke .lock(). This executes an atomic check: if the object is alive, it temporarily promotes the weak pointer to a full std::shared_ptr, guaranteeing memory stability during processing.

*/

class Resource 
{
    public:
        std::string name;
        Resource(std::string n) : name(n) { std::cout << "[+] " << name << " created on Heap.\n"; }
        ~Resource() { std::cout << "[-] " << name << " destroyed and freed from Heap.\n"; }
        void process() { std::cout << "    " << name << " in process.\n"; }
};

void uniquePointer()
{
    // Allocation: Single trip, exception-safe initialization via make_unique
    std::unique_ptr<Resource>ptr1 = std::make_unique<Resource>("Amogh");
    ptr1 -> process();

    // std::unique_ptr<Resource> ptr2 = ptr1; // COMPILE ERROR: Cannot copy unique ownership!
    std::unique_ptr<Resource>ptr2 = std::move(ptr1); //ownership transfer

    if (!ptr1) std::cout << " -> ptr1 is now empty (nullptr).\n";
    if (ptr2)  std::cout << " -> ptr2 now exclusively owns the resource.\n";
    ptr2->process();

} //unique Resource (object with string "Amogh") is destroyed the class object itself ; 

void sharedPointer()
{
    //weak_pointer outside : check scope
   std::weak_ptr<Resource> weakObserver ;
   {
        std::shared_ptr<Resource> ptr1 = std::make_shared<Resource>("Amogh");
        std::cout << " -> Initial reference count: " << ptr1.use_count() << "\n";
        
        //sharing the Amogh object with the ptr2
        std::shared_ptr<Resource> ptr2 = ptr1;
        std::cout << " -> Initial reference count: " << ptr1.use_count() << "\n";
        std::cout << " -> After reference count: " << ptr2.use_count() << "\n";

        //Assigning weak observer //no increase in reference count
        weakObserver = ptr1;
        std::cout << " -> Count after attaching weak observer: " << ptr1.use_count() << "\n";

        // Using the weak pointer while the resource is ALIVE
        // You cannot read data directly from a weak_ptr. You must promote it using .lock()
        if(std::shared_ptr<Resource>lockPtr = weakObserver.lock())
        {
            lockPtr -> process();
        }
    } 

    std::cout << "--- Outside Inner Scope ---\n";
    std::cout << " -> Current reference count: " << weakObserver.use_count() << "\n";

    // Resetting the final owner to force-drop the reference count to 0
    std::cout << "Manually resetting final shared owner...\n";
    
    /* NOTE: If you don't reset manually, this happens automatically when the 
    variable goes out of scope. We reset here to explicitly show the destruction. */
    // Object is wiped here!

    // Using the weak pointer after the resource is DEAD
    if (std::shared_ptr<Resource> lockedPtr = weakObserver.lock()) 
    {
        lockedPtr->process();
    } 
    else 
    {
        std::cout << " -> [weak_ptr check]: Promotion failed! Object was already deleted.\n";
    }
}

int main() {
    
    uniquePointer();
    sharedPointer();

    return 0;
}