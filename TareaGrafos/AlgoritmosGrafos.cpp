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

struct Par {
    vertice v1;
    vertice v2;

    bool operator==(const Par& par) const {
        bool iguales = (v1 == par.v1 && v2 == par.v2) ||
                (v1 == par.v2 && v2 == par.v1);
        return iguales;
    }

    bool operator!=(const Par& par) const {
        return !this->operator==(par);
    }
};
//Se utilizan en Dijkstra
map <string, int> Distancia;
map <string, string> Caminos;
map<string, int>::iterator it;
map<string, string>::iterator itCaminos;
Diccionario<Par> aristasVisitadas;
//grafo grf;
// se utiliza para el problema del vendedor.
Diccionario<vertice> diccVertVisitados;
vertice solActual[100];
vertice mejorSol[100];
int numSoluciones = 0;
int costoActual = 0;
int menorCosto = 1000000;
// se utiliza para ver si son iguales.
map<vertice, vertice> R11Vert;
//map<vertice,vertice> aristasVisitadas;

AlgoritmosGrafos::AlgoritmosGrafos() {
}

//AlgoritmosGrafos::AlgoritmosGrafos(const AlgoritmosGrafos& orig) {
//}

AlgoritmosGrafos::~AlgoritmosGrafos() {

}

void AlgoritmosGrafos::Dijkstra(vertice v, const grafo& grf) {
    vector<int> VectorPesos(grf.numVertices());
    vector<string> VectorCaminos(grf.numVertices());
    map<vertice,int> R11VertInd;
    map<int,vertice> R11IndVert;
    vertice v1=grf.primerVertice();
    int indice=0;
    while(v1!=nullptr){
        if(v1!=v){
            R11VertInd[v1]=indice;
            R11IndVert[indice]=v1;
            indice++;
        }
        v1=grf.sigVertice(v1);
    }
    
    indice++;
    v1=grf.primerVertice();
    while(v1!=nullptr){
        if(v1!=v){
            if (grf.Peso(v,v1)!=-1){
                VectorPesos[R11VertInd[v1]]=grf.Peso(v,v1);
            } else{
                VectorPesos[R11VertInd[v1]]=numeric_limits<int>::max();
            }
            VectorCaminos[R11VertInd[v1]]=grf.Etiqueta(v1);
        }
        v1=grf.sigVertice(v1);
    }
    
    Diccionario<vertice> DVV;
    DVV.iniciar();
    DVV.agregar(v);
    int menor;
    int menorPeso;
    int cont;
    vertice pivote;
    while (DVV.numElem()<indice){
        menorPeso=numeric_limits<int>::max();
        cont=0;
        while (cont<indice-1){
            if((VectorPesos[cont]<menorPeso)&&(!DVV.pertenece(R11IndVert[cont]))){
                menor=cont;
                menorPeso=VectorPesos[cont];
            }
            cont++;
        }
        
        pivote=R11IndVert[menor];
        DVV.agregar(pivote);
        v1=grf.primerVerticeAdy(pivote);
        while(v1!=nullptr){
            if(v1!=v){
                if(VectorPesos[R11VertInd[v1]]>(grf.Peso(pivote,v1)+VectorPesos[R11VertInd[pivote]])){
                    VectorPesos[R11VertInd[v1]]=grf.Peso(pivote,v1)+VectorPesos[R11VertInd[pivote]];
                    VectorCaminos[R11VertInd[v1]]=VectorCaminos[R11VertInd[v1]]+" - "+ grf.Etiqueta(pivote);
                }
            }
            v1=grf.sigVerticeAdy(pivote,v1);
        }        
    }
    
    for(int j=0; j<VectorCaminos.size()-1;j++){
        cout<< "El camino mas corto del vert "<< grf.Etiqueta(v)<< " hasta el vert "<< grf.Etiqueta(R11IndVert[j])<< " es: "<< VectorCaminos[j];
        cout<< " con un peso de: "<< VectorPesos[j]<<"\n";
    }
    
    DVV.~Diccionario();
}

