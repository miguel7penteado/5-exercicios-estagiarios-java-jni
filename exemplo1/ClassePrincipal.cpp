#include <cstdio>
#include <iostream>
#include <jni.h>
#include "ClassePrincipal.h"

using namespace std;

JNIEXPORT void JNICALL Java_ClassePrincipal_cumprimentos(JNIEnv *ambiente_java, jobject parametro_objeto1)
{
	printf( "\n C   ===> Olá, este é um cumprimento da linguagem C");
	cout << "\n C++ ===> Olá, este é um cumprimento da linguagem C++" << endl;
	printf("\n");
}
