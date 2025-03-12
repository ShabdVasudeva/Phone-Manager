#include <sys/system_properties.h>
#include <string>
#include <fstream>
#include <iostream>
#include "DeviceName.h"

std::string getDeviceName(){
    char name[PROP_VALUE_MAX +1] = {0};
    if(__system_property_get("ro.product.model", name) > 0){
        return std::string(name);
    }
    return "Unknown device";
}

std::string getCPUName() {
    std::ifstream file("/proc/cpuinfo");
    std::string line;
    
    while (getline(file, line)) {
        if (line.find("Processor") != std::string::npos || 
            line.find("model name") != std::string::npos) {  // Some devices use "model name"
            return line.substr(line.find(":") + 2);
        }
    } 
    
    return "Unknown CPU";
}
