
#include "gtest/gtest.h"
#include "Scanner.h"

using ::testing::InitGoogleTest;
using ::testing::EmptyTestEventListener;
using ::testing::UnitTest;
using ::testing::TestEventListeners;
using ::testing::Values;

class EventListener : public EmptyTestEventListener {
public:
    virtual void OnTestProgramEnd(const UnitTest& ut) {
        ASSERT_EQ(0, countA);
    }
};


class TestOpenPorts : public ::testing::TestWithParam<int> {
public: 
    Scanner* sc;

    void SetUp(){
        //std::cout << "#2\n";
        sc = new Scanner();
    }

    void TearDown(){
        delete sc;
    }
};
INSTANTIATE_TEST_CASE_P(openPorts, TestOpenPorts, Values(53, 68, 631));

class TestClosedPorts : public ::testing::TestWithParam<int> {
public: 
    Scanner* sc;

    void SetUp(){
        //std::cout << "#2\n";
        sc = new Scanner();
    }

    void TearDown(){
        delete sc;
    }
};
INSTANTIATE_TEST_CASE_P(closedPorts, TestClosedPorts, Values(20,50, 500, 666));


TEST_P(TestOpenPorts, Test){
    ASSERT_TRUE(sc->checkPort(GetParam()));
}

TEST_P(TestClosedPorts, Test){
    ASSERT_FALSE(sc->checkPort(GetParam()));
}


int main(int argc, char** argv){
    InitGoogleTest(&argc, argv);
    ::testing::TestEventListeners& listeners = UnitTest::GetInstance()->listeners();
    //delete listeners.Release(listeners.default_result_printer());
    listeners.Append(new EventListener);
    return RUN_ALL_TESTS();
}

