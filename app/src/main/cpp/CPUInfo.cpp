#include <jni.h>
#include <string>
#include <fstream>
#include <unistd.h>
#include <iostream>
#include <map>

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

extern "C" JNIEXPORT jstring JNICALL
Java_apw_android_phonemanager_CPU_Companion_getCPUName(JNIEnv *env, jobject thiz) {
    return env->NewStringUTF(getCpuInfoField("/sys/devices/system/cpu/cpu0/cpufreq/cpuinfo_max_freq").c_str());
}

extern "C" JNIEXPORT jint JNICALL
Java_apw_android_phonemanager_CPU_Companion_getCPUCores(JNIEnv *env, jobject thiz) {
    return sysconf(_SC_NPROCESSORS_ONLN);
}

extern "C" JNIEXPORT jstring JNICALL
Java_apw_android_phonemanager_CPU_Companion_getCPUArch(JNIEnv *env, jobject thiz) {
    return env->NewStringUTF(getCpuInfoField("/sys/devices/system/cpu/cpu0/cpufreq/scaling_cur_freq").c_str());
}