#include <iostream>
using namespace std;

int calcSum(int a) {
    // Base Case: When the number is completely chopped down to 0
    if (a <=9) {
        return a;
    }
    
    // Last digit + recursive call with the remaining digits
    return (a % 10) + calcSum(a / 10);
}

int main() {
    // Happy Coding
    int x = 144356; 
    cout << calcSum(x); // Outputs: 23
    return 0;
}
