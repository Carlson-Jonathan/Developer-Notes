#include <iostream>
#include <UnitTest++.h>
using namespace std;

int add(int a, int b) {
    return a + b;
}

TEST(AdditionTest) {
    CHECK_EQUAL(5, add(2, 3));
    CHECK_EQUAL(10, add(1, 3));
    CHECK_EQUAL(0, add(-2, 5));
}

int main() {
    return UnitTest::RunAllTests();
}
