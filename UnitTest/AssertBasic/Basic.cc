
#include "gtest/gtest.h"


TEST(TestCaseName, TestName1){
    EXPECT_FALSE(true);
}

TEST(TestCaseName, TestName2){
    ASSERT_TRUE(true);
}

TEST(TestCaseName, TestName3){
    if(true)
        SUCCEED();
}

TEST(TestCaseName, TestName4){
    if(5%3 != 0)
        FAIL() << "FAIL (this was expected)\n";
    SUCCEED() << "Esto no debe imprimirse\n";
}

TEST(TestCaseName, TestName5){
    ADD_FAILURE();
    SUCCEED() << "Should succeed\n";
}

TEST(TestCaseName, TestName6){
    ASSERT_EQ(48, '0');
}

TEST(TestCaseName, TestName7){
    ASSERT_NE(7,5);
}

TEST(TestCaseName, TestName8){
    ASSERT_LT(15, 20);
}

TEST(TestCaseName, TestName9){
    ASSERT_LE(15, 15);
}

TEST(TestCaseName, TestName10){
    ASSERT_GT(50, 1000);
}

TEST(TestCaseName, TestName11){
    ASSERT_GE( 100, 100);
}

TEST(TestCaseName, TestName12){
    ASSERT_STREQ("lol", "lol");
}

TEST(TestCaseName, TestName13){
    ASSERT_STRNE("foo", "bar");
}

TEST(TestCaseName, TestName14){
    ASSERT_STRCASEEQ("FOO", "fOo");
}

TEST(TestCaseName, TestName15){
    ASSERT_STRCASENE("foo", "BAR");
}


void throwsSomehting(){
    throw new std::invalid_argument("FAILURE!!!");
}

void notThrowSomething(){
    // . . . 
}

TEST(TestCaseName, TestName16){
    ASSERT_THROW(throwsSomehting(), std::invalid_argument);
}

TEST(TestCaseName, TestName17){
    ASSERT_ANY_THROW(throwsSomehting());
}

TEST(TestCaseName, TestName18){
    ASSERT_NO_THROW(notThrowSomething());
}

TEST(TestCaseName, TestName19){
    ASSERT_FLOAT_EQ(3.14f, 3.14f);
}

TEST(TestCaseName, TestName20){
    ASSERT_DOUBLE_EQ(3.14159, 3.14159);
}

TEST(TestCaseName, TestName21){
    ASSERT_NEAR(3.14159, 3.1416, 0.11);
}