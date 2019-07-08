import java.util.Scanner;

public class Matematica
{
	private int parcela1;
	private int parcela2;
	private int resultado;
	private native int somar(int parcela1, int parcela2);
		
    public Matematica()
	{
		System.loadLibrary("biblioteca_soma");
	}

	public static void main(String args[])
	{
		Scanner entrada ;
		Matematica operacao;
		operacao = new Matematica();
		entrada  = new Scanner( System.in );
		System.out.println("Vamos executar uma soma com ajuda de C++");
		System.out.println("Por favor digite a parcela1");
		operacao.parcela1 = entrada.nextInt();
		System.out.println("Por favor digite a parcela2");
		operacao.parcela2 = entrada.nextInt();
		System.out.println("Somando os números via C++ ");
		operacao.resultado = operacao.somar(operacao.parcela1,operacao.parcela2);
		System.out.printf( "A soma é = %d\n", operacao.resultado );		
	};
	
	public int getparcela1()
	{
		return(parcela1);
	};
	public void setparcela1(int parametro_parcela1)
	{
		parcela1 = parametro_parcela1;
	};

	public int getparcela2()
	{
		return(parcela2);
	};
	public void setparcela2(int parametro_parcela2)
	{
		parcela2 = parametro_parcela2;
	};
	
	public int getresultado()
	{
		return(resultado);
	};
	public void setresultado(int parametro_resultado)
	{
		resultado = parametro_resultado;
	};
}

