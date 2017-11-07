/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Diccionario.h
 * Author: Javier
 *
 * Created on 5 de noviembre de 2017, 11:34 p.m.
 */

#ifndef DICCIONARIO_H
#define DICCIONARIO_H
#include <iostream>
#include <string>
#include <memory>
#include <sstream>
using namespace std;

template <class T>
class Diccionario {
public:
/*
  EFE:
  REQ:
  MOD:
*/
    Diccionario();
 /*
  EFE:
  REQ:
  MOD:
*/
    virtual ~Diccionario();
/*
  EFE:
  REQ:
  MOD:
*/
    void vaciar();
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
    void agregar(T elemento);
/*
  EFE:
  REQ:
  MOD:
*/
    void borrar(T elemento);
/*
  EFE:
  REQ:
  MOD:
*/
    bool pertenece(T elemento);
/*
  EFE:
  REQ:
  MOD:
*/
    int numElem();
    
    
    string Listar();
    
    int ultimoLleno;
private:
template <typename V >
    struct Nodo {
        V elemento;
        Nodo *siguiente;
        Nodo(){};
        Nodo(V e) {
            elemento = e;
            siguiente = nullptr;
        }
    };
    Nodo<T> *primero;
};
template<typename T>
Diccionario<T>::Diccionario(){
    primero = nullptr;
    ultimoLleno = 0;
}

template < typename T >
Diccionario<T>::Diccionario(const Diccionario& orig){
}

template < typename T >
Diccionario<T>::~Diccionario(){
}

template < typename T >
void Diccionario< T>::Crear(){
    primero = nullptr;
    ultimoLleno = 0;
}

template < typename T >
void Diccionario<T>::Destruir(){
    Nodo<T> *temp = primero;
    Nodo<T> *aux = nullptr;
    while (temp != nullptr) {
        aux = temp->sgt;
        delete temp;
        temp = aux;
    }
    delete aux;
    delete temp;
}

template < typename T >
void Diccionario< T>::Vaciar(){
    primero = NULL;
}

template <typename T>
bool Diccionario<T>::Vacio(){
     if (primero != NULL) {
        return false;
    }
    return true;
}

template <typename T>
void Diccionario<T>::Agregar(T e){
     bool existe = false;
 
    if (ultimoLleno != 0) {
        Nodo<T> *aux = primero;
        while (aux != NULL && !existe) {
            if (aux->elemento == e) {
                existe = true;
            }
            aux = aux->sgt;
        }
    }

    if (!existe) {
        Nodo<T> *temp = new Nodo<T>(e);
        temp->sgt = primero;
        primero = temp;
        ultimoLleno++;
    }
}

template <typename T>
void Diccionario<T>::Eliminar(T e){
     Nodo<T> *temp = primero;
    while(temp->sgt->elemento != e && temp != NULL){
        temp = temp->sgt;
    }
    if(temp->sgt->elemento == e){
        temp->sgt = temp->sgt->sgt;
    }
    ultimoLleno--;
}

template <typename T>
bool Diccionario<T>::Pertenece(T e){
    Nodo<T> *temp = primero;
    while (temp != NULL) {
        if (temp->elemento == e) {
            return true;
        }
        temp = temp->sgt;
    }
    return false;
}

template <typename T>
int Diccionario<T>::NumElem(){
     return ultimoLleno;
}

template <typename T>
string Diccionario<T>::Listar(){
    stringstream fs; 
    Nodo<T> *temp = primero;
    while (temp != NULL ) {
        fs << temp->elemento << ",";
        temp = temp->sgt;
    }
    return fs.str();
}

#endif /* DICCIONARIO_H */

