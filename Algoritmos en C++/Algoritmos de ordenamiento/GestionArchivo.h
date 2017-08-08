/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   GestionArchivo.h
 * Author: Vonny
 *
 * Created on 6 de agosto de 2017, 07:19 PM
 */

#include <stdlib.h>
#include <cstdlib>
#include <string>

#ifndef GESTIONARCHIVO_H
#define GESTIONARCHIVO_H

using namespace std;

class GestionArchivo {
public:
    
    GestionArchivo();
    GestionArchivo(const GestionArchivo& orig);
    virtual ~GestionArchivo();
    
    int* LeerDatos(int *vector, int n);
    //void EscribirEstadisticas(string ordenamiento, int n, double tiempo);
    
private:

};

#endif /* GESTIONARCHIVO_H */

