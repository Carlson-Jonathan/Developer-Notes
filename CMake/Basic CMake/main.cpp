#include <iostream>
#include "calculator.h"
#include "textOutputter.h"
using namespace std;

int main() {

    Calculator calculator;
    TextOutputter gib;


    int x = 654;
    int y = 456;
    string sentence = "Here is some sentence.";

    cout << "The sum of " << x << " and " << y << " is " << calculator.add(x, y) << endl;
    cout << gib.makeGibberish(sentence) << endl;

    return 0;
}
