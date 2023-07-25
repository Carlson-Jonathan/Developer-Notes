/*******************************************************************************
 * Source Code Changes Needed:
 *     Any PRIVATE functions that need to be unit tested must be made accessible 
 *     by prototyping your unit test class, then adding a friend variable. If no
 *     private functions are being tested, no change is needed to the source.
 ******************************************************************************/
#ifndef SOURCECODE_H
#define SOURCECODE_H

#include <iostream>
using namespace std;

class VanillaUnitTests; // Required for unit testing private functions in C++.
class GoogleTests;
class UnitTestPlusPlus;

class SourceCode {
private:
    int addTwoNumbers     (int a, int b);
    int subtractTwoNumbers(int a, int b);
    int multiplyTwoNumbers(int a, int b);
    int divideTwoNumbers  (int a, int b); 

    friend VanillaUnitTests; // Required for unit testing private functions in C++.
    friend GoogleTests;
    friend UnitTestPlusPlus;
};
#endif // SOURCECODE_H
