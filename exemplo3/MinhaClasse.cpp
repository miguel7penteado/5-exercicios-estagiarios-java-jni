#include <cstdio>
#include <iostream>
#include <jni.h>
#include "MinhaClasse.h"

using namespace std;

/*======================================================================
 * Neste exemplo o código C++ chama métodos do OBJETO JAVA 
 *======================================================================
 * Inicialmente, o JAVA evoca o código C++ para que este faça seus 
 * procedimentos.
 * Contudo, o código c++ também faz uso dos recursos JAVA evocando 
 * métodos do próprio objeto JAVA que o chamou.
 * Isso acaba ocasionando uma espécie de sinergia. 
 * 
 * 
 * Miguel Suez Xve Penteado  miguel7penteado em gmail.com
*/


JNIEXPORT void JNICALL Java_MinhaClasse_funcao1_1cpp(JNIEnv *ambiente_java, jobject este_objeto)
{
	jclass apontamento_classe;

	jmethodID apontamento1_funcao1_java ;

	jmethodID apontamento2_funcao1_java;
	jstring parametro_para_o_java;

	jmethodID apontamento_construtor;
	jmethodID apontamento1_funcao2_java;
	jobject apontamento_objeto;
	jstring outro_parametro_para_o_java;
	jstring retorno;
	
	
	
	std::cout << "C++: Chamando a função1_java da MinhaClasse sem parâmetro:" << endl;
	
	// obtem ponteiro para a classe do objeto1 lá na máquina java.
	apontamento_classe = ambiente_java->FindClass("MinhaClasse");
	apontamento_construtor    = ambiente_java->GetMethodID(apontamento_classe, "<init>", "()V");
	apontamento_objeto        = ambiente_java->NewObject(apontamento_classe, apontamento_construtor);

	std::cout << "C++: Evocando função1 JAVA sem parâmetros e sem retorno:" << endl;
	apontamento1_funcao1_java = ambiente_java->GetMethodID(apontamento_classe, "funcao1_java", "()V" );
	if (NULL == apontamento1_funcao1_java)
	{
		return;
	}
	else
	{
		std::cout << "C++: Evocando funcao1_java()" << std::endl;		
		ambiente_java->CallObjectMethod(apontamento_objeto, apontamento1_funcao1_java);
	};
	
	
	std::cout << "C++: Evocando função1 JAVA com parâmetro String e sem retorno:" << endl;
	apontamento2_funcao1_java = ambiente_java->GetMethodID(apontamento_classe, "funcao1_java", "(Ljava/lang/String;)V");
	if (NULL == apontamento2_funcao1_java)
	{
		return;
	}
	else
	{
		std::cout << "C++: Evocando funcao1_java(String)" << std::endl ;
		parametro_para_o_java = ambiente_java->NewStringUTF("'C++: STRING originada do C++'");
		ambiente_java->CallVoidMethod(apontamento_objeto, apontamento2_funcao1_java, parametro_para_o_java);
	};

	/*
	std::cout << "C++: Evocando função1 JAVA com parâmetro String e com retorno String" << endl;
	apontamento1_funcao2_java = ambiente_java->GetMethodID(apontamento_classe, "funcao2_java", "(Ljava/lang/String;)Ljava/lang/String;");
	if (NULL == apontamento1_funcao2_java)
	{
		return;
	}
	else
	{
		std::cout << "C++: Evocando String funcao1_java(String)" << std::endl;		
		retorno = ambiente_java->CallObjectMethod(apontamento_objeto, apontamento1_funcao2_java);		
	};
	*/
	
	//ambiente_java->ReleaseStringUTFChars(parametro_para_o_java,outro_parametro_para_o_java);
	
}

























