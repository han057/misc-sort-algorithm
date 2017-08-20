package co.edu.utp.misc.algoritmos;

public class Insercion implements AlgoritmoOrdenamiento {

	@Override
	public int[] ordenar(int[] arreglo) {
		int p, j;
		int aux;
		for (p = 1; p < arreglo.length; p++) {
			aux = arreglo[p];
			j = p - 1;
			while ((j >= 0) && (aux < arreglo[j])) {
				arreglo[j + 1] = arreglo[j];
				j--;
			}
			arreglo[j + 1] = aux;
		}
		return arreglo;
	}

}