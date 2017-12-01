/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   AlgoritmosGrafos.cpp
 * Author: Javier
 * 
 * Created on 5 de noviembre de 2017, 11:35 p.m.
 */

#include "AlgoritmosGrafos.h"
using namespace std;
//Se utilizan en Dijkstra
map <string, int> Distancia; //También se utiliza en Coloreo de Grafo
map <string, string> Caminos;
map<string, int>::iterator it;
map<string, string>::iterator itCaminos;
grafo grf;

AlgoritmosGrafos::AlgoritmosGrafos() {
}

AlgoritmosGrafos::AlgoritmosGrafos(const AlgoritmosGrafos& orig) {
}

AlgoritmosGrafos::~AlgoritmosGrafos() {
}


void AlgoritmosGrafos::Dijkstra(vertice v) {
    Distancia.clear();
    Caminos.clear();
    Diccionario <vertice> VerticesRevisados;
    vertice actual = grf.primerVertice();
    vertice pivote;
    vertice AdyacentePivote;
    int menor;
    int n = grf.numVertices();
    while (actual != nullptr) {
        if (grf.adyacentes(v, actual)) {
            Distancia.insert(make_pair(grf.Etiqueta(actual), grf.Peso(v, actual)));
            Caminos.insert(make_pair(grf.Etiqueta(actual), grf.Etiqueta(v) + "-> " + grf.Etiqueta(actual)));
        } else if (v == actual) {
            Distancia.insert(make_pair(grf.Etiqueta(actual), 0));
            Caminos.insert(make_pair(grf.Etiqueta(actual), ""));
        } else {
            Distancia.insert(make_pair(grf.Etiqueta(actual), -1));
            Caminos.insert(make_pair(grf.Etiqueta(actual), ""));
        }
        actual = grf.sigVertice(actual);
    }
    VerticesRevisados.agregar(v);
    while (n != VerticesRevisados.numElem()) {
        menor = -1;
        for (it = Distancia.begin(); it != Distancia.end(); ++it) //Busca el menor camino que no esté listo.
        {
            if ((it ->second < menor && it ->second >= 0) || menor < 0) {
                //Buscar Vertice en Grafo
                vertice resultado = nullptr;
                vertice actual = grf.primerVertice();
                while (actual != nullptr && resultado == nullptr) {
                    if (grf.Etiqueta(actual) == it->first) {
                        resultado = actual;
                    }
                    actual = grf.sigVertice(actual);
                }
                //
                if (!VerticesRevisados.pertenece(actual)) {
                    menor = it ->second;
                    //Buscar Vertice en Grafo
                    resultado = nullptr;
                    actual = grf.primerVertice();
                    while (actual != nullptr && resultado == nullptr) {
                        if (grf.Etiqueta(actual) == it->first) {
                            resultado = actual;
                        }
                        actual = grf.sigVertice(actual);
                    }
                    //

                    pivote = actual;
                }
            }
        }
        VerticesRevisados.agregar(pivote);
        AdyacentePivote = grf.primerVerticeAdy(pivote);
        while (AdyacentePivote != nullptr) {
            it = Distancia.find(grf.Etiqueta(AdyacentePivote));
            if (!VerticesRevisados.pertenece(AdyacentePivote) && (it ->second > (Distancia.find(grf.Etiqueta(pivote))-> second) + grf.Peso(pivote, AdyacentePivote) || it ->second < 0)) {
                it ->second = Distancia.find(grf.Etiqueta(pivote))-> second + grf.Peso(pivote, AdyacentePivote);
                itCaminos = Caminos.find(grf.Etiqueta(AdyacentePivote));
                itCaminos ->second = Caminos.find(grf.Etiqueta(pivote))-> second + "-> " + grf.Etiqueta(AdyacentePivote);
            }
            AdyacentePivote = grf.sigVerticeAdy(pivote, AdyacentePivote);
        }
    }
    for (itCaminos = Caminos.begin(); itCaminos != Caminos.end(); ++itCaminos) {
        cout << "El camino mas corto de " << grf.Etiqueta(v) << " a " << itCaminos ->first << ": " << itCaminos ->second;
        cout << ". Su costo es de: " << Distancia.find(itCaminos->first)->second << endl;
    }
}

void AlgoritmosGrafos::Floyd() {

}

void AlgoritmosGrafos::Prim() {

}

void AlgoritmosGrafos::Kruskal() {

}

grafo AlgoritmosGrafos::Copiar() {

}

bool AlgoritmosGrafos::Iguales() {

}

