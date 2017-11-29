/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   MatrizDeAdy.cpp
 * Author: Javier
 * 
 * Created on 5 de noviembre de 2017, 11:17 p.m.
 */

#include "MatrizDeAdy.h"

MatrizDeAdy::MatrizDeAdy() {
    for (int i = 0; i < 10; i++) { //inicializar todos los pesos en -1
        for (int j = 0; j < 10; j++) {
            matrizAdyacencia[i][j] = -1;
        }
    }
    numVertice = 0;
}

//MatrizDeAdy::MatrizDeAdy(const MatrizDeAdy& orig) {
//}

MatrizDeAdy::~MatrizDeAdy() {
}

void MatrizDeAdy::vaciar(){
    ultimo = -1;
    for (int i = 0; i < 100; i++) { //reestablece el valor default de los pesos
        for (int j = 0; j < 100; j++) {
            matrizAdyacencia[i][j] = -1;
        }
    }
}

bool MatrizDeAdy::vacio(){
    return (numVertice == 0);
}

vertice MatrizDeAdy::agregarVertice(string etiq){
    ultimo++;
    vertices[ultimo].etiqueta = etiq;
    numVertice++;
    return &vertices[ultimo];
}

void MatrizDeAdy::eliminarVertice(vertice v){
    int contador = 0;
    while(contador < numVertice){
        if(vertices[contador].etiqueta == v->etiqueta){
            while(contador < (numVertice-1)){
                vertices[contador] = vertices[contador+1];
                contador++; 
            }
        }
        contador++;
    }
    numVertice--;
}

void MatrizDeAdy::modificarEtiqueta(vertice v, string etiq){
    v->etiqueta =  etiq;
}

string MatrizDeAdy::Etiqueta(vertice v){
    return v->etiqueta;
}

void MatrizDeAdy::agregarArista(vertice v1, vertice v2, int peso){
    int i = 0;
    bool iguales = false;
    while (!iguales) {
        if (vertices[i].etiqueta == v1->etiqueta) {
            iguales = true;
        } else {
            i++;
        }
    }
    iguales = false;
    int j = 0;
    while (!iguales) {
        if(vertices[j].etiqueta == v2->etiqueta) {
            iguales = true;
        } else {
            j++;
        }
    }
    matrizAdyacencia[i][j] = peso;
    matrizAdyacencia[j][i] = peso;

    vertices[i].numAdy++;
    vertices[j].numAdy++;
}

void MatrizDeAdy::eliminarArista(vertice v1, vertice v2){
    int i = 0;
    bool iguales = false;
    while (!iguales) {
        if (vertices[i].etiqueta == v1->etiqueta) {
            iguales = true;
        } else {
            i++;
        }
    }
    iguales = false;
    int j = 0;
    while (!iguales) {
        if (vertices[j].etiqueta == v2->etiqueta) {
            iguales = true;
        } else {
            j++;
        }
    }
    matrizAdyacencia[i][j] = -1;
    matrizAdyacencia[j][i] = -1;
}

void MatrizDeAdy::modificarPeso(vertice v1, vertice v2, int pesoN){
    int i = 0;
    bool iguales = false;
    while (!iguales) {
        if (vertices[i].etiqueta == v1->etiqueta) {
            iguales = true;
        } else {
            i++;
        }
    }
    iguales = false;
    int j = 0;
    while (!iguales) {
        if (vertices[j].etiqueta == v2->etiqueta) {
            iguales = true;
        } else {
            j++;
        }
    }
    matrizAdyacencia[i][j] = pesoN;
    matrizAdyacencia[j][i] = pesoN;
}

int MatrizDeAdy::Peso(vertice v1, vertice v2){
    int i = 0;
    bool iguales = false;
    while (!iguales) {
        if (vertices[i].etiqueta == v1->etiqueta) {
            iguales = true;
        } else {
            i++;
        }
    }
    iguales = false;
    int j = 0;
    while (!iguales) {
        if (vertices[j].etiqueta == v2->etiqueta) {
            iguales = true;
        } else {
            j++;
        }
    }
    return matrizAdyacencia[i][j];
}

bool MatrizDeAdy::adyacentes(vertice v1, vertice v2){
    int i = 0;
    bool iguales = false;
    while (!iguales) {
        if (vertices[i].etiqueta == v1->etiqueta) {
            iguales = true;
        } else {
            i++;
        }
    }
    iguales = false;
    int j = 0;
    while (!iguales) {
        if (vertices[j].etiqueta == v2->etiqueta) {
            iguales = true;
        } else {
            j++;
        }
    }
    if(matrizAdyacencia[i][j] != -1){
        return true;
    }
    else
        return false;
}

vertice MatrizDeAdy::primerVertice(){
    if(ultimo != -1)
        return &vertices[0];
    else
        return nullptr;
}

vertice MatrizDeAdy::sigVertice(vertice v){
    bool encontrado = false;
    int contador = 0;
    while (!encontrado) {
        if (vertices[contador].etiqueta == v->etiqueta) {
            encontrado = true;
        } else {
            contador++;
        }
    }
    if(!((contador+1) == ultimo))
        return &vertices[contador+1];
    else
        return nullptr;
}

vertice MatrizDeAdy::primerVerticeAdy(vertice v){
    int i = 0;
    bool iguales = false;
    while (!iguales) {
        if (vertices[i].etiqueta == v->etiqueta) {
            iguales = true;
        } else {
            i++;
        }
    }
    int j = 0;
    while(matrizAdyacencia[i][j] != -1){
        j++;
    }
    if(j <= ultimo)
        return &vertices[j];
    else 
        return nullptr;
}

vertice MatrizDeAdy::sigVerticeAdy(vertice v, vertice vAdy){
    int i = 0;
    bool iguales = false;
    while (!iguales) {
        if (vertices[i].etiqueta == v->etiqueta) {
            iguales = true;
        } else {
            i++;
        }
    }
    iguales = false;
    int j = 0;
    while (!iguales) {
        if (vertices[j].etiqueta == vAdy->etiqueta) {
            iguales = true;
        } else {
            j++;
        }
    }
    j++;
    while(matrizAdyacencia[i][j] != -1){
        j++;
    }
    if(j<= ultimo)
        return &vertices[j];
    else
        return nullptr;

}

int MatrizDeAdy::numVertices(){
    return numVertice;
}

int MatrizDeAdy::numVerticesAdy(vertice v){
    return v->numAdy;
}

