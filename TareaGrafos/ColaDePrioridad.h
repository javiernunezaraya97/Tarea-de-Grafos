/* 
 * File:   ColaDePrioridad.h
 * Author: Javier
 *
 * Created on 5 de noviembre de 2017, 11:24 p.m.
 */

#ifndef COLADEPRIORIDAD_H
#define COLADEPRIORIDAD_H
//#define SIZE 10
#include <iostream>
#include <string>
#include <memory>
#include <sstream>
using namespace std;

template <class A,int tam> 
class ColaDePrioridad{
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
    //    void borrar(A elemento);
private:
    
//template <A,tam>
struct Caja {
        A elemento;
        int prioridad;
        *Caja(A e, int pri) {
            elemento=e;
            prioridad=pri;
        }
    };
    
    Caja* heap[tam];
    int ultimo;
    int contador;
};

template <typename A,int tam>  
ColaDePrioridad<A,tam>::ColaDePrioridad() {
    ultimo = 0;
    contador = 0;
}

template <class A,int tam> 
ColaDePrioridad<A,tam>::~ColaDePrioridad() {

}

template <class A,int tam> 
void ColaDePrioridad<A,tam>::vaciar() {
    ultimo = 0;
    contador = 0;
}

template <class A,int tam> 
bool ColaDePrioridad<A,tam>::vacia() {
    return (ultimo == 0);
}

template <class A,int tam> 
void ColaDePrioridad<A,tam>::agregar(A elemento, int prioridad) {
    Caja nuevo = Caja ;
    nuevo.elemento=elemento;
    nuevo.prioridad=prioridad;
    Caja padre;
    ultimo++;
    contador++;
    heap[ultimo] = nuevo;
    int iterador = ultimo;
    while ((iterador > 1) && (heap[iterador].prioridad > heap[iterador / 2].prioridad)) {
        padre = heap[iterador / 2];
        heap[iterador / 2] = heap[iterador];
        iterador = iterador / 2;
    }
}

template <class A,int tam> 
A ColaDePrioridad<A,tam>::sacar() {
    Caja auxiliar = heap[1];
    Caja padre = heap[1];
    bool terminado = false;
    int iterador = 1;
    int minimo = 1;
    heap[1] = heap[ultimo];
    ultimo--;
    contador--;
    while (!terminado) {
        if (iterador * 2 > ultimo) {
            if (heap[iterador * 2].prioridad > heap[ultimo].prioridad) {
                minimo = iterador * 2;
                if ((heap[iterador * 2 + 1].prioridad > heap[minimo].prioridad)) {
                    minimo = iterador * 2 + 1;
                }
            }
            if (iterador != minimo) {
                padre = heap[iterador];
                heap[iterador] = heap[minimo];
                heap[minimo] = padre;
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

template <class A,int tam> 
int ColaDePrioridad<A,tam>::numElem() {
    return contador;
}
#endif /* COLADEPRIORIDAD_H */