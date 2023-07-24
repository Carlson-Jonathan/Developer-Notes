/*******************************************************************************
 * TESTHARNESS.H USAGE
 * To add a new unit test file to the test harness:
 *     1.) #include your file name in the designated place.
 *     2.) Add your unit test names as strings to the 'testNames' array.
 *     3.) Add your unit test calls to the 'results' array.
 ******************************************************************************/
#ifndef TESTHARNESS_H
#define TESTHARNESS_H

#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

// Add your unit test include here:
#include "unitTests.h"

class TestHarness {
public:
    TestHarness() {
        assertTests();
    }

private:
    VanillaUnitTests unitTests;

    // Add the name of your unit test as a string to this list:
    vector<string> testNames = {"addTwoNumbers_test()", 
                                "subtractTwoNumbers_test()",
                                "multiplyTwoNumbers_test()", 
                                "divideTwoNumbers_test()"};

    // Add your unit test function call to this list. Make sure the order of  
    // tests is the same as the 'testNames' list above:
    vector<bool> results = {unitTests.addTwoNumbers_test(), 
                            unitTests.subtractTwoNumbers_test(),
                            unitTests.multiplyTwoNumbers_test(), 
                            unitTests.divideTwoNumbers_test() };

    // -------------------------------------------------------------------------

    int numUnitTests = testNames.size();

    void assertTests() {
        cout << "\n\n";
        for(int i = 0; i < numUnitTests; i++) {
            cout << setw(getLongestStrLen()) << testNames[i] << ": ";
            if(!results[i])
                cout << "FAILED! * (See 'unitTestErrors.log')" << endl;
            else
                cout << "Passed" << endl;
        }
        cout << "\n\n";
    }

    // -------------------------------------------------------------------------

    int getLongestStrLen() {
        int longest = 0;
        for(int i = 0; i < numUnitTests; i++) {
            int newLen = testNames[i].length();
            if(newLen > longest)
                longest = newLen;
        }
        return longest;
    }
};

int main() {
    TestHarness testHarness;
    return 0;    
}

#endif // TESTHARNESS_H