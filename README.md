
# JNI - Interface Java Nativa C++

```
Equivalencia de tipos primitivos:
========================+
|    CPP    |    JAVA   |
========================+
|   jint    |   int     |
+-----------+-----------+
|  jbyte    |   byte    |
+-----------+-----------+
|  jshort   |   short   |
+-----------+-----------+
|  jlong    |   long    |
+-----------+-----------+
|  jfloat   |   float   |
+-----------+-----------+
|  jdouble  |   double  |
+-----------+-----------+
|  jchar    |   char    |
+-----------+-----------+
|  jboolean |   boolean |
+-----------+-----------+


Equivalência para Classes:
========================================+
|    CPP     |           JAVA           |
========================================+
|  jobject   |   java.lang.Object       |
+------------+--------------------------+
|  jclass    |   java.lang.Class        |
+------------+--------------------------+
|  jstring   |   java.lang.String       |
+------------+--------------------------+
| jthrowable |   java.lang.Throwable    |
+------------+--------------------------+


+================================================================================================================================+
|             FUNÇÕES DE    TRATAMENTO DE Objetos                                                                                |
+================================================================================================================================+
| jclass          FindClass(JNIEnv *env, const char *name); 
+--------------------------------------------------------------------------------------------------------------------------------+
| jobject         NewObject(JNIEnv *env, jclass cls, jmethodID methodID, ...); 
+--------------------------------------------------------------------------------------------------------------------------------+
| jobject         NewObjectA(JNIEnv *env, jclass cls, jmethodID methodID, const jvalue *args); 
+--------------------------------------------------------------------------------------------------------------------------------+
| jobject         NewObjectV(JNIEnv *env, jclass cls, jmethodID methodID, va_list args); 
+--------------------------------------------------------------------------------------------------------------------------------+
| jobject         AllocObject(JNIEnv *env, jclass cls); 
+--------------------------------------------------------------------------------------------------------------------------------+
 

+================================================================================================================================+
|             FUNÇÕES DE    TRATAMENTO DE STRINGS UTF-8 / ASCII                                                                  |
+================================================================================================================================+
| const char *     GetStringUTFChars(JNIEnv *env, jstring string, jboolean *isCopy);                                             |
+--------------------------------------------------------------------------------------------------------------------------------+
| void             ReleaseStringUTFChars(JNIEnv *env, jstring string, const char *utf);                                          |
+--------------------------------------------------------------------------------------------------------------------------------+
| jstring          NewStringUTF(JNIEnv *env, const char *bytes);                                                                 |
+--------------------------------------------------------------------------------------------------------------------------------+
| jsize            GetStringUTFLength(JNIEnv *env, jstring string);                                                              |
+--------------------------------------------------------------------------------------------------------------------------------+
| void             GetStringUTFRegion(JNIEnv *env, jstring str, jsize start, jsize length, char *buf);                           |
+--------------------------------------------------------------------------------------------------------------------------------+


+================================================================================================================================+
|             FUNÇÕES DE    TRATAMENTO DE STRINGS UTF-16                                                                         |
+================================================================================================================================+
| const jchar *   GetStringChars(JNIEnv *env, jstring string, jboolean *isCopy);                                                 |
+--------------------------------------------------------------------------------------------------------------------------------+
| void            ReleaseStringChars(JNIEnv *env, jstring string, const jchar *chars);                                           |
+--------------------------------------------------------------------------------------------------------------------------------+
| jstring         NewString(JNIEnv *env, const jchar *unicodeChars, jsize length);                                               |
+--------------------------------------------------------------------------------------------------------------------------------+
| jsize           GetStringLength(JNIEnv *env, jstring string);                                                                  |
+--------------------------------------------------------------------------------------------------------------------------------+
| void            GetStringRegion(JNIEnv *env, jstring str, jsize start, jsize length, jchar *buf);                              |
+--------------------------------------------------------------------------------------------------------------------------------+


+================================================================================================================================+
|                                    Funções de tratamento de Objetos (ponteiros instanciados)                                   |
+================================================================================================================================+
| jclass          GetObjectClass(JNIEnv *env, jobject obj);                                                                      |
+--------------------------------------------------------------------------------------------------------------------------------+
| jfieldID        GetFieldID(JNIEnv *env, jclass cls, const char *name, const char *sig);                                        |
+--------------------------------------------------------------------------------------------------------------------------------+
| NativeType      Get<type>Field(JNIEnv *env, jobject obj, jfieldID fieldID);                                                    |
+--------------------------------------------------------------------------------------------------------------------------------+
| void            Set<type>Field(JNIEnv *env, jobject obj, jfieldID fieldID, NativeType value);                                  |
+--------------------------------------------------------------------------------------------------------------------------------+
|                                     Chamando MÉTODOS dos objetos                                                               |
+--------------------------------------------------------------------------------------------------------------------------------+
| jmethodID       GetMethodID(JNIEnv *env, jclass cls, const char *name, const char *sig);
+--------------------------------------------------------------------------------------------------------------------------------+
| NativeType      Call<type>Method(JNIEnv *env, jobject obj, jmethodID methodID, ...);
+--------------------------------------------------------------------------------------------------------------------------------+
| NativeType      Call<type>MethodA(JNIEnv *env, jobject obj, jmethodID methodID, const jvalue *args);
+--------------------------------------------------------------------------------------------------------------------------------+
| NativeType      Call<type>MethodV(JNIEnv *env, jobject obj, jmethodID methodID, va_list args);
+--------------------------------------------------------------------------------------------------------------------------------+


+================================================================================================================================+
|                                    Funções de tratamento variáveis estáticas                                                   |
+================================================================================================================================+
| ------------------------------------------------------------------------------------------------------------------------------ |
+--------------------------------------------------------------------------------------------------------------------------------+
| jfieldID        GetStaticFieldID(JNIEnv *env, jclass cls, const char *name, const char *sig);                                  |
+--------------------------------------------------------------------------------------------------------------------------------+
| NativeType      GetStatic<type>Field(JNIEnv *env, jclass clazz, jfieldID fieldID);                                             |
+--------------------------------------------------------------------------------------------------------------------------------+
| void            SetStatic<type>Field(JNIEnv *env, jclass clazz, jfieldID fieldID, NativeType value);                           |
+--------------------------------------------------------------------------------------------------------------------------------+
|                                     Chamando MÉTODOS estáticos de classes                                                      |
+--------------------------------------------------------------------------------------------------------------------------------+
| jmethodID       GetStaticMethodID(JNIEnv *env, jclass cls, const char *name, const char *sig);                                 |
+--------------------------------------------------------------------------------------------------------------------------------+
| NativeType      CallStatic<type>Method(JNIEnv *env, jclass clazz, jmethodID methodID, ...);                                    |
+--------------------------------------------------------------------------------------------------------------------------------+
| NativeType      CallStatic<type>MethodA(JNIEnv *env, jclass clazz, jmethodID methodID, const jvalue *args);                    |
+--------------------------------------------------------------------------------------------------------------------------------+
| NativeType      CallStatic<type>MethodV(JNIEnv *env, jclass clazz, jmethodID methodID, va_list args);                          |
+--------------------------------------------------------------------------------------------------------------------------------+

+================================================================================================================================+
|                                    Métodos de super-classes antes de serem sobreescritos                                       |
+================================================================================================================================+
| NativeType      CallNonvirtual<type>Method(JNIEnv *env, jobject obj, jclass cls, jmethodID methodID, ...);                     |
+--------------------------------------------------------------------------------------------------------------------------------+
| NativeType      CallNonvirtual<type>MethodA(JNIEnv *env, jobject obj, jclass cls, jmethodID methodID, const jvalue *args);     |
+--------------------------------------------------------------------------------------------------------------------------------+
| NativeType      CallNonvirtual<type>MethodV(JNIEnv *env, jobject obj, jclass cls, jmethodID methodID, va_list args);           |
+--------------------------------------------------------------------------------------------------------------------------------+


//-----------------------------------------------------------------------   

jarray para vetores java Java. Vetores Java é um tipo de referência
com 8 vetores primitivos e
um vetor Object. 
Hence, there are eight array of primitives 

Mapeamento de Tipos vetores
==========================================+
|    CPP       |           JAVA           |
==========================================+
| jintArray    |         int[]            |
+--------------+--------------------------+
| jbyteArray   |         byte[]           |
+--------------+--------------------------+
| jshortArray  |        short[]           |
+--------------+--------------------------+
| jlongArray   |        long[]            |
+--------------+--------------------------+
| jfloatArray  |        float[]           |
+--------------+--------------------------+
| jdoubleArray |       double[]           |
+--------------+--------------------------+
| jcharArray   |       char[]             |
+--------------+--------------------------+
| jbooleanArray|      boolean[]           |
+--------------+--------------------------+
| jobjectArray |       Object[]           |
+--------------+--------------------------+

+================================================================================================================================+
|                                    Funções de tratamento de vetores                                                            |
+================================================================================================================================+
| NativeType * Get<PrimitiveType>ArrayElements(JNIEnv *env, ArrayType array, jboolean *isCopy);                                  |
+--------------------------------------------------------------------------------------------------------------------------------+
| void         Release<PrimitiveType>ArrayElements(JNIEnv *env, ArrayType array, NativeType *elems, jint mode);                  |
+--------------------------------------------------------------------------------------------------------------------------------+
| void         Get<PrimitiveType>ArrayRegion(JNIEnv *env, ArrayType array, jsize start, jsize length, NativeType *buffer);       |
+--------------------------------------------------------------------------------------------------------------------------------+
| void         Set<PrimitiveType>ArrayRegion(JNIEnv *env, ArrayType array, jsize start, jsize length, const NativeType *buffer); |
+--------------------------------------------------------------------------------------------------------------------------------+
| ArrayType    New<PrimitiveType>Array(JNIEnv *env, jsize length);                                                               |
+--------------------------------------------------------------------------------------------------------------------------------+
| void       * GetPrimitiveArrayCritical(JNIEnv *env, jarray array, jboolean *isCopy);                                           |
+--------------------------------------------------------------------------------------------------------------------------------+
| void         ReleasePrimitiveArrayCritical(JNIEnv *env, jarray array, void *carray, jint mode);                                |
+--------------------------------------------------------------------------------------------------------------------------------+
```
