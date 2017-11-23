/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ColaDePrioridad.h
 * Author: Luis
 *
 * Created on November 22, 2017, 7:35 PM
 */

#ifndef COLADEPRIORIDAD_H
#define COLADEPRIORIDAD_H
#define SIZE 10
#include <string.h>
#include <string>
#include <sstream>
#include <iostream>
using namespace std;

template <class A>
class ColaDePrioridad {
public:
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
  REQ:
  MOD:
     */
    bool vacia();
    /*
  EFE: Agrega un elemento a la cola segun su prioridad
  REQ: Cola Inicializada
  MOD: Cola
     */
    void agregar(A elemento, int prioridad);
    /*
  EFE: Saca el primer elemento de la Cola 
  REQ: Cola inicializada
  MOD: Cola
     */
    A sacar();
    //    /*
    //  EFE: Modifica la prioridad de un elemento A
    //  REQ: Cola inicializada
    //  MOD: Cola
    //     */
    //    void modificarPrioridad(A elemento, int nuevaPrioridad);
    /*
  EFE: Devuelve el numero de elementos de la cola
  REQ: Cola inicializada
  MOD:
     */
    int numElem();
    //    /*
    //  EFE: Borra un elmento de la Cola
    //  REQ: Cola Inicializada
    //  MOD: Cola
    //     */   
private:
    template <typename B>
    struct Caja {
        B elemento;
        int prioridad;
        Caja(B elementoNuevo, int nuevaPrioridad) {
            elemento = elementoNuevo;
            prioridad = nuevaPrioridad;
        }
    };
    Caja<A> arreglo[10];
    int ultimo;
    int contador;
};
    template <typename A>
    ColaDePrioridad<A>::ColaDePrioridad(){
        ultimo = 0;
        contador = 0;
    }
  template <class A> 
ColaDePrioridad<A>::~ColaDePrioridad() {

}

template <class A> 
void ColaDePrioridad<A>::vaciar() {
    ultimo = 0;
    contador = 0;
}

template <class A> 
bool ColaDePrioridad<A>::vacia() {
    return (ultimo == 0);
}

template <class A> 
void ColaDePrioridad<A>::agregar(A elemento, int prioridad) {
    Caja<A> nuevo = new Caja<A>(elemento,prioridad);
    Caja<A> padre = nuevo;
    ultimo++;
    contador++;
    arreglo[ultimo] = nuevo;
    int iterador = ultimo;
    while ((iterador > 1) && (arreglo[iterador].prioridad > arreglo[iterador / 2].prioridad)) {
        padre = arreglo[iterador / 2];
        arreglo[iterador / 2] = arreglo[iterador];
        iterador = iterador / 2;
    }
}

template <class A> 
A ColaDePrioridad<A>::sacar() {
    Caja<A> auxiliar = arreglo[1];
    Caja<A> padre = arreglo[1];
    bool terminado = false;
    int iterador = 1;
    int minimo = 1;
    arreglo[1] = arreglo[ultimo];
    ultimo--;
    contador--;
    while (!terminado) {
        if (iterador * 2 > ultimo) {
            if (arreglo[iterador * 2].prioridad > arreglo[ultimo].prioridad) {
                minimo = iterador * 2;
                if ((arreglo[iterador * 2 + 1].prioridad > arreglo[minimo].prioridad)) {
                    minimo = iterador * 2 + 1;
                }
            }
            if (iterador != minimo) {
                padre = arreglo[iterador];
                arreglo[iterador] = arreglo[minimo];
                arreglo[minimo] = padre;
                iterador = minimo;
            } else {
                terminado = true;
            }
        } else {
            terminado = true;
        }
    }
    return auxiliar.elemento;
}

template <class A> 
int ColaDePrioridad<A>::numElem() {
    return contador;
}  
//};
#endif /* COLADEPRIORIDAD_H */

