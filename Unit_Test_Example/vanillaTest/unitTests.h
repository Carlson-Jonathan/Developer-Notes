/*******************************************************************************
 * Vanilla C++ Unit Test Pattern Example:
 *     1.) Set your test cases.
 *     2.) Call your function.
 *     3.) Assert your results.
 *         * Outputs failed test cases to a log file.
 ******************************************************************************/
#ifndef UNITTESTS_H
#define UNITTESTS_H

#include <iostream>
#include <fstream>
using namespace std;

#include "sourceCode.h"

class VanillaUnitTests {
public:

    VanillaUnitTests() {
        logFile.open("unitTestErrors.log");
        logFile << "";
        logFile.close();
    }

    ofstream logFile;
    SourceCode sourcecode;
    string errorFile = "unitTestErrors.log";

    // -------------------------------------------------------------------------

    bool addTwoNumbers_test() 
    {
        // Set your test cases:
        int testCases_p1[]    = {-1, 0,  1, 3911, 0,  -500};
        int testCases_p2[]    = { 3, 5, -9, 4000, 0,  -800}; // Contains intentionally
        int expectedResults[] = { 7, 5, -8, 7911, 0, -1400}; // broken tests
        int numberOfTestCases = sizeof(testCases_p1) /       
                                sizeof(testCases_p1[0]);
        int actualResults[numberOfTestCases];
        bool passed = true;

        // Call your functions:
        for(int i = 0; i < numberOfTestCases - 1; i++) {
            actualResults[i] = sourcecode.addTwoNumbers(testCases_p1[i],
                                                        testCases_p2[i]);
        }

        // Assert your results:
        logFile.open(errorFile, ios::app);
        for(int i = 0; i < numberOfTestCases - 1; i++) {
            if(actualResults[i] != expectedResults[i]) {
                logFile << "UNIT TEST FAILED: addTwoNumbers_test() - test " << (i + 1) << "\n"
                        << "\tParameter 1: " << testCases_p1[i] << "\n"
                        << "\tParameter 2: " << testCases_p2[i] << "\n"
                        << "\tExpected Result: " << expectedResults[i] << "\n"
                        << "\tTest Output: " << actualResults[i] << "\n"
                        << "---------------------------------------------------------\n";
                passed = false;
            }
        }
        logFile.close();
        return passed;
    }

    // -------------------------------------------------------------------------

    bool subtractTwoNumbers_test() 
    {
        // Set your test cases:
        int testCases_p1[]    = {999,  51, 0,          0,  50, -25};
        int testCases_p2[]    = {999, 100, 0,  123456789, -50, -50}; // Contains intentionally
        int expectedResults[] = {900, -50, 0, -123456789, 100,  25}; // broken tests
        int numberOfTestCases = sizeof(testCases_p1) / 
                                sizeof(testCases_p1[0]);
        int actualResults[numberOfTestCases];
        bool passed = true;

        // Call your functions:
        for(int i = 0; i < numberOfTestCases - 1; i++) {
            actualResults[i] = sourcecode.subtractTwoNumbers(testCases_p1[i],
                                                        testCases_p2[i]);
        }

        // Assert your results:
        logFile.open(errorFile, ios::app);
        for(int i = 0; i < numberOfTestCases - 1; i++) {
            if(actualResults[i] != expectedResults[i]) {
                logFile << "UNIT TEST FAILED: subtractTwoNumbers_test() - test " << (i + 1) << "\n"
                        << "\tParameter 1: " << testCases_p1[i] << "\n"
                        << "\tParameter 2: " << testCases_p2[i] << "\n"
                        << "\tExpected Result: " << expectedResults[i] << "\n"
                        << "\tTest Output: " << actualResults[i] << "\n"
                        << "---------------------------------------------------------\n";
                passed = false;
            }
        }
        logFile.close();
        return passed;
    }        

    // -------------------------------------------------------------------------

    bool multiplyTwoNumbers_test() 
    {
        // Set your test cases:
        int testCases_p1[]    = { 5,  -5,   5, 0, 5, -5,  0};
        int testCases_p2[]    = { 5,   5,  -5, 5, 0, -5,  0};
        int expectedResults[] = {25, -25, -25, 0, 0, 25,  0};
        int numberOfTestCases = sizeof(testCases_p1) / 
                                sizeof(testCases_p1[0]);
        int actualResults[numberOfTestCases];
        int passed = true;

        // Call your functions:
        for(int i = 0; i < numberOfTestCases - 1; i++) {
            actualResults[i] = sourcecode.multiplyTwoNumbers(testCases_p1[i],
                                                             testCases_p2[i]);
        }

        // Assert your results:
        logFile.open(errorFile, ios::app);
        for(int i = 0; i < numberOfTestCases - 1; i++) {
            if(actualResults[i] != expectedResults[i]) {
                logFile << "UNIT TEST FAILED: multiplyTwoNumbers_test() - test " << (i + 1) << "\n"
                        << "\tParameter 1: " << testCases_p1[i] << "\n"
                        << "\tParameter 2: " << testCases_p2[i] << "\n"
                        << "\tExpected Result: " << expectedResults[i] << "\n"
                        << "\tTest Output: " << actualResults[i] << "\n"
                        << "---------------------------------------------------------\n";
                passed = false;
            }
        }
        logFile.close();
        return passed;
    }  

    // -------------------------------------------------------------------------

    bool divideTwoNumbers_test() 
    {
        // Set your test cases:
        int testCases_p1[]    = {99, 88, 110, -200, 8, -500,  50, 200,  0};
        int testCases_p2[]    = {33, 22,  30,   50, 0, -100, 200, -50, 10};
        int expectedResults[] = { 3,  4,   3,   -4, 0,    5,   0,  -4,  0};
        int numberOfTestCases = sizeof(testCases_p1) / 
                                sizeof(testCases_p1[0]);
        int actualResults[numberOfTestCases];
        bool passed = true;

        // Call your functions:
        for(int i = 0; i < numberOfTestCases - 1; i++) {
            actualResults[i] = sourcecode.divideTwoNumbers(testCases_p1[i],
                                                        testCases_p2[i]);
        }

        // Assert your results:
        logFile.open(errorFile, ios::app);
        for(int i = 0; i < numberOfTestCases - 1; i++) {
            if(actualResults[i] != expectedResults[i]) {
                logFile << "UNIT TEST FAILED: divideTwoNumbers_test() - test " << (i + 1) << "\n"
                        << "\tParameter 1: " << testCases_p1[i] << "\n"
                        << "\tParameter 2: " << testCases_p2[i] << "\n"
                        << "\tExpected Result: " << expectedResults[i] << "\n"
                        << "\tTest Output: " << actualResults[i] << "\n"
                        << "---------------------------------------------------------\n";
                passed = false;
            }
        }
        logFile.close();
        return passed;
    } 
};

#endif // UNITTESTS_H