void Floyd(const grafo& grf) {
    int tamGrafo = grf.numVertices();
    int Costos[tamGrafo][tamGrafo]; //Matriz de costos.
    int Vertices[tamGrafo][tamGrafo]; //Matriz de vertices.
    int i, j, k;
    vertice v1 = grf.primerVertice();
    vertice v2;
    vertice resultado;
    vertice actual;
    vector <vertice> recorrido;

    //Construye el vector recorrido.
    while (v1 != nullptr) {
        recorrido.push_back(v1);
        v1 = grf.sigVertice(v1);
    }

    //Llena la matriz Costos con los pesos de las aristas del grafo.
    for (i = 0; i < tamGrafo; ++i) {
        v1 = recorrido[i];
        for (j = i; j < tamGrafo; ++j) {
            v2 = recorrido[j];
            if (grf.adyacentes(v1, v2)) {
                Costos[i][j] = grf.Peso(v1, v2);
                Costos[j][i] = grf.Peso(v1, v2);
            } else //Si no existe arista utiliza -1 como "infinito".
            {
                Costos[i][j] = -1;
                Costos[j][i] = -1;
            }
        }
    }

    //Llena la matriz Vertices con ceros.
    for (i = 0; i < tamGrafo; ++i) {
        for (j = 0; j < tamGrafo; ++j) {
            Vertices[i][j] = 0;
        }
    }

    //Hace cero la diagonal de la matriz de pesos Costos.
    for (int i = 0; i < tamGrafo; ++i) {
        Costos[i][i] = 0;
    }

    //Ciclo del algoritmo de Floyd.
    for (k = 0; k < tamGrafo; ++k) {
        for (i = 0; i < tamGrafo; ++i) {
            for (j = 0; j < tamGrafo; ++j) {
                if (Costos[i][k] != -1 && Costos[k][j] != -1) {
                    if ((Costos[i][k] + Costos[k][j]) < Costos[i][j] || Costos[i][j] == -1) {
                        Costos[i][j] = Costos[i][k] + Costos[k][j];
                        Vertices[i][j] = k;
                    }
                }
            }
        }
    }

    //Cambia los "infinitos" por cero.
    for (int i = 0; i < tamGrafo; ++i) {
        for (int j = 0; j < tamGrafo; ++j) {
            if (Costos[i][j] == -1) {
                Costos[i][j] = 0;
            }
        }
    }
    cout << "Se ha ejecutado Floyd. Ingrese la etiqueta del vertice del que desea saber los caminos mas cortos, ingrese un -1 para salir." << endl;
    string e;
    cin >> e;
    vector <vertice>::iterator vit; //Iterador para moverse por el vector recorrido.
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
        vit = recorrido.begin();
        j = 0;
        while (*vit != v1) //Busca en el recorrido el vertice con la etiqueta ingresada.
        {
            ++vit;
            ++j;
        }
        for (i = 0; i < tamGrafo; ++i) {
            cout << "El camino mas corto de " << grf.Etiqueta(v1) << " a " << grf.Etiqueta(recorrido[i]) << ": " << grf.Etiqueta(v1);
            k = i;
            while (Vertices[j][k] != 0) {
                cout << "-> " << grf.Etiqueta(recorrido[Vertices[j][k]]);
                k = Vertices[j][k];
            }
            cout << "-> " << grf.Etiqueta(recorrido[i]);
            cout << ". Su costo es de: " << Costos[j][i] << endl;
        }
        cout << "Ingrese la etiqueta del vertice del que desea saber los caminos mas cortos, ingrese un -1 para salir." << endl;
        cin >> e;
    }
}

