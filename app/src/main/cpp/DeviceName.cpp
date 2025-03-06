#include <fstream>
#include <string>
#include "DeviceName.h"

std::string getDeviceName(){
    std::ifstream file("/system/build.prop");
    std::string line;
    if (file.is_open() && std::getLine(file, line))
    {
        return line;
    }
    return "Unknown device";
}