/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ListaDeAdy.h
 * Author: Javier
 *
 * Created on 5 de noviembre de 2017, 11:19 p.m.
 */

#ifndef LISTADEADY_H
#define LISTADEADY_H
#include <string>

using namespace std;

struct Vertice;

struct Arista {
    int peso;
    Arista* sgtAdy;
    Vertice* ptrVert;

    Arista() : peso(-1), sgtAdy(nullptr), ptrVert(nullptr) {
    };

    Arista(int p) : peso(p), sgtAdy(nullptr), ptrVert(nullptr) {
    };

    Arista(int p, Vertice* v) : peso(p), sgtAdy(nullptr), ptrVert(v) {
    };

    Arista& operator=(const Arista& orig) {
        peso = orig.peso;
        sgtAdy = orig.sgtAdy;
        ptrVert = orig.ptrVert;
    };
};

struct Vertice {
    // faltan las aristas
    string etiqueta;
    Vertice* sgtVertice;
    Arista* adyacencia;
    int cantAdy;

    Vertice() : etiqueta(""), sgtVertice(nullptr), adyacencia(nullptr), cantAdy(0) {
    };

    Vertice(string etiq) : etiqueta(etiq), sgtVertice(nullptr), adyacencia(nullptr), cantAdy(0) {
    };

    Vertice& operator=(const Vertice& orig) {
        etiqueta = orig.etiqueta;
        sgtVertice = orig.sgtVertice;
        adyacencia = orig.adyacencia;
        cantAdy = orig.cantAdy;
    };
};
typedef Arista* arista;
typedef Vertice* vertice;

class ListaDeAdy {
public:
    int cantVert;
    vertice vertInicial;
    /**
     * Efecto: Crea un grafo vacio.
     * Requiere: Grafo sin inicializar.
     * Modifica: 
     */
    ListaDeAdy();
    //    ListaDeAdy(const ListaDeAdy& orig);
    /**
     * Efecto: Destruye el grafo.
     * Requiere: Grafo inicializado.
     * Modifica: 
     */
    virtual ~ListaDeAdy();
    /**
     * Vaciar
     * Efecto: Vacía el grafo.
     * Requiere: Grafo inicializado.
     * Modifica: 
     */
    void vaciar();
    /**
     * Vacia
     * @return bool
     * Efecto: Devuelve verdadero si el grafo está vacío, falso en caso contrario.
     * Requiere: Grafo inicializado.
     * Modifica: 
     */
    bool vacio();
    /**
     * AgregarVertice
     * @param string
     * Efecto: Agrega un nuevo vértice al grafo.
     * Requiere: Grafo inicializado.
     * Modifica: Grafo.
     */
    vertice agregarVertice(string etiq);
    /**
     * EliminarVertice
     * @param vertice
     * Efecto: Elimina un vertice de el grafo.
     * Requiere: Vertice válido y aislado.
     * Modifica: Grafo.
     */
    void eliminarVertice(vertice v);
    /**
     * ModificarEtiqueta
     * @param string
     * @param vertice
     * Efecto: Modifica la etiqueca del vertice.
     * Requiere: Vertice válido.
     * Modifica: Vertice.
     */
    void modificarEtiqueta(vertice v, string etiq);
    /**
     * Etiqueta
     * @param vertice
     * @return string
     * Efecto: Devuelve la etiqueta del vertice.
     * Requiere: Vértice válido.
     * Modifica: 
     */
    string Etiqueta(vertice v);
    /**
     * AgregarArista
     * @param vertice
     * @param vertice
     * @param int
     * Efecto: Agrega una arista que conecta a los vértices.
     * Requiere: Vertices válidos, y que no exista arista entre ambos vertices.
     * Modifica: grafo
     */
    void agregarArista(vertice v1, vertice v2, int peso);
    /**
     * EliminarArista
     * @param vertice
     * @param vertice
     * Efecto: Elimina la arista que conecta a los vértices.
     * Requiere: Vértices válidos, que exista arista entre v1, v2.
     * Modifica: grafo
     */
    void eliminarArista(vertice v1, vertice v2);
    /**
     * ModificarPeso
     * @param vertice
     * @param vertice
     * @return int
     * Efecto: Modififica el peso de la arista que conecta a los vertices.
     * Requiere: Vértices válidos.
     * Modifica: Peso del arista.
     */
    void modificarPeso(vertice v1, vertice v2, int pesoN);
    /**
     * Peso
     * @param vertice
     * @param vertice
     * @return int
     * Efecto: Devuelve el peso del arista que conecta a los vertices.
     * Requiere: Vértices válidos.
     * Modifica: 
     */
    int Peso(vertice v1, vertice v2);
    /**
     * Adyacentes
     * @param vertice
     * @param vertice
     * @return bool
     * Efecto: Devuelve verdadero si los vertices son adyacentes, falso en caso contrario.
     * Requiere: Vértices válidos.
     * Modifica: 
     */
    bool adyacentes(vertice v1, vertice v2);
    /**
     * PrimerVertice
     * @return vertice
     * Efecto: Devuelve el primer vértice del grafo, nulo si no existe.
     * Requiere: Grafo inicializado.
     * Modifica: 
     */
    vertice primerVertice();
    /**
     * SiguienteVertice
     * @param vertice
     * @return vertice
     * Efecto: Devuelve el siguiente vértice al que es pasado por parámetro, nulo si no existe.
     * Requiere: Vértice válido.
     * Modifica: 
     */
    vertice sigVertice(vertice v);
    /**
     * PrimerVerticeAdyacente
     * @param vertice
     * @return vertice
     * Efecto: Devuelve el primer vértice adyacente al que es pasado por parámetro, nulo si no existe.
     * Requiere: Vértice válido.
     * Modifica: 
     */
    vertice primerVerticeAdy(vertice v);
    /**
     * SiguienteVerticeAdyacente
     * @param vertice
     * @param vertice
     * @return vertice
     * Efecto: Devuelve el vértice adyacente a v, que está después de vAdy, nulo si no existe.
     * Requiere: Vértices válidos.
     * Modifica:
     */
    vertice sigVerticeAdy(vertice v, vertice vAdy);
    /**
     * NumVertices
     * @return int
     * Efecto: Devuelve el némero de vertices del grafo.
     * Requiere: Grafo inicializado.
     * Modifica:
     */
    int numVertices();
    /**
     * NumVerticesAdyacentes
     * @param vertice
     * @return int
     * Efecto: Devuelve el número de vertices adyacentes al vértice.
     * Requiere: Vértice válido.
     * Modifica:
     */
    int numVerticesAdy(vertice v);


private:

    void deleteAllEdges(arista v);
    void deleteAllVertex(vertice v);




};
typedef ListaDeAdy grafo;
#endif /* LISTADEADY_H */

