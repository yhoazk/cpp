
#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "mock_calc.h" // not possible to add a cpp file as header in bazel

class basic_math_test : public ::testing::Test {
    protected:
    basic_math_test(){}

    virtual ~basic_math_test(){}
    virtual void SetUp(){
        mTestObj = new basic_math();
    }

    virtual void TearDown(){
        delete mTestObj;
    }
    basic_math *mTestObj;
};

TEST_F(basic_math_test, testAddition){
    // here the mock gets called
    mock_basic_math basictest;
    EXPECT_CALL(basictest, addition(2,3)).Times(1);
    EXPECT_EQ(5,basictest.addition(2,3));
}

// Here is a weird decision to take the protected and operate over it
TEST_F(basic_math_test, testMultiplication){
    EXPECT_EQ(6, mTestObj->multiply(2,3));
}

TEST_F(basic_math_test, testDivide){
    EXPECT_EQ(6, mTestObj->divide(60,10));
}