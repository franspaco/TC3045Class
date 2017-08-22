
#include "gtest/gtest.h"

using ::testing::EmptyTestEventListener;
using ::testing::InitGoogleTest;

class EventListener : public EmptyTestEventListener {

};

TEST (TcnUno, tname){

}

int main(int argc, char** argv){
    InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}