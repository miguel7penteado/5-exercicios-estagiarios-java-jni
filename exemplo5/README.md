# Evocando código nativo C++ no Android, utilizando o android NDK e java JNI:

Consultar [https://developer.android.com/training/articles/perf-jni.html?hl=pt-br#java](https://developer.android.com/training/articles/perf-jni.html?hl=pt-br#java)

```bash
cd native

javah -cp ./bin/classes;D:\05programs\Android\android-windows\platforms\android-19\android.jar \
-d ./jni com.huawei.g3.proxy.NativeApplication
```

```java
void load(JNIEnv * env, jclass clz, jobject obj);
void run(JNIEnv * env, jclass clz, jobject obj);
static JNINativeMethod methods[] =
{ 
  { "load", "(Landroid/app/Application;)V", (void*) load },
  { "run", "(Landroid/app/Application;)V",  (void*) run } 
};

jint JNI_OnLoad(JavaVM* vm, void* reserved)
{
    JNIEnv* env;
    if (vm->GetEnv(reinterpret_cast<void**>(&env), JNI_VERSION_1_6) != JNI_OK)
    {
        return JNI_ERR;
    }

    // Register methods with env->RegisterNatives.
    int len = sizeof(methods) / sizeof(methods[0]);
    jclass native = env->FindClass("com/huawei/g3/proxy/NativeApplication");
    if (env->RegisterNatives(native, methods, len) < 0) {
        return JNI_ERR;
    }
    return JNI_VERSION_1_6;
}
```

```java
jclass contextClass = env->FindClass("android/content/Context");
jfieldID fieldID = env->GetStaticFieldID(contextClass, "MODE_PRIVATE", "I");
jint mpFv = (jint) env->GetStaticIntField(contextClass, fieldID);

jstring _payload_dex = env->NewStringUTF("payload_dex");

jclass appClass = env->FindClass("android/app/Application");
jmethodID methodID = env->GetMethodID(appClass, "getDir", "(Ljava/lang/String;I)Ljava/io/File;");
jobject dex = env->CallObjectMethod(obj, dirMd, _payload_dex, mpFv); 

```
fonte: [https://mccxj.github.io/blog/20151028_android-ndk-jni.html](https://mccxj.github.io/blog/20151028_android-ndk-jni.html)