void AlgoritmosGrafos::Prim(const grafo& grf) {
    Diccionario<vertice>* dVV = new Diccionario<vertice>;
    dVV->agregar(grf.primerVertice());
    vertice v,vAdy,menor,menorAdy;
    int pesoMinimo;
    int numElem = grf.numVertices();
    while (dVV->numElem() < numElem){
        pesoMinimo= numeric_limits<int>::max();
        v = grf.primerVertice();
        while (v != nullptr) {
            if (dVV->pertenece(v)) {
                vAdy = grf.primerVerticeAdy(v);
                while(vAdy != nullptr){
                    if(!dVV->pertenece(vAdy)){
                        if(grf.Peso(v,vAdy) < pesoMinimo){
                            pesoMinimo = grf.Peso(v,vAdy);
                            menor = v;
                            menorAdy = vAdy;
                            //cout<< pesoMinimo;
                        }
                    }
                    vAdy = grf.sigVerticeAdy(v,vAdy);
                }
            }
            v = grf.sigVertice(v);
        }
        dVV->agregar(menorAdy);
        cout << grf.Etiqueta(menor) << "-" << grf.Etiqueta(menorAdy)<< " Peso: "<<pesoMinimo<<"\n";
    }
}

void AlgoritmosGrafos::Kruskal(const grafo& g) {
    cnjDeCnj.iniciar();
    ColaDePrioridad<pair<vertice, vertice>> CP;
    Diccionario<pair<vertice, vertice>> DiccAristasV;
    CP.iniciar();
    vertice v = g.primerVertice();
    vertice va;
    int nom = 0; // se usan ints para el identificador pero en string;
    pair<vertice, vertice> vertices;
    while (v != nullptr) {
        va = g.primerVerticeAdy(v);
        cnjDeCnj.agregarConjunto(to_string(nom), v);

        while (va != nullptr) {
            vertices.first = v;
            vertices.second = va;
            if (!DiccAristasV.pertenece(make_pair(va, v))) {
                CP.agregar(vertices, g.Peso(v, va));
                DiccAristasV.agregar(vertices);
            }
            va = g.sigVerticeAdy(v, va);
        }
        nom++;
        v = g.sigVertice(v);
    }

    int costo = 0;
    int cantAristas = 0;
    cout << "el arbol de costo minimo es: \n";
    string Ncnj1;
    string Ncnj2;
    while (cantAristas < g.numVertices() - 1) {
        vertices = CP.sacar();
        Ncnj1 = cnjDeCnj.conjuntoAlQuePertenece(vertices.first);
        Ncnj2 = cnjDeCnj.conjuntoAlQuePertenece(vertices.second);

        if (Ncnj1 != Ncnj2) {
            cout << g.Etiqueta(vertices.first) << "-" << g.Etiqueta(vertices.second)<< " con Peso: "<<g.Peso(vertices.first, vertices.second) << "\n";
            costo += g.Peso(vertices.first, vertices.second);
            cnjDeCnj.unirConjuntos(Ncnj1, Ncnj2);
            cantAristas++;
        }
    }
    cout << "y su costo es de " << costo << endl;
    cnjDeCnj.~ConjuntoDeConj();
    CP.~ColaDePrioridad();
}

grafo AlgoritmosGrafos::Copiar(const grafo& original) {
    grafo copia;
    string etiqueta = "";
    vertice v = original.primerVertice();
    int tamOriginal = original.numVertices();
    int peso = 0;
    //Copia todos los vertices de original a la copia
    for (int i = 0; i < tamOriginal; i++) {
        etiqueta = original.Etiqueta(v);
        copia.agregarVertice(etiqueta);
        v = original.sigVertice(v);
    }
    //
    v = original.primerVertice();
    vertice vCopia;
    vertice vCopiaAdy;
    vertice adyacente;
    while (v != nullptr) {
        etiqueta = original.Etiqueta(v);
        vCopia = buscarEtiq(etiqueta, copia);
        adyacente = original.primerVerticeAdy(v);

        while (adyacente != nullptr) {
                    peso = original.Peso(v, adyacente);
            if (!aristasVisitadas.pertenece({v, adyacente})) {//El == de este funciona en ambas direcciones
                aristasVisitadas.agregar({v, adyacente});
                //Conecta los vertices en la copia
                etiqueta = original.Etiqueta(adyacente);
                vCopiaAdy = buscarEtiq(etiqueta, copia);
                peso = original.Peso(v, adyacente);
                copia.agregarArista(vCopia, vCopiaAdy, peso);
                //
            }
            adyacente = original.sigVerticeAdy(v, adyacente);
        }
        v = original.sigVertice(v);
    }
    return copia;
}

