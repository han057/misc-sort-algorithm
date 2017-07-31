import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.Random;

public class Insercion {

	private final static int n = 1000000;

	private static SimpleDateFormat sdf = new SimpleDateFormat("hh:mm:ss.sssss");

	public static void main(String args[]) {
		int[] arreglo = generar();
		Date inicio = new Date();
		System.out.println("Ordenando los datos...");
		arreglo = ordenar(arreglo);
		Date fin = new Date();
		System.out.println("Datos ordenados, tomó[" + sdf.format(new Date(fin.getTime() - inicio.getTime())) + "]");
	}

	public static int[] ordenar(int[] in) {
		int p, j;
		int aux;
		for (p = 1; p < in.length; p++) {
			aux = in[p];
			j = p - 1;
			while ((j >= 0) && (aux < in[j])) {
				in[j + 1] = in[j];
				j--;
			}
			in[j + 1] = aux;
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
