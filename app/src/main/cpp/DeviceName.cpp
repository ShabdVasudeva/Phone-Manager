#include <fstream>
#include <string>
#include <DeviceName.h>

std::string getDeviceName(){
    std::ifstream file("/system/build.prop");
    std::string line;
    while (getLine(file, line))
    {
        if (line.find("ro.product.model") != std::string::npos)
        {
            return line.substr(line.find("=")+1);
        }
    }
    return "Unknown device";
}