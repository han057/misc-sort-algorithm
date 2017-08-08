/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Vonny
 *
 * Created on 6 de agosto de 2017, 05:41 PM
 */

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include "GestionArchivo.h"
#include "Ordenamiento.h"


using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    
    GestionArchivo A;
    Ordenamiento O;
    
    int *vector;
    int n;
 
    cout << "Ingrese el número de datos a ordenar: ";
    cin >> n;
    cout << '\n';
       
    vector = A.LeerDatos(vector, n);
    
    O.Seleccion(vector, n);
    
    O.Insercion(vector, n);
    
    O.OrdenarMezcla(vector, 0, n);
    
    O.OrdenarHeapsort(vector, n);
    
    O.OrdenarQuicksort(vector, 0, n);
    
    O.OrdenarCounting(vector, n, 5000);
            
    delete[] vector;
    return 0;
}

