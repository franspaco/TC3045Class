#include <iostream>

class Parent {
public:
    virtual void doSomething() = 0;
};

class Child1 : public Parent {
public:
    void doSomething(){
        std::cout << "Child1" << std::endl;
    }
};

class Child2 : public Parent {
public:
    void doSomething(){
        std::cout << "Child2" << std::endl;
    }
};

class Child3 : public Parent {
public:
    void doSomething(){
        std::cout << "Child3" << std::endl;
    }
};