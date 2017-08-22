
/*
C++14  !!!!!!!!
*/

#include <stdio.h>
#include <string>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <chrono>
#include <future>
#include <thread>
#include "gtest/gtest.h"
using namespace std;
using ::testing::EmptyTestEventListener;
using ::testing::InitGoogleTest;
using ::testing::UnitTest;
using ::testing::TestEventListeners;
using ::testing::TestPartResult;
using ::testing::TestInfo;
using ::testing::TestCase;

class Stopwatch {
private:
    clock_t start_time;
public:
    void start(){
        start_time = clock();
    }

    double ElapsedMillis(){
        clock_t finish = clock();
        double period = ((double)finish-(double)start_time)/CLOCKS_PER_SEC;
        return period;
    }
};

class EventListener : public EmptyTestEventListener {
private:
    FILE * file;
    string fileName;
    Stopwatch swTest;
    Stopwatch swCase;
    void OpenFile(){
        file = fopen (fileName.c_str(), "w+");
    }

public:
    EventListener(){
        fileName = "Log.txt";
        OpenFile();
    }
    EventListener(string _fileName){
        fileName = _fileName;
        OpenFile();
    }
    ~EventListener(){
        fclose(file);
    }
    virtual void OnTestProgramStart(const UnitTest& ut) {
        fprintf(file, "[Starting Test]\n");
    }

    virtual void OnTestCaseStart(const TestCase& tc) {
        fprintf(file, "\n######################\nStarting:\n");
        fprintf(file, "Test Case: %s\n", tc.name());
        swCase.start();
    }

    virtual void OnTestCaseEnd(const TestCase& tc) {
        double exec_time = swCase.ElapsedMillis();
        int total = tc.total_test_count();
        int pass = tc.successful_test_count();
        int fail = tc.failed_test_count();
        fprintf(file, "\nFINISHED TEST CASE!\nRun time for %s: %lf\n", tc.name(), exec_time);
        fprintf(file, "TOTAL TESTS: %i\nPASSED: %i tests.\nFAILED: %i tests.\n", total, pass, fail);
    }

    virtual void OnTestStart(const TestInfo& ti){
        fprintf(file, "\n===========\nStarting:\n");
        fprintf(file, "Test Name: %s\n", ti.name());
        swTest.start();
    }

    virtual void OnTestPartResult(const TestPartResult& tpr){
        if(tpr.failed()){
            // test Failed!
            fprintf(file, "Failure:\nIn line: %i\n%s\n", tpr.line_number(), tpr.summary());
        }
        else {
            // ??
        }
    }

    virtual void OnTestEnd(const TestInfo& ti){
        double exec_time = swTest.ElapsedMillis();
        fprintf(file, "FINISHED!\nRun time for %s: %lf\n", ti.name(), exec_time);
    }
};

TEST (TcnUno, tname){
    ASSERT_EQ(1, -1);
}

TEST (TcnUno, tname2){
    ASSERT_EQ(1, 1);
}

TEST (TcnUno, tname3){
    FAIL();
}

class InfClass {
public: 
    void infiniteMethod(){
        while(true){}
    }
};

TEST (TcnTimeout, Test1) {
    InfClass object;
    promise<bool> promisedFinished;
    auto futureResult = promisedFinished.get_future();
    std::thread([](std::promise<bool>& finished, InfClass & obj) {
        obj.infiniteMethod();
        finished.set_value(true);
    }, std::ref(promisedFinished), std::ref(object)).detach();
    
    EXPECT_TRUE(futureResult.wait_for(std::chrono::milliseconds(100))!= std::future_status::timeout);
}

int main(int argc, char** argv){
    InitGoogleTest(&argc, argv);
    ::testing::TestEventListeners& listeners = UnitTest::GetInstance()->listeners();
    delete listeners.Release(listeners.default_result_printer());
    listeners.Append(new EventListener);
    return RUN_ALL_TESTS();
}