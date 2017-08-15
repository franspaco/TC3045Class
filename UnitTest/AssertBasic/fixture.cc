
#include "Stack.h"
#include "gtest/gtest.h"

class TestStack : public ::testing::Test {
public:
    myStack<int> myst;
    void SetUp(){
        myst.push(10);
        myst.push(20);
    }
    void TearDown(){

    }
};

TEST_F(TestStack, PushTest){
    myst.push(30);
    myst.push(40);
    EXPECT_EQ(4, myst.size());
}

TEST_F(TestStack, PopTest){
    myst.pop();
    myst.pop();
    EXPECT_EQ(0, myst.size());
}