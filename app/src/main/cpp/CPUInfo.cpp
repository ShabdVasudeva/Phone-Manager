#include <jni.h>
#include <string>
#include <fstream>
#include <unistd.h>
#include <iostream>
#include <map>
#include <cstdio>
#include <memory>
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

std::string execCommand(const char *str){
    std::string result;
    char buffer[128];
    FILE* pipe = popen(str, "r");
    if(!pipe) return "Unkown";
    while(fgets(buffer, sizeof(buffer), pipe) != nullptr){
        result += buffer;
    }
    pclose(pipe);
    if(!result.empty() && result[result.length()-1] == '\n'){
        result.erase(result.length()-1);
    }
    return result;
}

extern "C" JNIEXPORT jstring JNICALL
Java_apw_android_phonemanager_CPU_getCPUName(JNIEnv *env, jobject thiz) {
    std::string cpuName = execCommand("getprop ro.soc.model");
    if (cpuName.empty())
    {
        cpuName = execCommand("getprop ro.board.platform");
    }
    return env->NewStringUTF(cpuName.c_str());
}

extern "C" JNIEXPORT jint JNICALL
Java_apw_android_phonemanager_CPU_getCPUCores(JNIEnv *env, jobject thiz) {
    return sysconf(_SC_NPROCESSORS_ONLN);
}

extern "C" JNIEXPORT jstring JNICALL
Java_apw_android_phonemanager_CPU_getCPUArch(JNIEnv *env, jobject thiz) {
    return env->NewStringUTF(getCpuInfoField("/sys/devices/system/cpu/cpu0/cpufreq/scaling_cur_freq").c_str());
}