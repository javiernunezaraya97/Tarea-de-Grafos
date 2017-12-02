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
    string etiqueta;
    int numAdy;
    Vertice(){
        etiqueta = "";
        numAdy = 0;
    }
    Vertice(string e){
        etiqueta = e;
        numAdy = 0;
    }
    Vertice& operator= (const Vertice orig){
        etiqueta=orig.etiqueta;
        numAdy=orig.numAdy;
    }
};
typedef Vertice* vertice;
class MatrizDeAdy {
public:
/*
  EFE:Inicializa la matriz de adyacencia
  REQ: ---
  MOD: matrizDeAdy
*/  
    MatrizDeAdy();
 //   MatrizDeAdy(const MatrizDeAdy& orig);
/*
  EFE:destruye la matriz y regresa memoria al compilador
  REQ: grafo inicializado
  MOD: matriz---
*/
    virtual ~MatrizDeAdy();
/*
  EFE: vacia el grafo
  REQ: grafo inicializado
  MOD: ultimo
*/
    void vaciar ();
/*
  EFE: pregunta si esta vacio el grafo
  REQ: grafo inicializado
  MOD: ---
*/
    bool vacio();
/*
  EFE: agrega un vertice al grafo y lo retorna
  REQ: grafo inicializado
  MOD: grafo
*/
    vertice agregarVertice(string etiq);
/*
  EFE: elimina un vertice
  REQ: grafo inicializado y V aislado y existende
  MOD:
*/
    void eliminarVertice (vertice v);
/*
  EFE: modifica la etiqueta de V
  REQ: V existente en el grafo
  MOD: v.etiqueta
*/
    void modificarEtiqueta (vertice v, string etiq);
/*
  EFE: Retorna la etiqueta del vertice v
  REQ: v existe en grafo
  MOD: ---
*/
    string Etiqueta(vertice v);
/*
  EFE: agrega una arista entre v1 y v2 con peso recibido por parametro
  REQ: v1 y v2 en el grafo
  MOD: matrizAdyacencia
*/
    void agregarArista(vertice v1, vertice v2, int peso);
/*
  EFE: elimina la arista entre v1 y v2
  REQ: v1 y v2 en el grafo
  MOD: matrizAdyacencia
*/
    void eliminarArista(vertice v1, vertice v2);
/*
  EFE: modifica el peso de la arista entre v1 y v2
  REQ: v1 y v2 en el grafo
  MOD: matriz adyacencia
*/
    void modificarPeso(vertice v1, vertice v2, int pesoN);
/*
  EFE: retorna el peso de una arista
  REQ: v1 y v2 en el grafo
  MOD: ---
*/
    int Peso (vertice v1, vertice v2);
/*
  EFE: retorna true o false si existe adyacencia entre v1 y v2
  REQ: v1 y v2 en grafo
  MOD: ---
*/
    bool adyacentes(vertice v1, vertice v2);
/*
  EFE: retorn el primer vertice del grafo
  REQ: grafo inicializaod y no vacio
  MOD: ---
*/
    vertice primerVertice ();
/*
  EFE: retorna el siguiente vertice del grafo con v como referencia
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
    Vertice vertices[10];
    int matrizAdyacencia[10][10];
    int ultimo = -1;
    int numVertice;
};
typedef MatrizDeAdy grafo;
#endif /* MATRIZDEADY_H */

