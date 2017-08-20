package co.edu.utp.misc;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.text.SimpleDateFormat;
import java.util.HashMap;
import java.util.Map;

import co.edu.utp.misc.algoritmos.AlgoritmoOrdenamiento;
import co.edu.utp.misc.algoritmos.CountingSort;
import co.edu.utp.misc.algoritmos.HeapSort;
import co.edu.utp.misc.algoritmos.Insercion;
import co.edu.utp.misc.algoritmos.MergeSort;
import co.edu.utp.misc.algoritmos.QuickSort;
import co.edu.utp.misc.algoritmos.Seleccion;

public class Main {

	private static Map<String, AlgoritmoOrdenamiento> algoritmosMap;
	private final static int n = 50000000;
	private final static int step = 100;
	private static SimpleDateFormat sdf = new SimpleDateFormat("hh:mm:ss.sssss");
	private static int[] arreglo;

	public static void main(String args[]) {

		FileWriter fw = null;
		BufferedWriter bw = null;
		File file = new File("/home/han/Maestria/resultados.csv");
		algoritmosMap = new HashMap<String, AlgoritmoOrdenamiento>();
		algoritmosMap.put("Seleccion", new Seleccion());
		algoritmosMap.put("Insercion", new Insercion());
		algoritmosMap.put("Counting", new CountingSort());
		algoritmosMap.put("Heap", new HeapSort());
		algoritmosMap.put("Quick", new QuickSort());
		algoritmosMap.put("Merge", new MergeSort());
		arreglo = generar();
		double startTime, endTime;
		try {
			fw = new FileWriter(file);
			bw = new BufferedWriter(fw);

			for (String key : algoritmosMap.keySet()) {
				bw.write("\n" + key + ",");
				for (int i = step; i <= 500; i = i + step) {
					System.out.println("\n\n----------------------------------------------------------------------");
					System.out.println("Ordenando arreglo con [" + i + "] datos...");
					startTime = System.currentTimeMillis();
					int[] arrayAOrdenar = new int[i];
					System.arraycopy(arreglo, 0, arrayAOrdenar, 0, i);
					algoritmosMap.get(key).ordenar(arrayAOrdenar);
					endTime = System.currentTimeMillis();
					System.out.println("Algoritmo [" + key + "] Tomó " + (endTime - startTime) / 1000.0
							+ " segundos para [" + i + "] datos");
					bw.write(((endTime - startTime) / 1000.0) + ",");
				}
			}
		} catch (IOException e) {
			e.printStackTrace();
		} finally {
			try {
				if (bw != null)
					bw.close();
				if (fw != null)
					fw.close();

			} catch (IOException e) {
				e.printStackTrace();
			}
		}
	}

	public static int[] generar() {

		int[] arreglo = new int[n];
		FileReader fr = null;
		BufferedReader br = null;
		try {
			fr = new FileReader("/home/han/Maestria/datos.csv");
			br = new BufferedReader(fr);
			String sCurrentLine;

			int i = 0;
			while ((sCurrentLine = br.readLine()) != null) {
				arreglo[i] = Integer.parseInt(sCurrentLine);
				i++;
			}
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		} finally {
			try {
				if (fr != null)
					fr.close();
				if (br != null)
					br.close();
			} catch (IOException e) {
				e.printStackTrace();
			}
		}
		return arreglo;
	}
}