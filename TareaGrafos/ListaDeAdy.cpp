/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ListaDeAdy.cpp
 * Author: Javier
 * 
 * Created on 5 de noviembre de 2017, 11:19 p.m.
 */

#include "ListaDeAdy.h"

ListaDeAdy::ListaDeAdy() {
    vertInicial=new Vertice();
    cantVert=0;
}

ListaDeAdy::~ListaDeAdy() {
    
}

void ListaDeAdy::vaciar(){
    
}

bool ListaDeAdy::vacio(){
    return cantVert==0;
}

vertice ListaDeAdy::agregarVertice(string etiq){
    
}
void ListaDeAdy::eliminarVertice(vertice v){
    
}
void ListaDeAdy::modificarEtiqueta(vertice v, string etiq){
    v->etiqueta=etiq;
}
string ListaDeAdy::Etiqueta(vertice v){
    return v->etiqueta;
}
void ListaDeAdy::agregarArista(vertice v1, vertice v2, int peso){
    Arista* adyN= new Arista(peso,v2);
    
    if (v1->cantAdy==0){
        v1->adyacencia=adyN;
    } else {   
        adyN->sgtAdy= v1->adyacencia;
        v1->adyacencia=adyN;
    }
    adyN->ptrVert=v1;
    adyN->sgtAdy=nullptr;
    
    if (v2->cantAdy==0)
        v2->adyacencia=adyN;
    else {
        adyN->sgtAdy=v2->adyacencia;
        v2->adyacencia=adyN;
    }

    v1->cantAdy++;
    v2->cantAdy++;
    
}
void ListaDeAdy::eliminarArista(vertice v1, vertice v2){
 
    
    
    
    
}
void ListaDeAdy::modificarPeso(vertice v1, vertice v2, int pesoN){
    
}
int ListaDeAdy::Peso(vertice v1, vertice v2){
    arista ady= v1->adyacencia;
    int pesoAdy=-1;
    while ((ady->ptrVert!=v2)&&(ady->sgtAdy!=nullptr)){
        ady=ady->sgtAdy;
    }
    /*REVISAR A PIE*/
    if(ady->ptrVert==v2)
        pesoAdy=ady->peso;    
    return pesoAdy;
}

bool ListaDeAdy::adyacentes(vertice v1, vertice v2){
    bool encontrado=false;
    arista ady= v1->adyacencia;
    
    while ((ady->sgtAdy!=nullptr)&&(!encontrado)){
        if (ady->ptrVert==v2){
            encontrado=true;
        }
        else 
            ady=ady->sgtAdy;
    }
    
    return encontrado;
}

vertice ListaDeAdy::primerVertice(){
    return vertInicial;
}
vertice ListaDeAdy::sigVertice(vertice v){
    return v->sgtVertice;
}
vertice ListaDeAdy::primerVerticeAdy(vertice v){
    return v->adyacencia->ptrVert;
}
vertice ListaDeAdy::sigVerticeAdy(vertice v, vertice vAdy){
    
}
int ListaDeAdy::numVertices(){
    return cantVert;
}
int ListaDeAdy::numVerticesAdy(vertice v){
    return v->cantAdy;
}
