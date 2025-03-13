#include <jni.h>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <android/log.h>
#include <sys/sysinfo.h>
#include <dirent.h>

#define LOG_TAG "CPUInfo"
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__)

extern "C" {

    // Function to get CPU details from /proc/cpuinfo
    JNIEXPORT jstring JNICALL
    Java_apw_android_phonemanager_CPU_getCPUDetails(JNIEnv *env, jobject) {
        std::ifstream file("/proc/cpuinfo");
        std::stringstream buffer;

        if (!file.is_open()) {
            return env->NewStringUTF("Failed to open /proc/cpuinfo");
        }

        std::string line;
        while (getline(file, line)) {
            buffer << line << "\n";
        }
                                                
        file.close();
        return env->NewStringUTF(buffer.str().c_str());
    }

    // Function to get CPU name
    JNIEXPORT jstring JNICALL
    Java_apw_android_phonemanager_CPU_getCPUName(JNIEnv *env, jobject) {
        std::ifstream file("/proc/cpuinfo");
        std::string line, cpuName = "Unknown CPU";

        while (getline(file, line)) {
            if (line.find("Processor") != std::string::npos || line.find("model name") != std::string::npos) {
                cpuName = line.substr(line.find(":") + 2);
                break;
            }
        }
    
        file.close();
        return env->NewStringUTF(cpuName.c_str());
    }

    // Function to get the number of CPU cores
    JNIEXPORT jint JNICALL
    Java_apw_android_phonemanager_CPU_getNumCores(JNIEnv *env, jobject) {
        int cores = 0;
        DIR *dir = opendir("/sys/devices/system/cpu/");
                                                                                                                                    
        if (dir) {
            struct dirent *entry;
            while ((entry = readdir(dir)) != nullptr) {
                if (strncmp(entry->d_name, "cpu", 3) == 0 && isdigit(entry->d_name[3])) {
                    cores++;
                }
            }
            closedir(dir);
        }

        return cores > 0 ? cores : 1;
    }
}