import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.text.SimpleDateFormat;
import java.util.Date;


public class algoritmoinsercion2 {
	
	private final static int n = 4000000; // valor igual al file
	
	
	private static SimpleDateFormat sdf = new SimpleDateFormat("hh:mm:ss:sssss");
	
	public static void main(String args[]) throws IOException {
		
		int[] arreglo = new int[n];
		int index = 0;
		//int[] arreglo1 = new int[n];
		
		System.out.println("Generando los datos [" + sdf.format(new Date()) + "]");
		/*	for (int i = 0; i< n; i++) {
				arreglo[i] = new Random().nextInt();
			}*/
			
		String fila, linea;
		
		FileReader f = new FileReader("datos4.txt");
	    BufferedReader buffer = new BufferedReader(f);
	    
		while((linea=buffer.readLine()) != null){
				fila = new String(linea.getBytes("ISO-8859-1"), "UTF-8");
				String[] datos = fila.split(" ", -1);
				for (int i = 0; i< datos.length ; i++) {
					arreglo[index] = Integer.parseInt(datos[i]);
					//System.out.println("Datos [" + arreglo[index] + "]" + "idx= " + index);
					index++;
				}
		}
		buffer.close();
		
/*		for (int i = 0; i< arreglo.length ; i++) {
			//System.out.println("Datos [" + arreglo[i] + "]");
		}*/
		
		System.out.println("Datos generados [" + sdf.format(new Date()) + "]");
		//return arreglo;
		
		Date inicio = new Date();
		System.out.println("ordenando los datos...");
		
		int p, j;
	    int aux;
	    for (p = 1; p < arreglo.length; p++){
	              aux = arreglo[p]; 
	              j = p - 1; 
	              while ((j >= 0) && (aux < arreglo[j])){ 
	                                                
	            	  arreglo[j + 1] = arreglo[j];   
	                             j--;               
	              }
	              arreglo[j + 1] = aux;
	    }
		
				//generar();

/*				for (int i = 0; i< arreglo.length ; i++) {
					System.out.println("Datos [" + arreglo[i] + "]");
				}
				*/
				
				//arreglo1 = insercionDirecta(arreglo);
				Date fin = new Date();
				System.out.println("Datos ordenados, tomo(" + sdf.format(new Date (fin.getTime() - inicio.getTime())) + "]");
				
				/*for (int i = 0; i< arreglo1.length ; i++) {
					System.out.println("Datos [" + arreglo1[i] + "]");
				}*/
				
	}
	

	 /*public static int[] insercionDirecta(int A[]){
		    int p, j;
		    int aux;
		    for (p = 1; p < A.length; p++){ 
		              aux = A[p]; 
		              j = p - 1; 
		              while ((j >= 0) && (aux < A[j])){ 
		                                                
		                             A[j + 1] = A[j];   
		                             j--;               
		              }
		              A[j + 1] = aux;
		    }
	return A;	
	 }*/


}