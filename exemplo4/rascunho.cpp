#include <jni.h>

#include <string>
#include <cassert>
#include <iostream>

#include <stdexcept>

class MinhaConexaoJAVA
{
    private:
        std::string MWE_str;

        // contexto JAVA
        JNIEnv*     ambienteJNI;
        JavaVM*     maquinaVirtualJava;

        std::string caminhoClassesJAVA;
        std::string nomeClasseJAVA;

        // Classe Java
        jclass      classeJAVA;

        // Java object (class instance)
        jobject     objetoClasseJava;

        // metodos JAVA
        jmethodID   apontamentoConstrutor;   // ()V
        jmethodID   apontamentoSetEstringue  // (Ljava/lang/String;)V
        jmethodID   apontamentoGetEstringue; // ()Ljava/lang/String;

    public:
        MinhaConexaoJAVA();

        void inicializa_contexto(void);               //Init methods
        void inicializa_classe(void);
        void inicializa_metodos(void);

        void          construtor_java(void);
        void        entra_string_java(std::string);
        std::string   sai_string_java(void);

};

MinhaConexaoJAVA::MinhaConexaoJAVA()
{
    this->caminhoClassesJAVA      = "/home/user/Documents/MWE"; //CHANGE HERE
    this->nomeClasseJAVA          = "EXICodec";

    this->classeJAVA              = NULL;
    this->objetoClasseJava        = NULL;

    this->apontamentoConstrutor   = NULL;
    this->apontamentoSetEstringue = NULL;
    this->apontamentoGetEstringue = NULL;
}

void MinhaConexaoJAVA::inicializa_contexto()
{
    const std::string parametros_opcionais("-Djava.class.path="+this->caminhoClassesJAVA);

    JavaVMOption argumentos_opcionais[3] = {
        { const_cast<char*>("-Xmx128m"), NULL },
        { const_cast<char*>("-verbose:gc"), NULL },
        { const_cast<char*>(parametros_opcionais.c_str()), NULL }
    };

    JavaVMInitArgs argumentos_maquina_virtual;
    argumentos_maquina_virtual.version = JNI_VERSION_1_6;
    argumentos_maquina_virtual.argumentos_opcionais = argumentos_opcionais;
    argumentos_maquina_virtual.nOptions = sizeof(argumentos_opcionais) / sizeof(JavaVMOption);
    assert(argumentos_maquina_virtual.nOptions == 3);

    this->ambienteJNI = NULL;
    this->maquinaVirtualJava = NULL;

    int res = JNI_CreateJavaVM(
		&this->maquinaVirtualJava, 
		reinterpret_cast<void**>(&this->ambienteJNI),
		&argumentos_maquina_virtual
    );

    if (JNI_OK != res)
    {
        throw std::runtime_error("JAVA_VM_EXCEPTION");
    }
}

void MinhaConexaoJAVA::inicializa_classe()
{
	this->classeJAVA = this->ambienteJNI
		->FindClass(std::string(this->nomeClasseJAVA).c_str());

    if (NULL == this->classeJAVA)
    {
        throw std::runtime_error("JAVA_CLASS_EXCEPTION");
    }
}

void MinhaConexaoJAVA::inicializa_metodos()
{
    this->apontamentoConstrutor = 
    this->ambienteJNI->
		GetMethodID(this->classeJAVA,"<init>","()V");

    this->IDsetString = 
    this->ambienteJNI->
    GetMethodID(this->classeJAVA,"setInputXML","(Ljava/lang/String;)V");

    this->apontamentoGetEstringue = this->ambienteJNI->
    GetMethodID(this->classeJAVA,"getInputXML","()Ljava/lang/String;");
}

void MinhaConexaoJAVA::construtor_java()
{
    this->objetoClasseJava = this->ambienteJNI->
    NewObject(this->classeJAVA,this->apontamentoConstrutor);

    if (NULL == this->objetoClasseJava)
    {
        throw std::runtime_error("JAVA_CONSTRUCTOR_EXCEPTION");
    }
}

void MinhaConexaoJAVA::entra_string_java( std::string str)
{
    jstring argumento = this->ambienteJNI->NewStringUTF(str.c_str());

    this->ambienteJNI->
    CallVoidMethod(this->objetoClasseJava,this->IDsetString,argumento);
}

std::string MinhaConexaoJAVA::sai_string_java()
{

    jstring string_retornada_java= (jstring) this->ambienteJNI->
    CallObjectMethod(
						this->objetoClasseJava,
						this->apontamentoGetEstringue,
						0
					);

    if (NULL == string_retornada_java)
    {
        throw std::runtime_error("JAVA_RETURN_EXCEPTION");
    }

    // jString to char*
    const char *string_c = 
    this->ambienteJNI->GetStringUTFChars(string_retornada_java, JNI_FALSE);

    std::string string_cpp(string_c);

    this->ambienteJNI->ReleaseStringUTFChars(string_retornada_java, string_c);

    return string_cpp;
}

int main()
{
	MinhaConexaoJAVA *conexao_java;
    conexao_java = new MinhaConexaoJAVA();

    conexao_java->inicializa_contexto();
    conexao_java->inicializa_classe();
    conexao_java->inicializa_metodos();
    conexao_java->construtor_java();

    std::string test_str = conexao_java->sai_string_java();
    std::cout << test_str << std::endl;
    std::cout << "Rodando perfeitamente" << std::endl;

    conexao_java->entra_string_java("teste");
    test_str = conexao_java->sai_string_java();
    std::cout << test_str << std::endl;
    
}
