
#include "Scanner.h"

int main(int argc, char** argv){
    Scanner s;
    std::vector<int> cosa = s.getOpenPortList();

    for(int i: cosa){
        std::cout << "OPEN: " << i << std::endl;
    }
}