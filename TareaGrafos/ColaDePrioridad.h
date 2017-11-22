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

template <class A> 
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
    
//template <typename A>

struct Caja {
        A elemento;
        int prioridad;
        Caja(A e, int pri) {
            elemento=e;
            prioridad=pri;
        }
    };
    
    Caja heap[SIZE];
    int ultimo;
    int contador;
};

template <typename A>  
ColaDePrioridad<A>::ColaDePrioridad() {
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
    Caja nuevo = new Caja(elemento, prioridad);
    Caja padre = new Caja(elemento, prioridad);
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

template <class A> 
A ColaDePrioridad<A>::sacar() {
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

//template <class A> void ColaDePrioridad<A>::modificarPrioridad(A elemento, int nuevaPrioridad) {
//    int auxiliar = 0;
//    bool encontrado = false;
//    while ((auxiliar <= ultimo)&& !encontrado) {
//        if (heap[auxiliar].elemento == elemento) {
//            if (heap[auxiliar].prioridad < nuevaPrioridad) {
//                heap[auxiliar].prioridad = nuevaPrioridad;
//                ordenarEntrada(auxiliar);
//            } else {
//                heap[auxiliar].prioridad = nuevaPrioridad;
//                ordenarSalida(auxiliar);
//            }
//
//            encontrado = true;
//        }
//        auxiliar++;
//    }
//}

template <class A> 
int ColaDePrioridad<A>::numElem() {
    return contador;
}
//
//template <class A> void ColaDePrioridad<A>::borrar(A elemento) {
//    //    int auxiliar = 1;
//    int iterador = 1;
//    int minimo = 0;
//    Caja padre = new Caja(elemento, 0);
//    bool encontrado = false;
//    bool terminado = false;
//    while ((iterador <= ultimo)&& !encontrado) {
//        if (heap[iterador].elemento == elemento) {
//            if (heap[iterador].elemento == heap[ultimo].elemento) {
//                ultimo--;
//                contador--;
//            } else {
//                heap[iterador] = heap[ultimo];
//                ultimo--;
//                contador--;
//                while (!terminado) {
//                    if (iterador * 2 > ultimo) {
//                        if (heap[iterador * 2].prioridad > heap[iterador].prioridad) {
//                            minimo = iterador * 2;
//                        }
//                        if ((heap[iterador * 2 + 1].prioridad > heap[iterador].prioridad)) {
//                            minimo = iterador * 2 + 1;
//                        }
//                        if (iterador != minimo) {
//                            padre = heap[iterador];
//                            heap[iterador] = heap[minimo];
//                            heap[minimo] = padre;
//                            iterador = minimo;
//                        } else {
//                            terminado = true;
//                        }
//                    } else {
//                        terminado = true;
//                    }
//                }
//            }
//            encontrado = true;
//        }
//        auxiliar++;
//    }
//}

#endif /* COLADEPRIORIDAD_H */