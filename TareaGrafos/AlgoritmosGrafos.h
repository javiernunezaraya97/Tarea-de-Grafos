/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   AlgoritmosGrafos.h
 * Author: Javier
 *
 * Created on 5 de noviembre de 2017, 11:35 p.m.
 */

#ifndef ALGORITMOSGRAFOS_H
#define ALGORITMOSGRAFOS_H
#include "ColaDePrioridad.h"
#include "ConjuntoDeConj.h"
//#include "Diccionario.h"
#include "ListaDeAdy.h"
//#include "MatrizDeAdy.h"

class AlgoritmosGrafos {
public:
    AlgoritmosGrafos();
    AlgoritmosGrafos(const AlgoritmosGrafos& orig);
    virtual ~AlgoritmosGrafos();
    
    grafo Iguales(grafo g);
    
    void kruskal();
    
private:

};

#endif /* ALGORITMOSGRAFOS_H */

