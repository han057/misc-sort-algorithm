/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Ordenamiento.cpp
 * Author: Vonny
 * 
 * Created on 6 de agosto de 2017, 11:03 PM
 */

#include "Ordenamiento.h"
//#include "GestionArchivo.h"
#include <stdlib.h>
#include <cstdlib>
#include <iostream>
#include <windows.h> 

using namespace std;

Ordenamiento::Ordenamiento() {
}

Ordenamiento::Ordenamiento(const Ordenamiento& orig) {
}

Ordenamiento::~Ordenamiento() {
}

/*--------------------------- TOMA DE TIEMPOS -----------------------*/

double Ordenamiento::Performancecounter_diff(LARGE_INTEGER *a, LARGE_INTEGER *b) {
    
    LARGE_INTEGER freq;
    QueryPerformanceFrequency(&freq);
    return (double)(a->QuadPart - b->QuadPart) / (double)freq.QuadPart;
}

/*--------------------------- SELECTION SORT -----------------------*/

void Ordenamiento::Seleccion(int *v, int n) {

    int i, min, j, aux;
    LARGE_INTEGER t_ini, t_fin;
    double secs;
    //GestionArchivo A;
    
    QueryPerformanceCounter(&t_ini); //Inicio del conteo del tiempo de ejecución
    
    for (i = 0; i < n - 1; i++) {
        min = i;

        for (j = i + 1; j < n; j++) {
            if (v[j] < v[min]) 
                min = j;
        }

        aux = v[i];
        v[i] = v[min];
        v[min] = aux;
    }
    
    QueryPerformanceCounter(&t_fin); //Fin del conteo del tiempo de ejecución
    
    secs = Performancecounter_diff(&t_fin, &t_ini);
    cout << "SelectionSort.  " << n <<" datos.  Tiempo de ejecución: " << secs * 1000.0 << " milisegundos\n";
    
    //A.EscribirEstadisticas("Selección", n, secs * 1000.0);
    
    /*
    //Para verificar el vector ordenado    
    cout << "este es ordenado: \n";
    
    for(i = 0; i < n; i++){
        cout << i << " : " << v[i] << '\n';
    }
    */
}

/*--------------------------- INSERTION SORT -----------------------*/

void Ordenamiento::Insercion(int *v, int n) {

    int i, j, index;
    LARGE_INTEGER t_ini, t_fin;
    double secs;
    
    QueryPerformanceCounter(&t_ini);

    for (i=0; i < n; i++) {
        index = v[i];
        j = i-1;
        while (j >= 0 && v[j] > index) {
          v[j + 1] = v[j];
          j--;
        }
        v[j+1] = index;
    }
    
    QueryPerformanceCounter(&t_fin);
    
    secs = Performancecounter_diff(&t_fin, &t_ini);
    cout << "InsertionSort.  " << n <<" datos.  Tiempo de ejecución: " << secs * 1000.0 << " milisegundos\n";
    
    /*
    //Para verificar el vector ordenado
    cout << "este es ordenado: \n";
    
    for(i = 0; i < n; i++){
        cout << i << " : " << v[i] << '\n';
    }
    */
}

/*--------------------------- MERGE SORT -----------------------*/

void Ordenamiento::Mezclar(int *v, int izq, int der, int centro) {
    
    int i=izq;
    int j=centro+1;
    int* aux= new int[der-izq+1];
    int k=0;

    while ((i<=centro) &&(j<=der))
    {
        if(v[i]<v[j])
        {
            aux[k]=v[i];
            i++;
        }
        else
        {
            aux[k]=v[j];
            j++;
        }
        k++;
    }

    while (i<=centro)
    {
        aux[k]=v[i];
        i++;      
        k++;
    }

    while (j<=der)
    {
        aux[k]=v[j];
        j++;      
        k++;
    }

    for(i=0;i<k;i++)
    {
        v[i+izq]=aux[i];
    }
}

void Ordenamiento::Ordenar(int *v, int p, int q) {
    
    int centro=0;
    
    if (p<q)
    {
        centro=(p+q)/2;
        Ordenar(v,p,centro);
        Ordenar(v,centro+1,q);
        Mezclar(v,p,q,centro);
    }
}

void Ordenamiento::OrdenarMezcla(int *v, int p, int q) {
    
    int centro=0;
    LARGE_INTEGER t_ini, t_fin;
    double secs;

    QueryPerformanceCounter(&t_ini);

    Ordenar(v, p, q);

    QueryPerformanceCounter(&t_fin);

    secs = Performancecounter_diff(&t_fin, &t_ini);
    cout << "MergeSort.  " << q <<" datos.  Tiempo de ejecución: " << secs * 1000.0 << " milisegundos\n";  

    /*
    //Para verificar el vector ordenado
    cout << "este es ordenado: \n";

    for(int i = 0; i < q; i++){
        cout << i << " : " << v[i] << '\n';
    }
    */
}

/*--------------------------- HEAP SORT -----------------------*/

