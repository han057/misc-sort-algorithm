package seleccion;

import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.Random;

public class Seleccion {
    
    private final static int n = 1000000;

	private static SimpleDateFormat sdf = new SimpleDateFormat("hh:mm:ss.sssss");

	public static void main(String args[]) {
		int[] arreglo = generar();
		Date inicio = new Date();
		System.out.println("Ordenando los datos [" + sdf.format(new Date(inicio.getTime()))+"]");
		arreglo = seleccion(arreglo);
		Date fin = new Date();
		System.out.println("Datos ordenados [" + sdf.format(new Date(fin.getTime())) + "]");
	}
        
        public static int[] seleccion(int[] in) {
		int p, j;
		int aux;
                for (p = 0; p < in.length - 1; p++ ){
		int min = p;
                    for (j = p + 1; j < in.length; j++){
                        if (in[j] < in[min]){
                            min = j;
                        }
                    }
                    if (p != min){
                        aux = in[p];
                        in[p]=in[min];
                        in[min]=aux;
                    }
                }
		return in;
	}
        
        public static int[] generar() {
		int[] arreglo = new int[n];
		System.out.println("Generando los datos [" + sdf.format(new Date()) + "]");
		for (int i = 0; i < n; i++) {
			arreglo[i] = new Random().nextInt();
		}
		System.out.println("Datos generados[" + sdf.format(new Date()) + "]");
		return arreglo;
	}
}