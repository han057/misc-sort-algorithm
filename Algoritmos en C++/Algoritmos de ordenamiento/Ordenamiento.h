/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Ordenamiento.h
 * Author: Vonny
 *
 * Created on 6 de agosto de 2017, 11:03 PM
 */
#include <windows.h> 

#ifndef ORDENAMIENTO_H
#define ORDENAMIENTO_H

class Ordenamiento {
public:
    
    Ordenamiento();
    Ordenamiento(const Ordenamiento& orig);
    virtual ~Ordenamiento();
    
    double Performancecounter_diff(LARGE_INTEGER *a, LARGE_INTEGER *b);
    
    void Seleccion(int *v, int n);
    void Insercion(int *v, int n);
    void Mezclar(int *v, int izq, int der, int centro);
    void Ordenar(int *v, int p, int q);
    void OrdenarMezcla(int *v, int p, int q);
    void Filtrado_desc(int *v, int i, int n);
    void Intercambiar(int *v, int i, int j);
    void OrdenarHeapsort(int *v, int n);
    int Dividir(int *v, int inicio, int fin);
    void Quicksort(int *v, int inicio, int fin);
    void OrdenarQuicksort(int *v, int inicio, int fin);
    void OrdenarCounting( int *v, int n, int nmax); 

private:

};

#endif /* ORDENAMIENTO_H */

