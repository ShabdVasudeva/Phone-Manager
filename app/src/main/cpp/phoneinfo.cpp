#include <jni.h>
#include "DeviceName.h"
#include <string>
#include <iostream>
#include <map>

extern "C" JNIEXPORT jstring JNICALL
Java_apw_android_phonemanager_DeviceInfo_getDeviceName(JNIEnv *env, jobject thiz){
  return env->NewStringUTF(getDeviceName().c_str());
}