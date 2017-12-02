/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Diccionario.h
 * Author: Felipe
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
 
    void iniciar();
    
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
    void eliminar(T elemento);
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
    
    
    string listar();
    
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
void Diccionario<T>::iniciar(){
    primero = nullptr;
    ultimoLleno = 0;
}

//Diccionario<T>::Diccionario(const Diccionario& orig){
//}

template < typename T >
Diccionario<T>::~Diccionario(){
     Nodo<T> *temp = primero;
    Nodo<T> *aux = nullptr;
    while (temp != nullptr) {
        aux = temp->siguiente;
        delete temp;
        temp = aux;
    }
    delete aux;
    delete temp;
}



template < typename T >
void Diccionario< T>::vaciar(){
    primero = nullptr;
}

template <typename T>
bool Diccionario<T>::vacio(){
    return primero==nullptr;
}

template <typename T>
void Diccionario<T>::agregar(T e){
     bool existe = false;
 
    if (ultimoLleno != 0) {
        Nodo<T> *aux = primero;
        while (aux != NULL && !existe) {
            if (aux->elemento == e) {
                existe = true;
            }
            aux = aux->siguiente;
        }
    }

    if (!existe) {
        Nodo<T> *temp = new Nodo<T>(e);
        temp->siguiente = primero;
        primero = temp;
        ultimoLleno++;
    }
}

template <typename T>
void Diccionario<T>::eliminar(T e){
     Nodo<T> *temp = primero;
    while(temp->siguiente->elemento != e && temp != NULL){
        temp = temp->siguiente;
    }
    if(temp->siguiente->elemento == e){
        temp->siguiente = temp->siguiente->siguiente;
    }
    ultimoLleno--;
}

template <typename T>
bool Diccionario<T>::pertenece(T e){
    Nodo<T> *temp = primero;
    while (temp != NULL) {
        if (temp->elemento == e) {
            return true;
        }
        temp = temp->siguiente;
    }
    return false;
}

template <typename T>
int Diccionario<T>::numElem(){
     return ultimoLleno;
}

template <typename T>
string Diccionario<T>::listar(){
    stringstream fs; 
    Nodo<T> *temp = primero;
    while (temp != NULL ) {
        fs << temp->elemento << ",";
        temp = temp->siguiente;
    }
    return fs.str();
}

#endif /* DICCIONARIO_H */

