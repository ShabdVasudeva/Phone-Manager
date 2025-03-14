#include "CPUInfo.h"
#include <fstream>
#include <sstream>
#include <android/log.h>

#define LOG_TAG "CPUInfo"
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__)

std::map<std::string, std::string> parseProcCpuInfo() {
    std::ifstream cpuFile("/proc/cpuinfo");
    std::map<std::string, std::string> cpuInfo;
    std::string line;

    if (!cpuFile.is_open()) {
        LOGE("Failed to open /proc/cpuinfo");
        return cpuInfo;
    }

    while (std::getline(cpuFile, line)) {
        std::istringstream iss(line);
        std::string key, value;
        if (std::getline(iss, key, ':') && std::getline(iss, value)) {
            cpuInfo[key] = value;
        }
    }

    cpuFile.close();
    return cpuInfo;
}

std::string getCpuGovernor() {
    std::ifstream governorFile("/sys/devices/system/cpu/cpu0/cpufreq/scaling_governor");
    std::string governor;
    
    if (governorFile.is_open()) {
        std::getline(governorFile, governor);
        governorFile.close();
    } else {
        governor = "Unknown";
    }
    
    return governor;
}

std::string getCpuMaxFrequency() {
    std::ifstream freqFile("/sys/devices/system/cpu/cpu0/cpufreq/cpuinfo_max_freq");
    std::string freq;
    
    if (freqFile.is_open()) {
        std::getline(freqFile, freq);
        freqFile.close();
    } else {
        freq = "Unknown";
    }
    
    return freq;
}

extern "C" CpuDataModel getCpuData() {
    auto cpuInfo = parseProcCpuInfo();

    std::string processorModel = cpuInfo["Hardware"];
    std::string architecture = cpuInfo["CPU architecture"];
    std::string coreCount = cpuInfo["processor"];
    std::string cpuPart = cpuInfo["CPU part"];
    std::string cpuImplementer = cpuInfo["CPU implementer"];
    std::string cpuVariant = cpuInfo["CPU variant"];
    std::string cpuRevision = cpuInfo["CPU revision"];
    std::string cpuFeatures = cpuInfo["Features"];

    if (coreCount.empty()) {
        coreCount = "Unknown";
    } else {
        coreCount = std::to_string(std::stoi(coreCount) + 1);
    }

    CpuDataModel cpuData = {
        processorModel,
        processorModel,
        "Qualcomm",
        architecture,
        "N/A",
        coreCount,
        "N/A",
        getCpuMaxFrequency() + " MHz",
        getCpuGovernor(),
        (cpuInfo["CPU architecture"] == "8") ? "64" : "32",
        cpuFeatures,
        cpuImplementer,
        cpuPart,
        cpuRevision,
        cpuVariant
    };

    LOGE("Processor Model: %s", cpuData.model.c_str());
    return cpuData;
}