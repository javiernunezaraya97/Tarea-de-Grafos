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
#include <limits>
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
    void Dijkstra(vertice v, const grafo& g);

    /*
      EFE:
      REQ:
      MOD:
     */
    void Floyd(const grafo& grf);
    /*
      EFE:
      REQ:
      MOD:
     */
    void Prim(const grafo& grf);
    /*
      EFE:
      REQ: grafo inicializado y no vacio, que contenga al menos una arista.
      MOD:
     */
    void Kruskal(const grafo& g);
    /*
  EFE:
  REQ:
  MOD:
     */
    grafo Copiar(const grafo& grf);
    /*
  EFE:
  REQ:
  MOD:
     */

    bool Iguales(const grafo& g1,const grafo& g2);
    /*
    EFE: parte recursiva del vendedor.
    REQ: grafo inicializado
    MOD: ---
     */
    void visitarVertRec(const grafo&, int i);

    /*
    EFE: Encuentra el circuito de menor costo y lo despliega en consola
    REQ:  grafo inicializado
    MOD:---
     */
    void vendedor(const grafo&);

    vertice buscarEtiq(string etiq,const grafo& g);

private:
    ConjuntoDeConj<vertice> cnjDeCnj;

};

#endif /* ALGORITMOSGRAFOS_H */

