
#include <vector>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <stdio.h>
#include "MemCheck.h"

static int countScanner = 0;

class Scanner : public MemCheck{
public: 
    bool checkPort(int port){
        std::string command = "netstat -ltun | grep \":" + std::to_string(port) + " \"";
        FILE* out = popen(command.c_str(), "r");
        
        if(out == nullptr){
            return false;
        }
        char * line = NULL;
        size_t len = 0;
        ssize_t read;
        bool value = false;
        if ((read = getline(&line, &len, out)) != -1) {
            value = true;
        }
        
        fclose(out);
        free(line);
        return value;
    }

    std::vector<int> getOpenPortList(){
        std::vector<int> list;
        for(int i = 10; i < 2000; i++){
            if(checkPort(i)){
                list.push_back(i);
            }
        }
        return list;
    }
};