bool AlgoritmosGrafos::Iguales(const grafo& g1,const grafo& g2) {
    bool iguales = true;
    if (g1.numVertices() == g2.numVertices()) {
        R11Vert.clear();
        vertice v1 = g1.primerVertice();
        vertice v2;
        while ((v1 != nullptr)&&(iguales)) {
            v2 = buscarEtiq(g1.Etiqueta(v1), g2);
            if (v2 != nullptr) {
                if (g1.numVerticesAdy(v1) == g2.numVerticesAdy(v2)) {
                    R11Vert[v1] = v2;
                } else iguales = false;
            } else iguales = false;
            v1 = g1.sigVertice(v1);
        }

    } else iguales = false;
    if (iguales) {
        vertice v1 = g1.primerVertice();
        vertice v2;
        while ((v1 != nullptr)&&(iguales)) {
            v2 = g1.primerVerticeAdy(v1);
            while ((v2 != nullptr)&&(iguales)) {
                if (g1.Peso(v1, v2) == g2.Peso(R11Vert[v1], R11Vert[v2])) {
                    v2 = g1.sigVerticeAdy(v1, v2);
                } else iguales = false;
            }
            v1 = g1.sigVertice(v1);
        }
    }

    return iguales;
}

void AlgoritmosGrafos::visitarVertRec(const grafo& g, int i) {
    vertice va = g.primerVerticeAdy(solActual[i - 1]);
    while (va != nullptr) {
        if (!diccVertVisitados.pertenece(va)) {
            diccVertVisitados.agregar(va);
            solActual[i] = va;
            costoActual += g.Peso(solActual[i - 1], va);
            if (i == g.numVertices()) {
                if (g.adyacentes(solActual[1], solActual[i])) {
                    costoActual += g.Peso(solActual[1], solActual[i]);
                    if (menorCosto > costoActual) {
                        menorCosto = costoActual;
                        for (int j = 1; j <= i; j++)
                            mejorSol[j] = solActual[j];
                    }
                    numSoluciones++;
                    costoActual -= g.Peso(solActual[1], solActual[i]);
                }
            } else {
                visitarVertRec(g, i + 1);
            }
            diccVertVisitados.eliminar(va);
            costoActual -= g.Peso(solActual[i - 1], va);
        }
        va=g.sigVerticeAdy(solActual[i-1],va);
    }

}

void AlgoritmosGrafos::vendedor(const grafo& g) {
    diccVertVisitados.iniciar();
    solActual[1] = g.primerVertice();
    diccVertVisitados.agregar(g.primerVertice());
    visitarVertRec(g, 2);
    cout << "Se obtuvieron: " << numSoluciones << " soluciones factibles. \nLa solucion con el menor costo obtenida fue: ";
    for (int i = 1; i <= g.numVertices(); ++i) {
        cout << g.Etiqueta(mejorSol[i]) << ", ";
    }
    cout << "\ncon un costo de: " << menorCosto << endl;

    diccVertVisitados.~Diccionario();
}

vertice AlgoritmosGrafos::buscarEtiq( string etiq ,const grafo&  g) {
    vertice v = g.primerVertice();
    while ((v != nullptr)&&(g.Etiqueta(v) != etiq)) {
        v = g.sigVertice(v);
    }
    return v;
}