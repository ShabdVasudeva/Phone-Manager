#ifndef CPUINFO_H
#define CPUINFO_H

#include <jni.h>

extern "C" {
    JNIEXPORT jstring JNICALL Java_apw_android_phonemanager_CPU_getCPUDetails(JNIEnv *, jobject);
    JNIEXPORT jstring JNICALL Java_apw_android_phonemanager_CPU_getCPUName(JNIEnv *, jobject);
    JNIEXPORT jint JNICALL Java_apw_android_phonemanager_CPU_getNumCores(JNIEnv *, jobject);
}

#endif