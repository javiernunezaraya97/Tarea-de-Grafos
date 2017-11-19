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
    //EFE:
    //REQ:
    //MOD:
    virtual ~ConjuntoDeConj();
    //EFE:
    //REQ:
    //MOD:
    void vaciar();
    //EFE:
    //REQ:
    //MOD:
    bool vacio();
    //EFE:
    //REQ:
    //MOD:
    string conjuntoAlQuePertenece(T elemento);
    //EFE:
    //REQ:
    //MOD:
    void agregarConjunto(string Identificador, T elemento);
    //EFE:
    //REQ:
    //MOD:
    void unirConjuntos(T conj1, T conj2);
private:
    template <typename C>
    struct ConjuntoDeConjuntos{
        struct Conjunto{
        C elemento;    
        Conjunto *sig;
        Conjunto(C e){
                Conjunto.elemento = e;
                Conjunto.sig = nullptr;
            };
        }
        string identificador;
        ConjuntoDeConjuntos *sig;
        Conjunto *conjuntos;
        ConjuntoDeConjuntos(string id, C e){
            identificador = id;
            conjuntos = new Conjunto(elemento);
            sig = nullptr;
        }
    };
    ConjuntoDeConjuntos *primero;
    template <typename T>
    ConjuntoDeConj<T>::ConjuntoDeConj(){
        
    }
    ConjuntoDeConj<T>::~ConjuntoDeConj(){
        
    }
    void ConjuntoDeConj<T>::agregarConjunto(string Identificador, T elemento){
        
    }
    string ConjuntoDeConj<T>::conjuntoAlQuePertenece(){
        
    }
    void ConjuntoDeConj<T>::unirConjuntos(T conj1, T conj2){
        
    }
};

#endif /* CONJUNTODECONJ_H */

