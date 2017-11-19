 /*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ColaDePrioridad.h
 * Author: Javier
 *
 * Created on 5 de noviembre de 2017, 11:24 p.m.
 */

#ifndef COLADEPRIORIDAD_H
#define COLADEPRIORIDAD_H
#define SIZE 10
#include <iostream>
#include <string>
#include <memory>
#include <sstream>
using namespace std;

template <class T>
class ColaDePrioridad {
public:
    T heap [SIZE];
    int primero;
    int ultimo;
    int contador;
    /*
  EFE: Crea una Cola vacia 
  REQ: Cola no inicializada
  MOD: 
*/
    ColaDePrioridad();
//    ColaDePrioridad(const ColaDePrioridad& orig);
    /*
  EFE: Destruye la cola
  REQ: Cola inicializada
  MOD: Cola
*/
    virtual ~ColaDePrioridad();
    /*
  EFE: Vacia la Cola
  REQ: Cola Inicializada
  MOD: Cola
*/
    void vaciar();
    /*
  EFE: verifica si la cola esta vacia
  REQ: cola inicializada
  MOD:
*/
    bool vacia();
    /*
  EFE: Agrega un elemento a la cola segun su prioridad
  REQ: Cola Inicializada
  MOD: Cola
*/
    void agregar(T elemento,int prioridad);
    /*
  EFE: Saca el primer elemento de la Cola 
  REQ: Cola inicializada
  MOD: Cola
*/
    T sacar();
    /*
  EFE: Modifica la prioridad de un elemento T
  REQ: Cola inicializada
  MOD: Cola
*/
    void modificarPrioridad(T elemento, int nuevaPrioridad);
    /*
  EFE: Devuelve el numero de elementos de la cola
  REQ: Cola inicializada
  MOD:
*/
    int numElem();
    /*
  EFE: Borra un elmento de la Cola
  REQ: Cola Inicializada
  MOD: Cola
*/
    void borrar(T elemento);
private:

};
template <typename T> ColaDePrioridad<T>::ColaDePrioridad(){
    primero = -1;
    ultimo = -1;
    contador = 0;
}

template <typename T> ColaDePrioridad<T>::~ColaDePrioridad(){
    
}

template <typename T> ColaDePrioridad<T>::vaciar(){
    
}

template <typename T> ColaDePrioridad<T>::vacia(){
    
}

template <typename T> ColaDePrioridad<T>::agregar(T elemento, int prioridad){
    
}

template <typename T> ColaDePrioridad<T>::sacar(){
    
}

template <typename T> ColaDePrioridad<T>::modificarPrioridad(T elemento, int nuevaPrioridad){
    
}

template <typename T> ColaDePrioridad<T>::numElem(){
    return contador;
}

template <typename T> ColaDePrioridad<T>::borrar(T elemento){
    
}
#endif /* COLADEPRIORIDAD_H */

