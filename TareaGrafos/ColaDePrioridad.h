
/* 
 * File:   ColaDePrioridad.h
 * Author: Luis
 *
 * Created on November 22, 2017, 7:35 PM
 */

#ifndef COLADEPRIORIDAD_H
#define COLADEPRIORIDAD_H
#define SIZE 100
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
    
    void iniciar();
    
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

        Caja() {
        };
    };
    Caja<A> arreglo[SIZE];
    int ultimo;
    int contador;
};

template <typename A>
ColaDePrioridad<A>::ColaDePrioridad() {
    ultimo = 0;
    contador = 0;
}

template <typename A>
void ColaDePrioridad<A>::iniciar(){
    ultimo = 0;
    contador = 0;
}

template <typename A>
ColaDePrioridad<A>::~ColaDePrioridad() {

}

template <typename A>
void ColaDePrioridad<A>::vaciar() {
    ultimo = 0;
    contador = 0;
}

template <typename A>
bool ColaDePrioridad<A>::vacia() {
    return (ultimo == 0);
}

template <typename A>
void ColaDePrioridad<A>::agregar(A elemento, int prioridad) {
    Caja<A>* nuevo = new Caja<A>(elemento, prioridad);
    Caja<A> padre;
    ultimo++;
    contador++;
    arreglo[ultimo] = *nuevo;
    //cout<<arreglo[ultimo].elemento<<"\n";
    int agregado = ultimo;
    while ((agregado > 0) && (agregado/2>0)&&(arreglo[agregado].prioridad < arreglo[agregado / 2].prioridad)) {
        padre = arreglo[agregado / 2];
        arreglo[agregado / 2] = arreglo[agregado];
        arreglo[agregado] = padre;
        //cout<<arreglo[agregado].elemento;
        agregado = agregado / 2;
    }
}

template <typename A>
A ColaDePrioridad<A>::sacar() {
    A auxiliar = arreglo[1].elemento;
//    cout<<arreglo[1].elemento<<"\n";

    Caja<A> padre;
    bool terminado = false;
    int iterador = 1;
    int minimo = 0;
    if (contador > 1) {
        arreglo[1] = arreglo[ultimo];
        ultimo--;
        contador--;
        while (!terminado) {
            if (iterador * 2 <= ultimo) {
                minimo = iterador * 2;
                if ((iterador * 2 + 1 <= ultimo)&&(arreglo[iterador * 2 + 1].prioridad < arreglo[iterador * 2].prioridad)) {
                    minimo = iterador * 2 + 1;
                }
                if (arreglo[minimo].prioridad < arreglo[iterador].prioridad) {
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
    } else {
        ultimo--;
        contador--;
    }
    //cout<<auxiliar<<"\n";
    return auxiliar;
}

template <typename A>
int ColaDePrioridad<A>::numElem() {
    return contador;
}
//};
#endif /* COLADEPRIORIDAD_H */

