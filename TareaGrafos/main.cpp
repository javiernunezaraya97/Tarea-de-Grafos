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
#define SIZE 10
#include "ListaDeAdy.h"
#include "ColaDePrioridad.h"
using namespace std;
/*
 * 
 */
int main(int argc, char** argv) {
    ColaDePrioridad<string,SIZE> cola;
    int i=cola.numElem();
    cola.agregar("Hola",1);
//    cola.agregar("Kikut",8);
//    cola.agregar("Sandra",7);
//    cola.agregar("Guapa",2);
//    for(int i=0;i<cola.numElem();i++){
        cout<<"Elemento: "<<i<<"\n";
//    }
    
    grafo *g=new grafo;
    
    vertice v1=g->agregarVertice("prueba");
        cout<< "etiqueta: "<<v1->etiqueta<<"\n";
       vertice v2= g->agregarVertice("katherine fea");
            cout<<"etiqueta2: "<< v2->etiqueta<<"\n";
       g->agregarArista(v1,v2,10);
            bool esAdy=g->adyacentes(v1,v2);
                cout<<"peso: "<< g->Peso(v1,v2)<<"\n";
            v2= g->agregarVertice("k fea");
       g->agregarArista(v1,v2,14);
            esAdy=g->adyacentes(v1,v2);
            cout<< v2->etiqueta<<"\n"<< esAdy<<"\n";
            cout<<"peso: "<< g->Peso(v1,v2)<<"\n";
        v2= g->agregarVertice("ka fea");
        g->agregarArista(v1,v2,6);
        esAdy=g->adyacentes(v1,v2);
        cout<<"peso: "<< g->Peso(v1,v2)<<"\n";
        g->modificarPeso(v1,v2,22);
        
        cout<<"peso nuevo: "<< g->Peso(v1,v2)<<"\n";
        cout<<"peso nuevo: "<< g->Peso(v2,v1)<<"\n";
        cout<< v1->etiqueta<<"\n"<< esAdy<<"\n";
        cout<< v2->etiqueta<<"\n";
    cout<< g->numVertices()<<"\n";
    cout<< g->numVerticesAdy(v1)<<"\n";
    
    
    v2=g->primerVerticeAdy(v1);
    cout<< g->Etiqueta(v2)<<"\n";
    v2= g->sigVerticeAdy(v1,v2);
    cout<< g->Etiqueta(v2)<<"\n";
    v2= g->sigVerticeAdy(v1,v2);
    cout<< g->Etiqueta(v2)<<"\n";


    g->vaciar();
    bool vacio=g->vacio();
    
    return 0;

}

