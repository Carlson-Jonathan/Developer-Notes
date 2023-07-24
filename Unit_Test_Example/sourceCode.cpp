#include "sourceCode.h"    

int SourceCode::addTwoNumbers     (int a, int b) {return a + b;}
int SourceCode::subtractTwoNumbers(int a, int b) {return a - b;}
int SourceCode::multiplyTwoNumbers(int a, int b) {return a * b;}
int SourceCode::divideTwoNumbers  (int a, int b) {
    if(!b) return 0;
    return a / b;
}