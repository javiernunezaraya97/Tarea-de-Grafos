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
    grafo g;
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
                cout << "Presione 1 para iniciar()" << "\n";
                cout << "Presione 2 para destruir()" << "\n";
                cout << "Presione 3 para vaciar()" << "\n";
                cout << "Presione 4 para vacio()" << "\n";
                cout << "Presione 5 para agregarVertice()" << "\n";
                cout << "Presione 6 para eliminarVertice()" << "\n";
                cout << "Presione 7 para modifiarEtiqueta()" << "\n";
                cout << "Presione 8 para Etiqueta()" << "\n";
                cout << "Presione 9 para agregarArista()" << "\n";
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
                cin >> segundoCaso;
                break;

            case 2:
                cout << "Presione 1 para Dijkstra()" << "\n";
                cout << "Presione 2 para Floyd()" << "\n";
                cout << "Presione 3 para Prim()" << "\n";
                cout << "Presione 4 para Kruskal()" << "\n";
                cout << "Presione 5 para Copiar()" << "\n";
                cout << "presione 6 para Iguales()" << "\n";
                cin >> segundoCaso;
                break;
            case 3:
                cout << "Adios" << "\n";
                salir = true;
                break;

        }
        if (!salir && caso == 1) {
            switch (segundoCaso) {

            }

            cout << "Saludos, ¿que desea utilizar?" << "\n";
            cout << "Presione la tecla 1 para operadores basicos." << "\n";
            cout << "Presione la tecla 2 para algoritmos." << "\n";
            cout << "Presione la tecla 3 para salir." << "\n";
            cin >> caso;
        } else if (!salir && caso == 2) {
            switch (segundoCaso) {

            }
            cout << "Saludos, ¿que desea utilizar?" << "\n";
            cout << "Presione la tecla 1 para operadores basicos." << "\n";
            cout << "Presione la tecla 2 para algoritmos." << "\n";
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

