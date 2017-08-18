#include "TypedValueParamEx.h"

using ::testing::Values;
using ::testing::ValuesIn;

template<class T>
class Fixture : public :: testing::Test { 
public:
        T * data;
    void SetUp(){
        data = new T;
    }
    void TearDown(){
        delete data;
    }
};

typedef :: testing::Types<char, int, float> implementations;

TYPED_TEST_CASE_P(Fixture);

//INSTANTIATE_TYPED_TEST_CASE_P(enteros, Fixture, Values(1,2,3,4,5));

TYPED_TEST_P(Fixture, PrintsData){
    for (TypeParam value : foo_test<TypeParam>::_range_) {
        //EXPECT_GT(value,0);
        //printValue(value);
        std::cout << value << std::endl;
    }
    
    //printValue(n);
}

REGISTER_TYPED_TEST_CASE_P(Fixture, PrintsData);

typedef ::testing::Types<char, int, float> MyTypes;
INSTANTIATE_TYPED_TEST_CASE_P(My, Fixture, MyTypes);

template<> std::vector<char> foo_test<char>::_range_{'1','2','3'};
template<> std::vector<int> foo_test<int>::_range_{1,2,3};
template<> std::vector<float> foo_test<float>::_range_{1.1,2.2,0.0};
