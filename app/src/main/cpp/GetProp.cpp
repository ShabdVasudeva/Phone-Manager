#include <map>
#include <string>
#include <jni.h>
#include <memory>
#include <iostream>
#include <cstdio>
#include "GetProp.h"

std::string getProp(const char* str){
    std::string result;
    char buffer[128];
    FILE* pipe = popen(str,"r");
    if(!pipe) return "Unknown";
    while(fgets(buffer, sizeof(buffer), pipe) != nullptr){
        result += buffer;
    }
    pclose(buffer);
    if (!result.empty() && result[result.length()-1] == '\n'){
        result.erase(result.length()-1);
    }
    return result;
}