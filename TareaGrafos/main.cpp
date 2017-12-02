/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Javier
 *
 * Created on 5 de noviembre de 2017, 11:11 p.m.
 */

#include <iostream>
//#define SIZE 10
#include "AlgoritmosGrafos.h"
//#include "MatrizDeAdy.h"
#include "ListaDeAdy.h"
#include "Diccionario.h"
#include "ColaDePrioridad.h"
#include "ConjuntoDeConj.h"
#include <string>
#include <ctime>
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    srand(10042017);
    
    grafo* g= new grafo;
    AlgoritmosGrafos AG;
    vertice vj;
//    for (int i = 0; i <= 50; ++i) {
//        vj = g->agregarVertice(to_string(i));
//        if (i > 0 && i < 50) {
//            g->agregarArista(g->primerVertice(), g->sigVertice(vj), 3);
//        }
//    }
    vertice v1;
    vertice v2;
    int n=20;
    int p;
    for (int i = 0; i < n; ++i){
        g->agregarVertice(to_string(i));
    }
//   const grafo gPrueba=g;
    for (int i = 0; i < n; ++i){
         
        v1 = AG.buscarEtiq(to_string(i),*g);
        for (int j = 0; j < n/3; ++j)
        {  // g=gPrueba;
            p = (rand()%20) + 1;
            v2 = AG.buscarEtiq(to_string(rand()%(n-1)), *g);
            while ((g->adyacentes(v1, v2)) || (v1 == v2))
            {   //g=gPrueba;
                v2 = AG.buscarEtiq(to_string(rand()%n), *g);
            }
           // g=gPrueba;
            g->agregarArista(v1,v2,p);
           // gPrueba=g;
        }
        
    }
    
    AG.vendedor(*g);
    cout<< "hola";
    int j=n;



    return 0;

}

