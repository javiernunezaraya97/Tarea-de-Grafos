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
  EFE:
  REQ:
  MOD:
*/
    virtual ~ColaDePrioridad();
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
    bool vacia();
    /*
  EFE:
  REQ:
  MOD:
*/
    void agregar(T elemento,int prioridad);
    /*
  EFE:
  REQ:
  MOD:
*/
    T sacar();
    /*
  EFE:
  REQ:
  MOD:
*/
    void modificarPrioridad(T elemento, int nuevaPrioridad);
    /*
  EFE:
  REQ:
  MOD:
*/
    int numElem();
    /*
  EFE:
  REQ:
  MOD:
*/
    void borrar(T elemento);
private:

};

#endif /* COLADEPRIORIDAD_H */

