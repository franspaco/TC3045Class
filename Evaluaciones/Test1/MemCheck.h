
#ifndef MemCheck_H
#define MemCheck_H

#include <stdlib.h>

static int countA = 0;

class MemCheck {
public: 
    void* operator new(std::size_t n){
        countA++;
        //std::cout << "NEW " << ++countA << " | size: " << n << std::endl;
        void* temp = ::operator new(n);
        return temp;
    }

    void* operator new[](std::size_t n){
        countA++;
        //std::cout << "NEW " << ++countA << " | size: " << n << std::endl;
        void* temp = ::operator new(n);
        return temp;
    }

    void operator delete(void * p) {
        countA--;
        //std::cout << "DEL " << --countA << std::endl;
        ::operator delete(p);
    }

    void operator delete[](void * p) {
        countA--;
        //std::cout << "DEL " << --countA << std::endl;
        ::operator delete(p);
    }
};

#endif