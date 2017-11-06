/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ListaDeAdy.h
 * Author: Javier
 *
 * Created on 5 de noviembre de 2017, 11:19 p.m.
 */

#ifndef LISTADEADY_H
#define LISTADEADY_H
#include <string>

using namespace std;
struct Vertice{
    string etiqueta;
    
    Vertice():etiqueta(""){};
};
typedef Vertice* vertice;
class ListaDeAdy {
public:
/*
  EFE:
  REQ:
  MOD:
*/
    ListaDeAdy();
//    ListaDeAdy(const ListaDeAdy& orig);
/*
  EFE:
  REQ:
  MOD:
*/
    virtual ~ListaDeAdy();
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
    void modificarPeso(/*Arista a*/ int pesoN);
/*
  EFE:
  REQ:
  MOD:
*/
    int Peso (/*Arista a*/);
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
private:

};

#endif /* LISTADEADY_H */

