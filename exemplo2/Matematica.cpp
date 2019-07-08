#include <cstdio>
#include <iostream>
#include <jni.h>
#include "Matematica.h"


JNIEXPORT jint JNICALL Java_Matematica_somar(JNIEnv *ambiente_java, jobject este_objeto, jint parcela1, jint parcela2)
{
	return(parcela1 + parcela2);	
};

