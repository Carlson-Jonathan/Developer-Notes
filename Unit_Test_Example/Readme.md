This is a brief tutorial with examples of unit testing. There are three kinds of
C++ unit test methods- one using only C++ code another using Google Test, and
a third using UnitTest++. In any folder, compile the unit tests using CMake and run:
    - mkdir build
    - cd build
    - cmake ..
    - make

A unit test 
    is a function that tests another function.
    tests functions at their lowest level.
    promotes clean coding practices.
    helps identify bugs early on.
    helps us plan code before we write it.

Good unit tests
    test one thing at a time.
    tell exactly what test case broke and how.
    takes no input and returns a boolean.
    are stand-alone (no reliance on other tests).
    are up-to-date with the source code.
    work the same 100% of the time.
    cover all edge cases and extreme inputs.
    are simple and easy to read.

Un-testable (unit testable) functions
    are excessivly long.
    do multiple things.
    return nothing (logs/pass-by-reference/etc).
    are high-level.

---------------------------------------------------------------

Google Test Installation (Pretty much the same for UnitTest++):
1.) Clone the repository: https://github.com/google/googletest
2.) cd into the repository and build
    - mkdir build
    - cd build
    - cmake ..
    - make
    - sudo make --install

CMake Lines needed: 
    - find_package(GTest REQUIRED)
    - target_link_libraries(<exe> GTest::GTest GTEST_LIBS)

Source Code Include:
    - #include <gtest/gtest.h>

