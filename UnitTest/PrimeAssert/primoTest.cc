#include "gtest/gtest.h"
#include "primes.h"

class PrimoTest : public ::testing::Test {
public:
    int checkPrime(int n){
        return isPrime(n);
    }
    void checkRotate(char * str, int length){
        for(int i = 0; i < length; i++){
            rotate(str, length);
        }
    }
    int checkCircular(int n){
        return checkAndRotate(n);
    }
};

TEST_F(PrimoTest, TestPrimo){
    ASSERT_TRUE(checkPrime(199));
}

TEST_F(PrimoTest, TestNoPrimo){
    ASSERT_FALSE(checkPrime(1000));
}

TEST_F(PrimoTest, TestFullRotation){
    int length = 4;
    char str[] = { 'a', 'b', 'c', 'd'};
    char * cpy = (char*)malloc(sizeof(char)*length);
    strcpy(cpy,str);

    checkRotate(str, length);

    ASSERT_STREQ(cpy, str);

    //delete[] str;
    free(cpy);
}

TEST_F(PrimoTest, TestCircular){
    ASSERT_TRUE(checkCircular(19937));
}

TEST_F(PrimoTest, TestNoCircular){
    ASSERT_FALSE(checkCircular(2222222));
}

TEST_F(PrimoTest, TestMuchosPrimos){
    int count = 0;
    for(int i = 2; i <= 1000000; i++){
        count += checkPrime(i);
    }
    ASSERT_EQ(78498, count) << "got " << count;
    // debe haber 78498 primos menores a 1000000
    // https://primes.utm.edu/howmany.html
}