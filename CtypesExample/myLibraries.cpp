#include <iostream>
 
extern "C" {
    int addTwoNumbers(int a, int b) { return a + b; }
    int subtractTwoNumbers(int a, int b) { return a - b; }
    int multiplyTwoNumbers(int a, int b) { return a * b; }
    int divideTwoNumbers(int a, int b) { 
        if(!b) return 0;
        return a / b;
    }
}
