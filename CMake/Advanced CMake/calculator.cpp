#include "calculator.h"

int Calculator::add(int x, int y) {
    return x + y;
}

int Calculator::subtract(int x, int y) {
    return x - y;
}

int Calculator::multiply(int x, int y) {
    return x * y;
}

int Calculator::divide(int x, int y) {
    if(!y) return 0;
    return x / y;
}
