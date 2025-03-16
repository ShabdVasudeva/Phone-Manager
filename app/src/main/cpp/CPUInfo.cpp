#include <jni.h>
#include <string>
#include <fstream>
#include <unistd.h>
#include <iostream>
#include <map>
#include <cstdio>
#include <memory>
#include <sys/utsname.h>

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

extern "C" JNIEXPORT jstring JNICALL
Java_apw_android_phonemanager_CPU_getCPUMan(JNIEnv *env, jobject thiz){
    std::string cpuMan = execCommand("getprop ro.soc.manufacturer");
    return env->NewStringUTF(cpuMan.c_str());
}

extern "C" JNIEXPORT jint JNICALL
Java_apw_android_phonemanager_CPU_getCPUCores(JNIEnv *env, jobject thiz) {
    return sysconf(_SC_NPROCESSORS_ONLN);
}

extern "C" JNIEXPORT jstring JNICALL
Java_apw_android_phonemanager_CPU_getCPUArch(JNIEnv *env, jobject thiz) {
    std::string arm64 = "64 Bit";
    std::string arm32 = "32 Bit";
    std::string cpuType = execCommand("getprop ro.product.cpu.abilist64");
    if (cpuType.empty()){
        return env->NewStringUTF(arm32.c_str());
    }
    return env->NewStringUTF(arm64.c_str());
}

extern "C" JNIEXPORT jstring JNICALL
Java_apw_android_phonemanager_CPU_getGPURenderer(JNIEnv *env, jobject thiz){
    const char *renderer = reinterpret_cast<const char*>(glGetString(GL_RENDERER));
    return env->NewStringUTF(renderer ? renderer : "Unknown");
}