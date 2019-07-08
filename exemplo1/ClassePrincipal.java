public class ClassePrincipal
{  
	private native void cumprimentos();

	public ClassePrincipal()
	{
		System.loadLibrary("biblioteca1");                                   
	};
  
   public static void main(String[] args)
   {
	  ClassePrincipal objeto1;
	  objeto1 = new ClassePrincipal();
	  System.out.println("Evocando código c++ daqui em diante...");
      objeto1.cumprimentos();
   };
}
