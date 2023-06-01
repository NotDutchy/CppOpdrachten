#include "pch.h"

// Rekenkundige functies
int Add(int a, int b) {
    return a + b;
}

int Sub(int a, int b) {
    return a - b;
}

int Divide(int a, int b) {
    return a / b;
}

int Multiply(int a, int b) {
    return a * b;
}

// Test fixture
class MyTest : public ::testing::Test {
protected:
    virtual void SetUp() {
        // init code hier
    }

    virtual void TearDown() {
        // clean-up code hier
    }
};

// Testcase met ASSERT_EQ macro
TEST_F(MyTest, TestAddition) {
    // De feitelijke test
    ASSERT_EQ(Add(2, 2), 4);
}

TEST_F(MyTest, TestSubtraction)
{
    ASSERT_EQ(Sub(4, 2), 2);
}

TEST_F(MyTest, TestDivide)
{
    ASSERT_EQ(Divide(4, 2), 2);
}

TEST_F(MyTest, TestMultiply)
{
    ASSERT_EQ(Multiply(4, 2), 8);
}

int main(int argc, char** argv) {

    // Initialiseer het Google Test-framework
    ::testing::InitGoogleTest(&argc, argv);

    // Voer alle testcases uit
    return RUN_ALL_TESTS();
}