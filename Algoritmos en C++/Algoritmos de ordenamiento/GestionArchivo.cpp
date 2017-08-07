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
#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;

GestionArchivo::GestionArchivo() {
}

GestionArchivo::GestionArchivo(const GestionArchivo& orig) {
}

GestionArchivo::~GestionArchivo() {
}

void GestionArchivo::LeerDatos() {

    fstream archivo("datos1.txt");
    string num;
    
    if(!archivo.is_open())
        archivo.open("datos1.txt",ios::in);
    
    while(!archivo.eof())
    {
        getline(archivo,num);
        cout << num << "\n";
    }
    
    archivo.close();
    system("pause");
}
