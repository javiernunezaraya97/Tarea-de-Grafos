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

#include <utility> 
#include <vector>
#include "map"
#include<string>
#include "ColaDePrioridad.h"
#include "ConjuntoDeConj.h"
#include "Diccionario.h"
#include "ListaDeAdy.h"
//#include "MatrizDeAdy.h"
using namespace std;


class AlgoritmosGrafos {
public:
    /*
      EFE:
      REQ:
      MOD:
     */
    AlgoritmosGrafos();
    //AlgoritmosGrafos(const AlgoritmosGrafos& orig);
    /*
      EFE:
      REQ:
      MOD:
     */
    virtual ~AlgoritmosGrafos();

    
        /*
      EFE:
      REQ:
      MOD:
     */
    void Dijkstra(vertice v);

    /*
      EFE:
      REQ:
      MOD:
     */
    void Floyd();
    /*
      EFE:
      REQ:
      MOD:
     */
    void Prim();
    /*
      EFE:
      REQ: grafo inicializado y no vacio, que contenga al menos una arista.
      MOD:
     */
    void Kruskal(grafo g);
    /*
  EFE:
  REQ:
  MOD:
     */
    grafo Copiar(grafo);
    /*
  EFE:
  REQ:
  MOD:
     */
    bool Iguales(grafo g1, grafo g2);

        /*
  EFE: parte recursiva del vendedor.
  REQ: grafo inicializado
  MOD: ---
     */
    void visitarVertRec(grafo, int i);
    
        /*
  EFE: Encuentra el circuito de menor costo y lo despliega en consola
  REQ:  grafo inicializado
  MOD:---
     */
    void vendedor(grafo);
    
    vertice buscarEtiq(string etiq, grafo g);
    
private:
    ConjuntoDeConj<vertice> cnjDeCnj;
    
};

#endif /* ALGORITMOSGRAFOS_H */

