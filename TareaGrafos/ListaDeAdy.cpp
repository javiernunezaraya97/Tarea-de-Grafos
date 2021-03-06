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
    vertice v= vertInicial;
    
    while(v!=nullptr) {
        deleteAllEdges(v->adyacencia);
        v->cantAdy=0;
        v=v->sgtVertice;
        
    }
    deleteAllVertex(vertInicial);
    cantVert=0;    
}

void ListaDeAdy::vaciar(){
    vertice v= vertInicial;
    
    while(v!=nullptr) {
        deleteAllEdges(v->adyacencia);
        v->cantAdy=0;
        v=v->sgtVertice;
        
    }
    deleteAllVertex(vertInicial);
    //cantVert=0;    
    vertInicial=new Vertice();
}

bool ListaDeAdy::vacio(){
    return cantVert==0;
}

vertice ListaDeAdy::agregarVertice(string etiq){
    vertice nVert= new Vertice(etiq);
    
    if(cantVert==0){
        vertInicial=nVert;
    }else {
    nVert->sgtVertice=vertInicial;
    vertInicial=nVert;
    }
    cantVert++;
    return nVert;
}

void ListaDeAdy::eliminarVertice(vertice v){
    bool encontrado=false;
    if(cantVert==1){
        vertInicial=nullptr;
    } else  {
        vertice aux=vertInicial;
        while(!encontrado){
            if(aux->sgtVertice==v){
                encontrado=true;
            }
            else aux=aux->sgtVertice;
        }
        if(v->sgtVertice==nullptr){
            aux->sgtVertice=nullptr;
        } else {
            aux->sgtVertice=v->sgtVertice;
        }
    }
    delete(v);
    cantVert--;
}
void ListaDeAdy::modificarEtiqueta(vertice v, string etiq){
    v->etiqueta=etiq;
}
string ListaDeAdy::Etiqueta(vertice v)const{
    return v->etiqueta;
}
void ListaDeAdy::agregarArista(vertice v1, vertice v2, int peso){
    Arista* adyNv1= new Arista(peso,v2);
    
    if (v1->cantAdy==0){
        v1->adyacencia=adyNv1;
    } else {   
        adyNv1->sgtAdy= v1->adyacencia;
        v1->adyacencia=adyNv1;
    }
    Arista* adyNv2= new Arista(peso,v1);
    
    if (v2->cantAdy==0)
        v2->adyacencia=adyNv2;
    else {
        adyNv2->sgtAdy=v2->adyacencia;
        v2->adyacencia=adyNv2;
    }

    v1->cantAdy++;
    v2->cantAdy++;
    
}
void ListaDeAdy::eliminarArista(vertice v1, vertice v2){
    
    arista aristaAux= v1->adyacencia;
    if (v1->cantAdy==1){
        v1->adyacencia=nullptr;
        delete(aristaAux);
    } else {
        
        arista ady=aristaAux->sgtAdy;
        while ((aristaAux->sgtAdy!=nullptr)&&(ady->ptrVert!=v2)){
            aristaAux=ady;
            ady=ady->sgtAdy;
        }
        if (aristaAux->sgtAdy->sgtAdy==nullptr){
            aristaAux->sgtAdy=nullptr;
        } else {
            aristaAux->sgtAdy=ady->sgtAdy;
        }
        delete(ady);
    }
     aristaAux= v2->adyacencia;
    if (v2->cantAdy==1){
        v2->adyacencia=nullptr;
        delete(aristaAux);
    } else {
        
        arista ady=aristaAux->sgtAdy;
        while ((aristaAux->sgtAdy!=nullptr)&&(ady->ptrVert!=v2)){
            aristaAux=ady;
            ady=ady->sgtAdy;
        }
        if (aristaAux->sgtAdy->sgtAdy==nullptr){
            aristaAux->sgtAdy=nullptr;
        } else {
            aristaAux->sgtAdy=ady->sgtAdy;
        }
        delete(ady);
    }
    
    
    
}
void ListaDeAdy::modificarPeso(vertice v1, vertice v2, int pesoN){
    arista ady= v1->adyacencia;
    while (ady->ptrVert!=v2){
        ady=ady->sgtAdy;
    } 
    ady->peso=pesoN;
    ady=v2->adyacencia;
    while (ady->ptrVert!=v1){
        ady=ady->sgtAdy;
    }
    ady->peso=pesoN;
    
}
int ListaDeAdy::Peso(vertice v1, vertice v2)const{
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

bool ListaDeAdy::adyacentes(vertice v1, vertice v2)const{
    bool encontrado=false;
    arista ady= v1->adyacencia;
    
    while ((ady!=nullptr)&&(!encontrado)){
        if (ady->ptrVert->etiqueta==v2->etiqueta){
            encontrado=true;
        }
        else 
            ady=ady->sgtAdy;
    }
    
    return encontrado;
}

vertice ListaDeAdy::primerVertice() const {
    return vertInicial;
}
vertice ListaDeAdy::sigVertice(vertice v)const{
    return v->sgtVertice;
}
vertice ListaDeAdy::primerVerticeAdy(vertice v)const{
    vertice va=nullptr;
    if (v->adyacencia!=nullptr){
        va=v->adyacencia->ptrVert;
    }
    return va;
}
vertice ListaDeAdy::sigVerticeAdy(vertice v, vertice vAdy)const{
    arista AdySgt=v->adyacencia;
    vertice aux=nullptr;
    while ((AdySgt->sgtAdy!=nullptr)&&(AdySgt->ptrVert!=vAdy)){
        AdySgt=AdySgt->sgtAdy;
    }
    if ((AdySgt->ptrVert==vAdy)&&(AdySgt->sgtAdy!=nullptr)){
        aux=AdySgt->sgtAdy->ptrVert;
    }
    return aux;
}
int ListaDeAdy::numVertices()const{
    return cantVert;
}
int ListaDeAdy::numVerticesAdy(vertice v)const{
    return v->cantAdy;
}

void ListaDeAdy::deleteAllEdges(arista ady){
    if (ady!=nullptr){
        deleteAllEdges(ady->sgtAdy);
        delete(ady);
    }
}

void ListaDeAdy::deleteAllVertex(vertice v){
    if (v!=nullptr){
        deleteAllVertex(v->sgtVertice);
        cantVert--;
        delete(v);
    }
}