/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Algoritmosgrfrafos.cpp
 * Author: Javier
 * 
 * Created on 5 de noviembre de 2017, 11:35 p.m.
 */

#include "AlgoritmosGrafos.h"
using namespace std;
//Se utilizan en Dijkstra
map <string, int> Distancia; //También se utiliza en Coloreo de grfrafo
map <string, string> Caminos;
map<string, int>::iterator it;
map<string, string>::iterator itCaminos;
grafo grf;
Diccionario<vertice> diccVertVisitados;
Vertice solActual[100];
Vertice mejorSol[100];
int numSoluciones = 0;
int costoActual = 0;
int menorCosto= 1000000;


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
                //Buscar Vertice en grfrafo
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
                    //Buscar Vertice en grfrafo
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

void Floyd(grafo grf) {
    int cantVertices = grf.numVertices();
    int A[cantVertices][cantVertices]; //Matriz de costos.
    int P[cantVertices][cantVertices]; //Matriz de vertices.
    int i, j, k;
    vertice v1 = grf.primerVertice();
    vertice v2;
    vertice resultado;
    vertice actual;
    vector <vertice> mapeo;

    //Construye el vector mapeo.
    while (v1 != nullptr) {
        mapeo.push_back(v1);
        v1 = grf.sigVertice(v1);
    }

    //Llena la matriz A con los pesos de las aristas del grafo.
    for (i = 0; i < cantVertices; ++i) {
        v1 = mapeo[i];
        for (j = i; j < cantVertices; ++j) {
            v2 = mapeo[j];
            if (grf.adyacentes(v1, v2)) {
                A[i][j] = grf.Peso(v1, v2);
                A[j][i] = grf.Peso(v1, v2);
            } else //Si no existe arista utiliza -1 como "infinito".
            {
                A[i][j] = -1;
                A[j][i] = -1;
            }
        }
    }

    //Llena la matriz P con ceros.
    for (i = 0; i < cantVertices; ++i) {
        for (j = 0; j < cantVertices; ++j) {
            P[i][j] = 0;
        }
    }

    //Hace cero la diagonal de la matriz de pesos A.
    for (int i = 0; i < cantVertices; ++i) {
        A[i][i] = 0;
    }

    //Ciclo del algoritmo de Floyd.
    for (k = 0; k < cantVertices; ++k) {
        for (i = 0; i < cantVertices; ++i) {
            for (j = 0; j < cantVertices; ++j) {
                if (A[i][k] != -1 && A[k][j] != -1) {
                    if ((A[i][k] + A[k][j]) < A[i][j] || A[i][j] == -1) {
                        A[i][j] = A[i][k] + A[k][j];
                        P[i][j] = k;
                    }
                }
            }
        }
    }

    //Cambia los "infinitos" por cero.
    for (int i = 0; i < cantVertices; ++i) {
        for (int j = 0; j < cantVertices; ++j) {
            if (A[i][j] == -1) {
                A[i][j] = 0;
            }
        }
    }
    cout << "Se ha ejecutado Floyd. Ingrese la etiqueta del vertice del que desea saber los caminos mas cortos, ingrese un -1 para salir." << endl;
    string e;
    cin >> e;
    vector <vertice>::iterator vit; //Iterador para moverse por el vector mapeo.
    while (e != "-1") {
        //Buscar Vertice en grfrafo
        resultado = nullptr;
        actual = grf.primerVertice();
        while (actual != nullptr && resultado == nullptr) {
            if (grf.Etiqueta(actual) == it->first) {
                resultado = actual;
            }
            actual = grf.sigVertice(actual);
        }
        //
        v1 = actual;
        vit = mapeo.begin();
        j = 0;
        while (*vit != v1) //Busca en el mapeo el vertice con la etiqueta ingresada.
        {
            ++vit;
            ++j;
        }
        for (i = 0; i < cantVertices; ++i) {
            cout << "El camino mas corto de " << grf.Etiqueta(v1) << " a " << grf.Etiqueta(mapeo[i]) << ": " << grf.Etiqueta(v1);
            k = i;
            while (P[j][k] != 0) {
                cout << "-> " << grf.Etiqueta(mapeo[P[j][k]]);
                k = P[j][k];
            }
            cout << "-> " << grf.Etiqueta(mapeo[i]);
            cout << ". Su costo es de: " << A[j][i] << endl;
        }
        cout << "Ingrese la etiqueta del vertice del que desea saber los caminos mas cortos, ingrese un -1 para salir." << endl;
        cin >> e;
    }
}

void AlgoritmosGrafos::Prim() {

}

