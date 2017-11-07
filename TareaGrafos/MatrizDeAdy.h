/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   MatrizDeAdy.h
 * Author: Javier
 *
 * Created on 5 de noviembre de 2017, 11:17 p.m.
 */

#ifndef MATRIZDEADY_H
#define MATRIZDEADY_H
#include <string>
using namespace std;
struct Vertice{
    
};
typedef Vertice* vertice;
class MatrizDeAdy {
public:
/*
  EFE:
  REQ:
  MOD:
*/  
    MatrizDeAdy();
 //   MatrizDeAdy(const MatrizDeAdy& orig);
/*
  EFE:
  REQ:
  MOD:
*/
    virtual ~MatrizDeAdy();
/*
  EFE:
  REQ:
  MOD:
*/
    void vaciar ();
/*
  EFE:
  REQ:
  MOD:
*/
    bool vacio();
/*
  EFE:
  REQ:
  MOD:
*/
    vertice agregarVertice(string etiq);
/*
  EFE:
  REQ:
  MOD:
*/
    void eliminarVertice (vertice v);
/*
  EFE:
  REQ:
  MOD:
*/
    void modificarEtiqueta (vertice v, string etiq);
/*
  EFE:
  REQ:
  MOD:
*/
    string Etiqueta(vertice v);
/*
  EFE:
  REQ:
  MOD:
*/
    void agregarArista(vertice v1, vertice v2, int peso);
/*
  EFE:
  REQ:
  MOD:
*/
    void eliminarArista(vertice v1, vertice v2);
/*
  EFE:
  REQ:
  MOD:
*/
    void modificarPeso(vertice v1, vertice v2, int pesoN);
/*
  EFE:
  REQ:
  MOD:
*/
    int Peso (vertice v1, vertice v2);
/*
  EFE:
  REQ:
  MOD:
*/
    bool adyacentes(vertice v1, vertice v2);
/*
  EFE:
  REQ:
  MOD:
*/
    vertice primerVertice ();
/*
  EFE:
  REQ:
  MOD:
*/
    vertice sigVertice(vertice v);
/*
  EFE:
  REQ:
  MOD:
*/
    vertice primerVerticeAdy (vertice v);
/*
  EFE:
  REQ:
  MOD:
*/
    vertice sigVerticeAdy (vertice v, vertice vAdy);
/*
  EFE:
  REQ:
  MOD:
*/
    int numVertices ();
/*
  EFE:
  REQ:
  MOD:
*/
    int numVerticesAdy(vertice v);
    
    typedef MatrizDeAdy grafo;
private:

};

#endif /* MATRIZDEADY_H */