void Ordenamiento::Filtrado_desc(int *v, int i, int n) {
    
    /* queremos que se respete el orden MAX del montículo */
    int tmp = v[i];
    int hijo = 2 * i;
    
    if ((hijo < n) && (v[hijo + 1] > v[hijo]))
        hijo++;
   
    while ((hijo <= n) && (tmp < v[hijo]))
    {
        /* elijo bien el hijo */
        if ((hijo < n) && (v[hijo + 1] > v[hijo]))
          hijo++;
        v[i] = v[hijo];
        i = hijo;
        hijo = 2 * i;
    }
    
    v[i] = tmp;
}

void Ordenamiento::Intercambiar(int *v, int i, int j) {
    
    int temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

void Ordenamiento::OrdenarHeapsort(int *v, int n) {
    
    int i;
    LARGE_INTEGER t_ini, t_fin;
    double secs;
    
    QueryPerformanceCounter(&t_ini);
    
    /* coloco los datos en el montículo (ordeno) */
    for (i = n / 2; i >= 0; i--)
    {
        Filtrado_desc(v, i, n);
    }
    /* saco los datos y los meto al final para obtener el array ordenado */
    for (i = n - 1; i > 0; i--)
    {
        Intercambiar(v, 0, i);
        Filtrado_desc(v, 0, i - 1);
    }
    
    QueryPerformanceCounter(&t_fin);

    secs = Performancecounter_diff(&t_fin, &t_ini);
    cout << "HeapSort.  " << n <<" datos.  Tiempo de ejecución: " << secs * 1000.0 << " milisegundos\n";  

    /*
    //Para verificar el vector ordenado
    cout << "este es ordenado: \n";

    for(int j = 0; j < n; j++){
        cout << j << " : " << v[j] << '\n';
    }
    */
}

/*--------------------------- QUICK SORT -----------------------*/

int Ordenamiento::Dividir(int *v, int inicio, int fin) {
    
    int izq, der, pivote, temp;

    pivote = v[inicio];
    izq = inicio;
    der = fin;

    //Mientras no se cruzen los índices
    while (izq < der){
        
        while (v[der] > pivote){
            der--;
        }

        while ((izq < der) && (v[izq] <= pivote)){
            izq++;
        }

        // Si todavia no se cruzan los indices seguimos intercambiando
        if(izq < der){
            temp= v[izq];
            v[izq] = v[der];
            v[der] = temp;
        }
    }

  //Los indices ya se han cruzado, ponemos el pivote en el lugar que le corresponde
    temp = v[der];
    v[der] = v[inicio];
    v[inicio] = temp;

    //La nueva posición del pivote
    return der;
}

void Ordenamiento::Quicksort(int *v, int inicio, int fin) {
    
    int pivote;

    if(inicio < fin)
    {
        pivote = Dividir(v, inicio, fin );
        Quicksort( v, inicio, pivote - 1 );//ordeno la lista de los menores
        Quicksort( v, pivote + 1, fin );//ordeno la lista de los mayores
    }
}

void Ordenamiento::OrdenarQuicksort(int *v, int inicio, int fin) {

    LARGE_INTEGER t_ini, t_fin;
    double secs;

    QueryPerformanceCounter(&t_ini);

    Quicksort(v, inicio, fin);
    
    QueryPerformanceCounter(&t_fin);

    secs = Performancecounter_diff(&t_fin, &t_ini);
    cout << "QuickSort.  " << fin <<" datos.  Tiempo de ejecución: " << secs * 1000.0 << " milisegundos\n";  

    /*
    //Para verificar el vector ordenado
    cout << "este es ordenado: \n";
    
    for(int i = 0; i < fin; i++){
        cout << i << " : " << v[i] << '\n';
    }
    */
}

/*--------------------------- COUNTING SORT -----------------------*/

void Ordenamiento::OrdenarCounting(int *v, int n, int nmax) {
    
    int *aux; 
    int *r;
    int i, j;
    LARGE_INTEGER t_ini, t_fin;
    double secs;
    
    r = new int[n];
    aux = new int[nmax];
    
    //Para limpiar el vector de resultados
    for(i = 0; i < n; i++){
        r[i] = 0;
    }
    
    //Llena de ceros el vector auxiliar
    for(i = 0; i < nmax; i++) {
        aux[i]=0;
    }
        
    QueryPerformanceCounter(&t_ini);
        
    for(j = 1; j <= n; j++) {
        aux[v[j]] = aux[v[j]] + 1;
    }
    // aux[i] contiene ahora el número de elementos igual a 'i'
    
    for(i = 1; i < nmax; i++) {
        aux[i] = aux[i] + aux[i-1];
    }
    // aux[i] contiene ahora el número de elementos menor que o igual a 'i'    
    
    for(j = n; j > 0; j--) {
        r[aux[v[j]]] = v[j];
        aux[v[j]] = aux[v[j]] - 1;
    }    
    
    QueryPerformanceCounter(&t_fin);

    secs = Performancecounter_diff(&t_fin, &t_ini);
    cout << "CountingSort.  " << n <<" datos.  Tiempo de ejecución: " << secs * 1000.0 << " milisegundos\n";  

    /*
    //Para verificar el vector ordenado
    cout << "este es ordenado: \n";
    
    for(i = 1; i <= n; i++){
        cout << i << " : " << r[i] << '\n';
    }
    */
}