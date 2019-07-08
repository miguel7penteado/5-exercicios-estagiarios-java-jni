import java.util.Scanner;

public class MinhaClasse
{
	private String nome;
	private int    idade;
	private String endereco;
	
	private native void funcao1_cpp();

	private        void funcao1_java()
	{
		System.out.println("JAVA: Este é um método Java sem parâmetros");
	}

	private        void funcao1_java(String parametro1)
	{
		System.out.println("JAVA: Este é um método Java com parâmetro" + parametro1);
	}

	private        String funcao2_java(String parametro2)
	{
		String parametro3;
		parametro3 = parametro2 + "JAVA: PARAMETRO VINDO DO JAVA"; 
		System.out.println("JAVA: Este método JAVA está retornando o seguinte parâmetro:" + parametro2);
		return (parametro3);
	}
	
	public MinhaClasse()
	{
		System.loadLibrary("biblioteca_padrao");
	}

	static public void main(String[] args)
	{
		Scanner     variavel_entrada ;
		MinhaClasse objeto1;
		variavel_entrada = new Scanner(System.in);
		objeto1          = new MinhaClasse();
		System.out.println("JAVA: Chamando método C++");
		objeto1.funcao1_cpp();
		
	};
	
	public String getNome()
	{
		return nome;
	}

	public void setNome(String nome)
	{
		this.nome = nome;
	}

	public int getIdade()
	{
		return idade;
	}

	public void setIdade(int idade)
	{
		this.idade = idade;
	}

	public String getEndereco()
	{
		return endereco;
	}

	public void setEndereco(String endereco)
	{
		this.endereco = endereco;
	}


};
