#include <jni.h>
#include <string>
#include <fstream>
#include <unistd.h>
#include <iostream>
#include <map>
#include <sys/utsname.h>

std::string getCpuInfoField(const std::string& path) {
    std::ifstream file(path);
    std::string value;
    if (file.is_open()) {
        std::getline(file, value);
        file.close();
        return value;
    }
    return "Unknown";
}

std::string getCPUName(){
    std::ifstream file("/proc/cpuinfo");
    std::string line;
    while(std::getline(file, line)){
        if(line.find("Hardware") != std::string::npos || line.find("model name") != std::string::npos){
            return line.substr(line.find(":")+2);
        }
    }
    return "Null";
}

extern "C" JNIEXPORT jstring JNICALL
Java_apw_android_phonemanager_CPU_getCPUName(JNIEnv *env, jobject thiz) {
    std::string name = getCPUName();
    return env->NewStringUTF(name.c_str());
}

extern "C" JNIEXPORT jint JNICALL
Java_apw_android_phonemanager_CPU_getCPUCores(JNIEnv *env, jobject thiz) {
    return sysconf(_SC_NPROCESSORS_ONLN);
}

extern "C" JNIEXPORT jstring JNICALL
Java_apw_android_phonemanager_CPU_getCPUArch(JNIEnv *env, jobject thiz) {
    return env->NewStringUTF(getCpuInfoField("/sys/devices/system/cpu/cpu0/cpufreq/scaling_cur_freq").c_str());
}