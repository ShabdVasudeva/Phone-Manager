#ifndef CPUINFO_H
#define CPUINFO_H

#include <string>

struct CpuDataModel {
    std::string model;
    std::string name;
    std::string manufacturer;
    std::string architecture;
    std::string fab;
    std::string coreCount;
    std::string coreDetail;
    std::string frequency;
    std::string governor;
    std::string cpuBit;
    std::string cpuFeatures;
    std::string cpuImplementer;
    std::string cpuPart;
    std::string cpuRevision;
    std::string cpuVariant;
};

CpuDataModel getCpuData();

#endif