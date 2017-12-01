/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Javier
 *
 * Created on 5 de noviembre de 2017, 11:11 p.m.
 */

#include <iostream>
//#define SIZE 10
#include "MatrizDeAdy.h"
//#include "ListaDeAdy.h"
#include "Diccionario.h"
#include "ColaDePrioridad.h"
#include "ConjuntoDeConj.h"
#include <string>
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    grafo g;
    int caso = 0;
    cout << "Saludos, ¿que desea utilizar?" << "\n";
    cout << "Presione la tecla 1 para operadores basicos." << "\n";
    cout << "Presione la tecla 2 para algoritmos." << "\n";
    cin >> caso;
    bool salir = false;
    while(!salir){
        switch(caso){
            case 1: 
                caso = 0;
                cout << "Presione 1 para iniciar()" << "\n";
                cout << "Presione 2 para destruir()" << "\n";
                cout << "Presione 3 para vaciar()"  << "\n";
                cout << "Presione 4 para vacio()" << "\n";
                cout << "Presione 5 para agregarVertice()" << "\n";
                cout << "Presione 6 para eliminarVertice()" << "\n";
                cout << "Presione 7 para modifiarEtiqueta()" << "\n";
                cout << "Presione 8 para Etiqueta()"  << "\n";
                cout << "Presione 9 para agregarArista()"  << "\n";
                cout << "Presione 10 para eliminarArista()" << "\n";
                cout << "Presione 11 para modificarPeso()" << "\n";
                cout << "Presione 12 para peso()" << "\n";
                cout << "Presione 13 para adyacentes()" << "\n";
                cout << "Presione 14 para primerVertice()" << "\n";
                cout << "Presione 15 para siguienteVertice()" << "\n";
                cout << "Presione 16 para primerVerticeAdy()" << "\n";
                cout << "Presione 17 para sigVerticeAdy()" << "\n";
                cout << "Presione 18 para numVertices()" << "\n";
                cout << "Presione 19 para numVerticesAdy()" << "\n";
                        
                break;
                
            case 2:
                //placeholder
                break;
        }
    }
    
    
    
    
    
    
//    Diccionario<string>* dicc = new Diccionario<string>;
//    dicc->agregar("Hola");
//    dicc->agregar("Soy");
//    dicc->agregar("Una");
//    dicc->agregar("Oveja");
//    dicc->agregar("Ovejas");
//    dicc->agregar("Muchas");
//    dicc->agregar("Sence");
//    dicc->agregar("No");
//    dicc->agregar("Make");
//    cout << dicc->listar();
//    /*
//     ColaDePrioridad<string>* cola = new ColaDePrioridad<string>;
//
//    cola->agregar("j", 9);
//    cola->agregar("g", 8);
//    cola->agregar("a", 1);
//    cola->agregar("s", 5);
//    cola->agregar("t", 2);
//    cola->agregar("i", 3);
//    cola->agregar("y", 4);
//    cola->agregar("r", 6);
//    cola->agregar("f", 7);
//    cola->agregar("e", 10);
//        int num = cola->numElem();
//        for (int i = 0; i < num; i++) {
//            cout << "Elemento: " << i + 1 << cola->sacar() << "\n";
//        }
//
//     */
//
//    ConjuntoDeConj<int>* prueba = new ConjuntoDeConj<int>;
//
//    prueba->agregarConjunto("c", 5);
//    prueba->agregarConjunto("d", 6);
//    prueba->agregarConjunto("e", 7);
//    prueba->agregarConjunto("k", 17);
//    prueba->agregarConjunto("j", 71);
//    prueba->agregarConjunto("i", 73);
//    prueba->agregarConjunto("h", 27);
//    prueba->agregarConjunto("g", 24);
//    prueba->agregarConjunto("f", 74);
//    prueba->agregarConjunto("b", 75);
//    prueba->agregarConjunto("a", 78);
//
//    string pert = prueba->conjuntoAlQuePertenece(6);
//    prueba->unirConjuntos("c", "e");
//    prueba->unirConjuntos("d", "c");
//    prueba->unirConjuntos("d", "k");
//    prueba->unirConjuntos("d", "f");
//    prueba->unirConjuntos("d", "b");
//    prueba->unirConjuntos("d", "a");
//
//
//    int jj = 0;
//    //    ColaDePrioridad<string>* cola = new ColaDePrioridad<string>;
//    //
//    //    cola->agregar("a", 1);
//    //    cola->agregar("s", 2);
//    //
//    //    cola->agregar("Sandra", 7);
//    //    int num = 2/*cola->numElem()*/;
//    //    for (int i = 0; i < num; i++) {
//    //        cout << "Elemento: " << i << cola->sacar() << "\n";
//    //    }
//
//    grafo *g = new grafo;
//
//
//    vertice v1 = g->agregarVertice("abc");
//    cout << "etiqueta: " << v1->etiqueta << "\n";
//
//    vertice v2 = g->agregarVertice("katherine fea");
//    cout << "etiqueta2: " << v2->etiqueta << "\n";
//    g->agregarArista(v1, v2, 10);
//    bool esAdy = g->adyacentes(v1, v2);
//    cout << "peso: " << g->Peso(v1, v2) << "\n";
//    v2 = g->agregarVertice("k fea");
//    g->agregarArista(v1, v2, 14);
//    esAdy = g->adyacentes(v1, v2);
//    cout << v2->etiqueta << "\n" << esAdy << "\n";
//    cout << "peso: " << g->Peso(v1, v2) << "\n";
//    v2 = g->agregarVertice("ka fea");
//    g->agregarArista(v1, v2, 6);
//    esAdy = g->adyacentes(v1, v2);
//    cout << "peso: " << g->Peso(v1, v2) << "\n";
//    g->modificarPeso(v1, v2, 22);
//
//    cout << "peso nuevo: " << g->Peso(v1, v2) << "\n";
//    cout << "peso nuevo: " << g->Peso(v2, v1) << "\n";
//    cout << v1->etiqueta << "\n" << esAdy << "\n";
//    cout << v2->etiqueta << "\n";
//    cout << g->numVertices() << "\n";
//    cout << g->numVerticesAdy(v1) << "\n";
//
//
//    v2 = g->primerVerticeAdy(v1);
//    cout << g->Etiqueta(v2) << "\n";
//    v2 = g->sigVerticeAdy(v1, v2);
//    cout << g->Etiqueta(v2) << "\n";
//    v2 = g->sigVerticeAdy(v1, v2);
//    cout << g->Etiqueta(v2) << "\n";
//
//
//    g->vaciar();
//    bool vacio = g->vacio();
//

    return 0;

}

