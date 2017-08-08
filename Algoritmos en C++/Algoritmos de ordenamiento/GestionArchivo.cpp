/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   GestionArchivo.cpp
 * Author: Vonny
 * 
 * Created on 6 de agosto de 2017, 07:19 PM
 */

#include "GestionArchivo.h"
//#include "Ordenamiento.h"
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <cstdlib>
#include <string>

using namespace std;

GestionArchivo::GestionArchivo() {
}

GestionArchivo::GestionArchivo(const GestionArchivo& orig) {
}

GestionArchivo::~GestionArchivo() {
}

int* GestionArchivo::LeerDatos(int *vector, int n) {

    fstream archivo("datos1.txt");
    string num;
    int i;
    vector = new int[n];
    
    //Para limpiar el vector
    for(i = 0; i < n; i++){
        vector[i] = 0;
        //cout << i << " : " << vector[i] << "\n";
    }
        
    if(!archivo.is_open())
        archivo.open("datos1.txt",ios::in);
        
        for(i = 0; i < n; i++){
            if(!archivo.eof()){
                getline(archivo,num);
                vector[i] = std::stoi(num);
            }    
            //Para ver cómo queda el vector recien cargado
            //cout << i << " : " << vector[i] << "\n"; 
        }
    
    
    archivo.close();
    cout << "archivo cerrado \n";
    
    //system("pause");
    
    return vector;
}

/* Función para escribir archivo de estadísticas
void GestionArchivo::EscribirEstadisticas(string ordenamiento, int n, double tiempo) {

    fstream archivo2("estadisticas.txt");
 
    archivo2.open("estadisticas.txt",ios::out | ios::app);
    
    if (archivo2.is_open()){
        archivo2 << ordenamiento << ' ' << n << ' ' << tiempo << '\n';
        cout << "guardado";
    }
    else cout << "no abrió";
 
    archivo2.close();
}*/