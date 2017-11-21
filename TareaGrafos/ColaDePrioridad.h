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
struct Caja {
    T elemento;
    int prioridad;

    Caja(T e, int pri) {
        Caja.elemento = e;
        Caja.prioridad = pri;
    };
};

class ColaDePrioridad {
public:
    Caja heap [SIZE];
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
  REQ:
  MOD:
     */
    bool vacia();
    /*
  EFE: Agrega un elemento a la cola segun su prioridad
  REQ: Cola Inicializada
  MOD: Cola
     */
    void agregar(T elemento, int prioridad);
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

template <typename T> ColaDePrioridad<T>::ColaDePrioridad() {
    ultimo = 0;
    contador = 0;
}

template <class T> ColaDePrioridad<T>::~ColaDePrioridad() {

}

template <class T> void ColaDePrioridad<T>::vaciar() {
    ultimo = 0;
    contador = 0;
}

template <class T> bool ColaDePrioridad<T>::vacia() {
    return (ultimo == 0);
}

template <class T> void ColaDePrioridad<T>::agregar(T elemento, int prioridad) {
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

template <class T> Caja ColaDePrioridad<T>::sacar() {
    Caja auxiliar = heap[1];
    Caja padre = heap[1];
    bool terminado = false;
    int iterador = 1;
    int minimo = 0;
    heap[1] = heap[ultimo];
    ultimo--;
    contador--;
    while (!terminado) {
        if (iterador * 2 > ultimo) {
            if (heap[iterador * 2].prioridad > heap[ultimo].prioridad) {
                minimo = iterador * 2;
            } else if ((heap[iterador * 2 + 1].prioridad > heap[minimo].prioridad)) {
                minimo = iterador * 2 + 1;
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
    return auxiliar;
}

template <class T> void ColaDePrioridad<T>::modificarPrioridad(T elemento, int nuevaPrioridad) {
    int auxiliar = 0;
    bool encontrado = false;
    while ((auxiliar <= ultimo)&& !encontrado) {
        if (heap[auxiliar].elemento == elemento) {
            if (heap[auxiliar].prioridad < nuevaPrioridad) {
                heap[auxiliar].prioridad = nuevaPrioridad;
                ordenarEntrada(auxiliar);
            } else {
                heap[auxiliar].prioridad = nuevaPrioridad;
                ordenarSalida(auxiliar);
            }

            encontrado = true;
        }
        auxiliar++;
    }
}

template <class T> int ColaDePrioridad<T>::numElem() {
    return contador;
}

template <class T> void ColaDePrioridad<T>::borrar(T elemento) {
    int auxiliar = 0;
    bool encontrado = false;
    //Caja caja = new Caja(elemento,0);
    while ((auxiliar <= ultimo)&& !encontrado) {
        if (heap[auxiliar].elemento == elemento) {
            if (heap[auxiliar].elemento == heap[ultimo].elemento) {
                ultimo--;
                contador--;
            } else {
                //caja = heap[auxiliar];
                heap[auxiliar] = heap[ultimo];
                //heap[ultimo]=caja;
                ultimo--;
                contador--;
                ordenarSalida(auxiliar);
            }
            encontrado = true;
        }
        auxiliar++;
    }
}

template <class T> void ColaDePrioridad<T>::ordenarEntrada(int posHijo) {
    int hijo = posHijo;
    int padre = padre(hijo);
    while (heap[hijo].prioridad > heap[padre].prioridad && hijo >= 0 && padre >= 0) {
        //Cambiar hijo y padre por orden de prioridad
        Caja auxiliar;
        auxiliar = heap[hijo];
        heap[hijo] = heap[padre];
        heap[padre] = auxiliar;
        //
        hijo = padre;
        padre = padre(hijo);
    }
}

template <class T> void ColaDePrioridad<T>::ordenarSalida(int posPadre) {
    int padre = posPadre;
    bool terminado = false;
    while (!terminado) {
        int hijoDerecho = hijoDerecho(padre);
        int hijoIzquierdo = hijoIzquierdo(padre);
        int auxiliar = padre;

        if (hijoIzquierdo < contador && heap[hijoIzquierdo].prioridad > heap[auxiliar].prioridad) {
            auxiliar = hijoIzquierdo;
        }
        if (hijoDerecho < contador && heap[hijoDerecho].prioridad > heap[auxiliar].prioridad) {
            auxiliar = hijoDerecho;
        }
        if (auxiliar != padre) {
            //
            Caja caja;
            caja = heap[padre];
            heap[padre] = heap[auxiliar];
            heap[auxiliar] = caja;
            //
            padre = auxiliar;
        } else {
            terminado = true;
        }
    }
}

template <class T> int ColaDePrioridad<T>::padre(int hijo) {
    if (hijo % 2 == 0) {
        return (hijo / 2) - 1;
    } else {
        return hijo / 2;
    }
}

template <class T> int ColaDePrioridad<T>::hijoDerecho(int padre) {
    return padre * 2 + 2;
}

template <class T> int ColaDePrioridad<T>::hijoIzquierdo(int padre) {
    return padre * 2 + 1;
}
#endif /* COLADEPRIORIDAD_H */

