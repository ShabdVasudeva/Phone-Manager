#include <jni.h>
#include "DeviceName.h"
#include <string>
#include <iostream>
#include "CPUInfo.h"
#include <map>

extern "C" JNIEXPORT jstring JNICALL
Java_apw_android_phonemanager_DeviceInfo_getDeviceName(JNIEnv *env, jobject thiz){
  return env->NewStringUTF(getDeviceName().c_str());
}

extern "C" JNIEXPORT jobject JNICALL
Java_apw_android_phonemanager_CPU_getCPUInfo(JNIEnv *env, jobject thiz){
  CpuDataModel data = getCpuData();
  jclass cpuDataClass = env->FindClass("apw/android/phonemanager/CpuDataModel");
  jmethodID constructor = env->GetMethodID(cpuDataClass,"<init>","(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)V");
  if(constructor == nullptr){
    return nullptr;
  }
  auto strToJstring = [env](const std::string& str){
    return env->NewStringUTF(str.c_str());
  };
  jobject dataObject = env->NewObject(cpuDataClass, constructor, strToJstring(data.model), strToJstring(data.name), strToJstring(data.manufacturer), strToJstring(data.architecture), strToJstring(data.fab), strToJstring(data.coreCount), strToJstring(data.coreDetail), strToJstring(data.frequency), strToJstring(data.governor), strToJstring(data.cpuBit), strToJstring(data.cpuFeatures), strToJstring(data.cpuImplementer), strToJstring(data.cpuPart), strToJstring(data.cpuRevision), strToJstring(data.cpuVariant));
  return dataObject;
}