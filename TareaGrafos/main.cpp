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
#include "AlgoritmosGrafos.h"
//#include "MatrizDeAdy.h"
#include "ListaDeAdy.h"
#include "Diccionario.h"
#include "ColaDePrioridad.h"
#include "ConjuntoDeConj.h"
#include "AlgoritmosGrafos.h"
#include <string>
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    grafo g = new grafo;
    vertice v;
    string etiqueta;
    AlgoritmosGrafos* algoritmos = new AlgoritmosGrafos();
    int caso = 0;
    cout << "Saludos, ¿que desea utilizar?" << "\n";
    cout << "Presione la tecla 1 para operadores basicos." << "\n";
    cout << "Presione la tecla 2 para algoritmos." << "\n";
    cout << "Presione la tecla 3 para salir." << "\n";
    bool salir = false;
    while (!salir) {
        cin >> caso;
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
                cout << "Presione 7 para Vendedor()"<< "\n";
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
                    g.vaciar();
                    break;
                case 2:
                    if(g.vacio())
                        cout << "El grafo esta vacio" << "\n";
                    else
                        cout << "El grafo no esta vacio"<< "\n";
                    break;
                case 3:
                    cout << "Escriba la etiqueta del vertice: ";
                    cin >> etiqueta;
                    g.agregarVertice(etiqueta);
                    break;
                case 4:
                    cout << "Escriba la etiqueta del vertice: ";
                    cin >> etiqueta;
                    v = algoritmos->buscarEtiq(etiqueta,g);
                    g.eliminarVertice(v);
                    break;
                case 5:
                    cout << "Escriba la etiqueta del vertice: ";
                    cin >> etiqueta;
                    v = algoritmos->buscarEtiq(etiqueta,g);
                    cout << "Escriba la nueva etiqueta del vertice: ";
                    cin >> etiqueta;
                    g.modificarEtiqueta(v,etiqueta);
                    break;
                case 6:
                    cout << "Escriba la etiqueta del vertice: ";
                    cin >> etiqueta;
                    v = algoritmos->buscarEtiq(etiqueta,g);
                    cout << g.Etiqueta(v);
                    break;
            }
            cout << "Presione la tecla 1 para seguir con operadores basicos." << "\n";
            cout << "Presione la tecla 2 para usar algoritmos." << "\n";
            cout << "Presione la tecla 3 para salir." << "\n";
            cin >> caso;
        } else if (!salir && caso == 2) {
            switch (segundoCaso) {

            }
            cout << "Presione la tecla 1 para seguir con operadores basicos." << "\n";
            cout << "Presione la tecla 2 para usar algoritmos." << "\n";
            cout << "Presione la tecla 3 para salir." << "\n";
            cin >> caso;
        }
        if(caso == 3){
            salir = true;
            cout << "adios";
        }
    }
    return 0;
}

