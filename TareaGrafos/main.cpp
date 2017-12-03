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
//#include "AlgoritmosGrafos.h"
#include "MatrizDeAdy.h"
//#include "ListaDeAdy.h"
#include "Diccionario.h"
#include "ColaDePrioridad.h"
#include "ConjuntoDeConj.h"
#include "AlgoritmosGrafos.h"
#include <string>
#include <ctime>
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    srand(10042017);
    
//    grafo* g= new grafo;
//    AlgoritmosGrafos AG;
//    vertice vj;
////    for (int i = 0; i <= 50; ++i) {
////        vj = g->agregarVertice(to_string(i));
////        if (i > 0 && i < 50) {
////            g->agregarArista(g->primerVertice(), g->sigVertice(vj), 3);
////        }
////    }
//    vertice v1;
//    vertice v2;
//    int n=6;
//    int p;
//    for (int i = 0; i < n; ++i){
//        g->agregarVertice(to_string(i));
//    }
//
//    for (int i = 0; i < n; ++i){
//         
//        v1 = AG.buscarEtiq(to_string(i),*g);
//        for (int j = 0; j < n/3; ++j)
//        {  
//            p = (rand()%20) + 1;
//            v2 = AG.buscarEtiq(to_string(rand()%(n-1)), *g);
//            while ((g->adyacentes(v1, v2)) || (v1 == v2))
//            {   
//                v2 = AG.buscarEtiq(to_string(rand()%n), *g);
//            }
//            g->agregarArista(v1,v2, p);
//        }
//    }
//    
//    grafo gCopia= AG.Copiar(*g);
//    bool igual= AG.Iguales(*g, gCopia);
//    
//    AG.Kruskal(gCopia);
//    
//    AG.Prim(gCopia);
//    
//    AG.Floyd(*g);
   // AG.vendedor(gCopia);
   // AG.Dijkstra(gCopia.primerVertice(), gCopia);


    grafo* g = new grafo;
    vertice v, vAdy;
    string etiqueta;
    int peso;

    AlgoritmosGrafos* algoritmos = new AlgoritmosGrafos();
    int caso = 0;
    cout << "Saludos, ¿que desea utilizar? Por favor no escribir una letra si se solicita un numero." << "\n";
    cout << "Presione la tecla 1 para operadores basicos." << "\n";
    cout << "Presione la tecla 2 para algoritmos." << "\n";
    cout << "Presione la tecla 3 para salir." << "\n";
    bool salir = false;
    cin >> caso;
    while (!salir) {
        
        int segundoCaso = 0;
        switch (caso) {
            case 1:
                cout << "Presione 1 para vaciar()" << "\n";
                cout << "Presione 2 para vacio()" << "\n";
                cout << "Presione 3 para agregarVertice()" << "\n";
                cout << "Presione 4 para eliminarVertice()" << "\n";
                cout << "Presione 5 para modifiarEtiqueta()" << "\n";
                cout << "Presione 6 para Etiqueta()" << "\n";
                cout << "Presione 7 para agregarArista()" << "\n";
                cout << "Presione 8 para eliminarArista()" << "\n";
                cout << "Presione 9 para modificarPeso()" << "\n";
                cout << "Presione 10 para peso()" << "\n";
                cout << "Presione 11 para adyacentes()" << "\n";
                cout << "Presione 12 para primerVertice()" << "\n";
                cout << "Presione 13 para siguienteVertice()" << "\n";
                cout << "Presione 14 para primerVerticeAdy()" << "\n";
                cout << "Presione 15 para sigVerticeAdy()" << "\n";
                cout << "Presione 16 para numVertices()" << "\n";
                cout << "Presione 17 para numVerticesAdy()" << "\n";
                cin >> segundoCaso;
                break;

            case 2:
                cout << "Presione 1 para Dijkstra()" << "\n";
                cout << "Presione 2 para Floyd()" << "\n";
                cout << "Presione 3 para Prim()" << "\n";
                cout << "Presione 4 para Kruskal()" << "\n";
                cout << "Presione 5 para Copiar()" << "\n";
                cout << "Presione 6 para Iguales()" << "\n";

                cout << "Presione 7 para Vendedor()" << "\n";
                cin >> segundoCaso;
                break;
            case 3:
                cout << "Adios" << "\n";
                salir = true;
                break;

        }
       
        if (!salir && caso == 1) {
            switch (segundoCaso) {
                case 1:
                    g->vaciar();
                    break;
                case 2:
                    if (g->vacio())
                        cout << "El grafo esta vacio" << "\n";
                    else
                        cout << "El grafo no esta vacio" << "\n";
                    break;
                case 3:
                    cout << "Escriba la etiqueta del vertice: ";
                    cin >> etiqueta;
                    g->agregarVertice(etiqueta);
                    break;
                case 4:
                    cout << "Escriba la etiqueta del vertice: ";
                    cin >> etiqueta;
                    v = algoritmos->buscarEtiq(etiqueta, *g);
                    g->eliminarVertice(v);
                    break;
                case 5:
                    cout << "Escriba la etiqueta del vertice: ";
                    cin >> etiqueta;
                    v = algoritmos->buscarEtiq(etiqueta, *g);
                    cout << "Escriba la nueva etiqueta del vertice: ";
                    cin >> etiqueta;
                    g->modificarEtiqueta(v, etiqueta);
                    break;
                case 6:
                    cout << "Escriba la etiqueta del vertice: ";
                    cin >> etiqueta;
                    v = algoritmos->buscarEtiq(etiqueta, *g);
                    cout << g->Etiqueta(v);
                    break;
                case 7:
                    cout << "Escriba la etiqueta del vertice: ";
                    cin >> etiqueta;
                    v = algoritmos->buscarEtiq(etiqueta, *g);
                    cout << "Escriba la etiqueta del vertice para crear adyacencia: ";
                    cin >> etiqueta;
                    vAdy = algoritmos->buscarEtiq(etiqueta, *g);
                    cout << "Escriba el peso de la arista: ";
                    cin >> peso;
                    g->agregarArista(v, vAdy, peso);
                    break;
                case 8:
                    cout << "Escriba la etiqueta del vertice: ";
                    cin >> etiqueta;
                    v = algoritmos->buscarEtiq(etiqueta, *g);
                    cout << "Escriba la etiqueta del vertice para crear adyacencia: ";
                    cin >> etiqueta;
                    vAdy = algoritmos->buscarEtiq(etiqueta, *g);
                    g->eliminarArista(v, vAdy);
                    break;
                case 9:
                    cout << "Escriba la etiqueta del vertice: ";
                    cin >> etiqueta;
                    v = algoritmos->buscarEtiq(etiqueta, *g);
                    cout << "Escriba la etiqueta del vertice adyacente: ";
                    cin >> etiqueta;
                    vAdy = algoritmos->buscarEtiq(etiqueta, *g);
                    cout << "Escriba el nuevo peso de la arista: ";
                    cin >> peso;
                    g->agregarArista(v, vAdy, peso);
                    break;
                case 10:
                    cout << "Escriba la etiqueta del vertice: ";
                    cin >> etiqueta;
                    v = algoritmos->buscarEtiq(etiqueta, *g);
                    cout << "Escriba la etiqueta del vertice adyacente: ";
                    cin >> etiqueta;
                    vAdy = algoritmos->buscarEtiq(etiqueta, *g);
                    cout << "\n" << g->Peso(v, vAdy);
                    break;
                case 11:
                    cout << "Escriba la etiqueta del vertice: ";
                    cin >> etiqueta;
                    v = algoritmos->buscarEtiq(etiqueta, *g);
                    cout << "Escriba la etiqueta del vertice adyacente: ";
                    cin >> etiqueta;
                    vAdy = algoritmos->buscarEtiq(etiqueta, *g);
                    if (g->adyacentes(v, vAdy))
                        cout << "Existe adyacencia entre ambos vertices";
                    else
                        cout << "No existe adyacencia entre ambos vertices";
                    break;
                case 12:
                    if (g->primerVertice() != nullptr)
                        cout << "El primer vertice del grafo es: " << g->Etiqueta(g->primerVertice());
                    else
                        cout << "El grafo no tiene vertices";
                    break;
                case 13:
                    cout << "Escriba la etiqueta del vertice: ";
                    cin >> etiqueta;
                    v = algoritmos->buscarEtiq(etiqueta, *g);
                    if (v != nullptr)
                        cout << "El Siguiente vertice de " << etiqueta << " Es: " << g->Etiqueta(g->sigVertice(v));
                    else
                        cout << "El vertice " << etiqueta << " no tiene vertice adyacente";
                    break;
                case 14:
                    cout << "Escriba la etiqueta del vertice: ";
                    cin >> etiqueta;
                    v = algoritmos->buscarEtiq(etiqueta, *g);
                    vAdy = g->primerVerticeAdy(v);
                    if (vAdy != nullptr)
                        cout << "El primer vertice Adyacente de " << etiqueta << " Es: " << g->Etiqueta(v);
                    else
                        cout << "El vertice no tiene adyacencias";
                    break;
                case 15:
                    cout << "Escriba la etiqueta del vertice: ";
                    cin >> etiqueta;
                    v = algoritmos->buscarEtiq(etiqueta, *g);
                    cout << "Escriba la etiqueta del vertice adyacente: ";
                    cin >> etiqueta;
                    vAdy = algoritmos->buscarEtiq(etiqueta, *g);
                    if (g->sigVerticeAdy(v, vAdy) != nullptr)
                        cout << "El siguiente vertice adyacente de " << g->Etiqueta(v) << " y " << g->Etiqueta(vAdy) << "Es " <<g->Etiqueta(g->sigVerticeAdy(v, vAdy));
                    else
                        cout << "no hay siguiente adyacente entre " << g->Etiqueta(v) << " y " << g->Etiqueta(vAdy);
                    break;
                case 16:
                    cout << "El grafo tiene " << g->numVertices() << " vertices";
                    break;
                case 17:
                    cout << "Escriba la etiqueta del vertice: ";
                    cin >> etiqueta;
                    v = algoritmos->buscarEtiq(etiqueta, *g);
                    cout << "\n" << "El vertice " << etiqueta << " Tiene " << g->numVerticesAdy(v) << " adyacencias";
                    break;
            }
            cout << "\n";
            cout << "Presione la tecla 1 para seguir con operadores basicos." << "\n";
            cout << "Presione la tecla 2 para usar algoritmos." << "\n";
            cout << "Presione la tecla 3 para salir." << "\n";
            cin >> caso;
        } else if (!salir && caso == 2) {
            switch (segundoCaso) {
                case 1:
                    cout << "Escriba la etiqueta del vertice a utilizar: " << "\n";
                    cin >> etiqueta;
                    v = algoritmos->buscarEtiq(etiqueta, *g);
                    algoritmos->Dijkstra(v, *g);
                    break;
                case 2:
                    algoritmos->Floyd(*g);
                    break;
                case 3:
                    algoritmos->Kruskal(*g);
                    break;
                case 4:
                    algoritmos->Prim(*g);
                    break;
                case 5:
                    algoritmos->vendedor(*g);
                    break;
                case 6:
                    break;
            }
            cout << "Presione la tecla 1 para seguir con operadores basicos." << "\n";
            cout << "Presione la tecla 2 para usar algoritmos." << "\n";
            cout << "Presione la tecla 3 para salir." << "\n";
            cin >> caso;
        }
        if (caso == 3) {
            salir = true;
            cout << "adios";     
        }

    }
    return 0;
}