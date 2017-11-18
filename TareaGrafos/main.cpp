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
using namespace std;
#include "ListaDeAdy.h"
/*
 * 
 */
int main(int argc, char** argv) {

    grafo *g=new grafo;
    
    vertice v1=g->agregarVertice("prueba");
        cout<< v1->etiqueta<<"\n";
       vertice v2= g->agregarVertice("katherine fea");
            cout<< v2->etiqueta<<"\n";
       g->agregarArista(v1,v2,10);
            bool esAdy=g->adyacentes(v1,v2);
                cout<< g->Peso(v1,v2);
            v1= g->agregarVertice("k fea");
            cout<< v1->etiqueta<<"\n";
        v1= g->agregarVertice("ka fea");
    cout<< v1->etiqueta<<"\n";
    cout<< g->numVertices()<<"\n";
        

    
    if (esAdy){
        cout<< "es ady\n";
    } else
    cout<< "no es ady\n";

    return 0;
}