void AlgoritmosGrafos::Kruskal(grafo g) {
    cnjDeCnj.iniciar();
    ColaDePrioridad<pair<vertice, vertice>> CP;
    Diccionario<pair<vertice, vertice>> DiccAristasV;
    CP.iniciar();
    vertice v= g.primerVertice();
    vertice va;
    int nom=0; // se usan ints para el identificador pero en string;
    pair<vertice, vertice> vertices;
    while(v!=nullptr){
        va=g.primerVerticeAdy(v);
        cnjDeCnj.agregarConjunto(to_string(nom),v);
        
        while(va!=nullptr){
            vertices.first=v;
            vertices.second=va;
            if (!DiccAristasV.pertenece(make_pair(va,v))){
                CP.agregar(vertices,g.Peso(v,va));
                DiccAristasV.agregar(vertices);
            }
            va=g.sigVerticeAdy(v, va);
        }
        nom++;
        v=g.sigVertice(v);
    }
    
    int costo=0;
    int cantAristas=0;
    cout<<"el arbol de costo minimo es: ";
    string Ncnj1;
    string Ncnj2;
    while(cantAristas<g.numVertices()-1){
        vertices=CP.sacar();
        Ncnj1=cnjDeCnj.conjuntoAlQuePertenece(vertices.first);
        Ncnj2=cnjDeCnj.conjuntoAlQuePertenece(vertices.second);
        
        if(Ncnj1!=Ncnj2){
            cout<< g.Etiqueta(vertices.first)<<"-"<< g.Etiqueta(vertices.second)<<", ";
            costo+=g.Peso(vertices.first,vertices.second);
            cnjDeCnj.unirConjuntos(Ncnj1,Ncnj2);
            cantAristas++;
        }
    }
    cout<< "y su costo es de"<<costo<<endl;
    cnjDeCnj.~ConjuntoDeConj();
    CP.~ColaDePrioridad();
}

grafo AlgoritmosGrafos::Copiar(grafo original) {
//    grafo copia;
//    visitedEdges.empty();
//    Graph::Vertex vertex = graph.firstVertex();
//    const int numVertex = graph.numVertex();
//    for (int i = 0; i < numVertex; i++) {
//        std::string label = graph.getLabel(vertex);
//        graphCopy.addVertex(label);
//        vertex = graph.nextVertex(vertex);
//    }
//    vertex = graph.firstVertex();
//    while (vertex != Graph::NullVertex) {
//        std::string label = graph.getLabel(vertex);
//        Graph::Vertex vertexCopy = findVertex(graphCopy, label);
//        Graph::Vertex adjacent = graph.firstAdjacent(vertex);
//        while (adjacent != Graph::NullVertex) {
//            if (!visitedEdges.contains({vertex, adjacent})) {
//                visitedEdges.add({vertex, adjacent});
//                label = graph.getLabel(adjacent);
//                Graph::Vertex adjacentCopy = findVertex(graphCopy, label);
//                int weight = graph.getWeight(vertex, adjacent);
//                graphCopy.addEdge(vertexCopy, adjacentCopy, weight);
//            }
//            adjacent = graph.nextAdjacent(vertex, adjacent);
//        }
//        vertex = graph.nextVertex(vertex);
//    }
//    return graphCopy;
}

bool AlgoritmosGrafos::Iguales(grafo g1, grafo g2) {

}


void AlgoritmosGrafos::visitarVertRec(grafo g, int i){
    vertice va= g.primerVerticeAdy(solActual[i-1]);
    while(va!=nullptr){
        if(!diccVertVisitados.pertenece(va)){
            diccVertVisitados.agregar(va);
            solActual[i]=va;
            costoActual+=g.Peso(solActual[i-1],va);
            if(i==g.numVertices()){
                if(g.adyacentes(solActual[i],solActual[i])){
                    costoActual+=g.Peso(solActual[1],solActual[i]);
                    if(menorCosto>costoActual){
                        menorCosto=costoActual;
                        mejorSol=solActual;
                    }
                    numSoluciones++;
                    costoActual-=g.Peso(solActual[1],solActual[i]);
                }
            } else {
                visitarVertRec(g, i+1);
            }
            diccVertVisitados.eliminar(va);
            costoActual-=g.Peso(solActual[i-1],va);
        }
    }
    
}

void AlgoritmosGrafos::vendedor(grafo g){
    diccVertVisitados.iniciar();
    solActual[1]=g.primerVertice();
    diccVertVisitados.agregar(g.primerVertice());
    visitarVertRec(g,2);
    cout << "Se obtuvieron: " << numSoluciones << " soluciones factibles. \nLa solucion con el menor costo obtenida fue: ";
    for (int i = 1; i <= g.numVertices(); ++i)
    {
        cout << g.Etiqueta(mejorSol[i]) << ", ";
    }
    cout << "\ncon un costo de: " << menorCosto << endl;
    
    diccVertVisitados.~Diccionario();
}

