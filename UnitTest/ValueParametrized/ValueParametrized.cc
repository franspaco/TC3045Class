
#include "ValueParametrized.h"
#include "gtest/gtest.h"

using ::testing::Range;
using ::testing::Values;
using ::testing::ValuesIn;
using ::testing::Bool;
using ::testing::Combine;

class Fixture : public ::testing::TestWithParam<int> {};

class Chars : public ::testing::TestWithParam<char> {};

class Bools : public ::testing::TestWithParam<bool> {};

class Combinaciones : public ::testing::TestWithParam< ::testing::tuple<int, int> > {
public:
    int value1 = ::testing::get<0>(GetParam());
    int value2 = ::testing::get<1>(GetParam());
};

TEST_P(Fixture, Test){
    printValue(GetParam());
}

TEST_P(Chars, TestChars){
    printValue(GetParam());
}

TEST_P(Bools, TestBools){
    printValue(GetParam());
}

TEST_P(Combinaciones, TestComb){
    printValues(value1, value2);
}

INSTANTIATE_TEST_CASE_P(enteros, Fixture, Values(1,2,3,4,5));

char arr[] = {'a', 'e', 'i', 'o', 'u'};
INSTANTIATE_TEST_CASE_P(caracteres, Chars, ValuesIn(arr));

INSTANTIATE_TEST_CASE_P(booleanos, Bools, Bool());

INSTANTIATE_TEST_CASE_P(combinacion, Combinaciones, Combine(Range(1,10,1), Range(1,10,1)));