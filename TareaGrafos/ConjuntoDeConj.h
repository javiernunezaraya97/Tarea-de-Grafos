/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ConjuntoDeConj.h
 * Author: Fitzberth
 *
 * Created on 5 de noviembre de 2017, 11:30 p.m.
 */

#ifndef CONJUNTODECONJ_H
#define CONJUNTODECONJ_H
#include <string.h>
#include <string>
#include <sstream>
#include <iostream>
using namespace std;
template <class T>
class ConjuntoDeConj {
public:
    //EFE:Constructuye el conjunto de conjunto disjutnos
    //REQ:---
    //MOD:
    ConjuntoDeConj();
    //EFE: Destruye el conjunto de conjuntos.
    //REQ: conjunto de conjuntos inicialiado
    //MOD: conjunto de conjuntos
    virtual ~ConjuntoDeConj();
    //EFE:vacia el conjunto de conjuntos 
    //REQ: conjunto de conjuntos inicializado
    //MOD:
    void vaciar();
    //EFE: retorna un true si el conjunto de conjuntos esta vacio y un false si no.
    //REQ: conjunto de conjuntos inicializado
    //MOD:
    bool vacio();
    //EFE: retorna el identificador del conjunto que pertenece elemento
    //REQ: conjunto de conjuntos inicializado.
    //MOD:---
    string conjuntoAlQuePertenece(T elemento);
    //EFE: agrega un conjunto con un elemento al conjunto de conjuntos.
    //REQ: conjunto de conjuntos inicializado. elemento no pertenezca a otro conjunto.
    //MOD: conjunto de conjuntos..
    void agregarConjunto(string Identificador, T elemento);
    //EFE: une los elementos del conjunto 1 con los del conjunto 2.
    //REQ: conjunto de conjuntos inicializado. ambos conjuntos existan.
    //MOD: conjunto de conjuntos.
    void unirConjuntos(ElemList conj1, ElemList conj2);
private:
    template <typename C>
            struct ElemList{
        C elemento;    
        ElemList *sig;
        ElemList(C e){
               elemento = e;
                sig = nullptr;
            };
        ElemList(){};
        };
    template <typename C>
    struct ConjuntosList{

        string identificador;
        ConjuntosList *sig;
        ElemList *conjuntos;
        ConjuntosList(string id, C e){
            identificador = id;
            conjuntos = new ElemList(e);
            sig = nullptr;
        }
        ConjuntosList(){identificador="";conjuntos=new ElemList; sig=nullptr;};
    };
    ConjuntosList<T>* primero;
};
    template <typename T>
    ConjuntoDeConj<T>::ConjuntoDeConj(){
        primero= new ConjuntosList<T>;
    }
    template <typename T>
    ConjuntoDeConj<T>::~ConjuntoDeConj(){
        
    }
    
    template <typename T>
    void ConjuntoDeConj<T>::vaciar(){
    
    }

    template <typename T>
    bool ConjuntoDeConj<T>::vacio(){
    
    }
    
    template <typename T>
    void ConjuntoDeConj<T>::agregarConjunto(string Identificador, T elemento){
        ConjuntosList<T> nConj= new ConjuntosList<T>(Identificador, elemento);
        nConj.sig=primero;
        primero=nConj;
    }
    template <typename T>
    string ConjuntoDeConj<T>::conjuntoAlQuePertenece(T elem){
        bool encontrado=false;
        ElemList auxElem=primero->conjuntos;
        ConjuntosList auxConj=primero;
        string buscado= "";
        while ((auxConj==nullptr)&&(!encontrado)){
            while ((auxElem==nullptr)&&(!encontrado)){
                if (auxElem.elemento==elem){
                    encontrado=true;
                }
                else 
                    auxElem=auxElem.sig;
            }
            if (!encontrado)
                auxConj=auxConj.sig;
        }
        if (encontrado)
            buscado= auxConj.identificador;
        return buscado;
    }
    template <typename T>
    void ConjuntoDeConj<T>::unirConjuntos(T conj1, T conj2){
        
    }
//};

#endif /* CONJUNTODECONJ_H */

