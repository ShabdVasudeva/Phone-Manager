#include <jni.h>
#include "DeviceName.h"
#include <string>
#include <iostream>
#include <map>
#include "GetProp.h"

extern "C" JNIEXPORT jstring JNICALL
Java_apw_android_phonemanager_DeviceInfo_getDeviceName(JNIEnv *env, jobject thiz){
  return env->NewStringUTF(getDeviceName().c_str());
}

extern "C" JNIEXPORT jstring JNICALL
Java_apw_android_phonemanager_DeviceInfo_getBuildVersion(JNIEnv *env, jobject thiz){
  std::string version = getProp("getprop ro.build.version.release");
  return env->NewStringUTF(version.c_str());
}

extern "C" JNIEXPORT jstring JNICALL
Java_apw_android_phonemanager_DeviceInfo_getBasebandVersion(JNIEnv *env, jobject thiz){
  std::string version = getProp("getprop gsm.version.baseband");
  return env->NewStringUTF(version.c_str());
}

extern "C" JNIEXPORT jstring JNICALL
Java_apw_android_phonemanager_DeviceInfo_getKernelVersion(JNIEnv *env, jobject thiz){
  std::string kernel = getProp("uname -r");
  return env->NewStringUTF(kernel.c_str());
}