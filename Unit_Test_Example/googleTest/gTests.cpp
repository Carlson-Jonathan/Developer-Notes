#include "sourceCode.h"
#include <gtest/gtest.h>

class GoogleTests : public ::testing::Test {
public:
    int addTwoNumbers(int a, int b)      { return obj.addTwoNumbers(a, b);      }
    int subtractTwoNumbers(int a, int b) { return obj.subtractTwoNumbers(a, b); }
    int multiplyTwoNumbers(int a, int b) { return obj.multiplyTwoNumbers(a, b); }
    int divideTwoNumbers(int a, int b)   { return obj.divideTwoNumbers(a, b);   }

    SourceCode obj; 
};

TEST_F(GoogleTests, AddTest) {
    EXPECT_EQ(addTwoNumbers(2, 3), 5);
    EXPECT_EQ(addTwoNumbers(1, 7), 8);
    EXPECT_EQ(addTwoNumbers(5, 3), 5); // Intentionally broken
    EXPECT_EQ(addTwoNumbers(8, 1), 9);
    EXPECT_EQ(addTwoNumbers(4, 4), 8);
}

TEST_F(GoogleTests, SubtractTest) {
    EXPECT_EQ(subtractTwoNumbers(5, 3), 2);
    EXPECT_EQ(subtractTwoNumbers(9, 3), 6);
    EXPECT_EQ(subtractTwoNumbers(2, 1), 1);
    EXPECT_EQ(subtractTwoNumbers(7, 4), 2); // Intentionally broken
    EXPECT_EQ(subtractTwoNumbers(4, 3), 1);
}

TEST_F(GoogleTests, MultiplyTest) {
    EXPECT_EQ(multiplyTwoNumbers(2, 3), 9); // Intentionally broken
}

TEST_F(GoogleTests, DivideTest) {
    EXPECT_EQ(divideTwoNumbers(10, 2), 5);
    EXPECT_EQ(divideTwoNumbers(10, 0), 0); 
}

int main(int argc, char* argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
