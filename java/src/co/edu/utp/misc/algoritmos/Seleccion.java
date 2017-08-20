package co.edu.utp.misc.algoritmos;

public class Seleccion implements AlgoritmoOrdenamiento {

	@Override
	public int[] ordenar(int[] arreglo) {
		int p, j;
		int aux;
		for (p = 0; p < arreglo.length - 1; p++) {
			int min = p;
			for (j = p + 1; j < arreglo.length; j++) {
				if (arreglo[j] < arreglo[min]) {
					min = j;
				}
			}
			if (p != min) {
				aux = arreglo[p];
				arreglo[p] = arreglo[min];
				arreglo[min] = aux;
			}
		}
		return arreglo;
	}

}
