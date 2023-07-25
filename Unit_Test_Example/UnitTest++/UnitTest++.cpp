#include <UnitTest++.h>
#include "sourceCode.h"

class UnitTestPlusPlus : public SourceCode {
public:
    int addTwoNumbers(int a, int b)      { return obj.addTwoNumbers(a, b);      }
    int subtractTwoNumbers(int a, int b) { return obj.subtractTwoNumbers(a, b); }
    int multiplyTwoNumbers(int a, int b) { return obj.multiplyTwoNumbers(a, b); }
    int divideTwoNumbers(int a, int b)   { return obj.divideTwoNumbers(a, b);   }

    SourceCode obj; 
};

TEST(SourceCode_AdditionTest) {
    UnitTestPlusPlus obj;
    CHECK_EQUAL(5, obj.addTwoNumbers(2, 1));         // Note that some tests are
    CHECK_EQUAL(10, obj.addTwoNumbers(5, 5));        // intentionally broken.
    CHECK_EQUAL(0, obj.addTwoNumbers(-5, 5));
}

TEST(SourceCode_SubtractionTest) {
    UnitTestPlusPlus obj;
    CHECK_EQUAL(5, obj.subtractTwoNumbers(8, 3));
    CHECK_EQUAL(-10, obj.subtractTwoNumbers(0, 5));
    CHECK_EQUAL(0, obj.subtractTwoNumbers(-5, -5));
}

TEST(SourceCode_MultiplicationTest) {
    UnitTestPlusPlus obj;
    CHECK_EQUAL(6, obj.multiplyTwoNumbers(2, 3));
    CHECK_EQUAL(0, obj.multiplyTwoNumbers(5, 0));
    CHECK_EQUAL(-25, obj.multiplyTwoNumbers(2, -5));
}

TEST(SourceCode_DivisionTest) {
    UnitTestPlusPlus obj;
    CHECK_EQUAL(2, obj.divideTwoNumbers(6, 3));
    CHECK_EQUAL(0, obj.divideTwoNumbers(0, 5));
    CHECK_EQUAL(-1, obj.divideTwoNumbers(-10, 10));
    CHECK_EQUAL(0, obj.divideTwoNumbers(10, 0)); 
}

int main() {
    return UnitTest::RunAllTests();
}
