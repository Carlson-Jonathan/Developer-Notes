#include <gtest/gtest.h>
#include <gmock/gmock.h>

class SourceCodeClass {
public:

    int functionA() {
        int x = 5;
        double y = 123.456;
        return functionB(x, y);
    }

    // Functions you intend to mock MUST be declared virtual. Change the source code if needed.
    virtual int functionB(int x, double y) { 
        // We dont care! Mock it! Disable it!
        return 123456789;
    }
};

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

class SourceCodeClass_Mock : public SourceCodeClass {
public:
    // Mocks (disables) functionB in the source code
    MOCK_METHOD(int, functionB, (int, double));
};

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

TEST(SourceCodeClass_Mock, MockSomething) {
    SourceCodeClass_Mock mockObject;

    // Tests that function B is called 1 time in this function after this line. Also verifies that
    // the arguements functionB receives on call are correct. Additional verifications available.
    EXPECT_CALL(mockObject, functionB(5, 123.456)).Times(1);

    mockObject.functionA(); // funcitonB is called via functionA

    /************************************************************************************************
    // You can verify that functionB is actually being mocked by commenting out EXPECT_CALL, and 
    // uncommenting EXPECT_EQ below. When MOCK_METHOD is present in SourceCodeClass_Mock, functionB 
    // returns 0 (does nothing), otherwise it returns 123456789.
    ************************************************************************************************/
    //EXPECT_EQ(mockObject.functionB(5, 123.456), 123456789); 

    // This line should always be included when using EXPECT_CALL for cleanup and maintenence.
    EXPECT_TRUE(testing::Mock::VerifyAndClearExpectations(&mockObject)); 
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

// Used to exeute this example. Do not include in Target code.
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
