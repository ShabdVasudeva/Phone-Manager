#include <sys/system_properties.h>
#include <string>
#include "DeviceName.h"

std::string getDeviceName(){
    char name[PROP_VALUE_MAX +1] = {0};
    if(__system_property_get("ro.product.model", name) > 0){
        return std::string(name);
    }
    return "Unknown device";
}