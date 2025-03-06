#include <jni.h>
#include <DeviceName.h>
extern "C" JNIEXPORT jstring JNICALL
Java_apw_android_phonemanager_DeviceInfo_getDeviceName(JNIEnv *env, jobject thiz){
  return env->NewStringUTF(getDeviceName());
}