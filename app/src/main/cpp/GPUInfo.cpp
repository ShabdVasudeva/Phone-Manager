#include <jni.h>
#include <GLES2/gl2.h>
#include <string>

extern "C"
JNIEXPORT jstring JNICALL
Java_apw_android_phonemanager_GPU_getGPURenderer(JNIEnv* env, jobject /* this */) {
    const char* renderer = reinterpret_cast<const char*>(glGetString(GL_RENDERER));
    return env->NewStringUTF(renderer ? renderer : "Unknown");
}

extern "C"
JNIEXPORT jstring JNICALL
Java_apw_android_phonemanager_GPU_getGPUVendor(JNIEnv* env, jobject /* this */) {
    const char* vendor = reinterpret_cast<const char*>(glGetString(GL_VENDOR));
    return env->NewStringUTF(vendor ? vendor : "Unknown");
}

extern "C"
JNIEXPORT jstring JNICALL
Java_apw_android_phonemanager_GPU_getGPUVersion(JNIEnv* env, jobject /* this */) {
    const char* version = reinterpret_cast<const char*>(glGetString(GL_VERSION));
    return env->NewStringUTF(version ? version : "Unknown");
}

extern "C"
JNIEXPORT jstring JNICALL
Java_apw_android_phonemanager_GPU_getGPUExtensions(JNIEnv* env, jobject /* this */) {
    const char* extensions = reinterpret_cast<const char*>(glGetString(GL_EXTENSIONS));
    return env->NewStringUTF(extensions ? extensions : "Unknown");
}