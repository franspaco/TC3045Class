
#include "gtest/gtest.h"
#include "Hierarchy.h"

template<class T>
class Fixture : public :: testing::Test { 
public:
        Parent * parent;
    void SetUp(){
        parent = new T;
    }
    void TearDown(){
        delete parent;
    }
};

typedef :: testing::Types<Child1, Child2, Child3> implementations;

TYPED_TEST_CASE(Fixture, implementations);

TYPED_TEST(Fixture, testDoSomething){
    this->parent->doSomething();
}

