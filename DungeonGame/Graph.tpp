#pragma once
#include "Graph.h"

// Constructor
template<typename T>
Graph<T>::Graph(int maxCorners){
    if(maxCorners <= 0) maxCorners = 1;
    capability = maxCorners;
    cornerNum = 0;
    corners = new Node<T>*[capability];
    for(int i = 0; i<capability; ++i) corners[i] = nullptr;
}

// Destructor
template<typename T>
Graph<T>::~Graph(){
    // Borramos los nodos que creamos
    for(int i = 0; i < capability; ++i){
        if(corners[i] != nullptr){
            delete corners[i];
            corners[i] = nullptr;
        }
    }
    delete[] corners;
    corners = nullptr;
}

template<typename T>
int Graph<T>::maxCapability() const { return capability; }

template<typename T>
int Graph<T>::totalCorners() const { return cornerNum; }

template<typename T>
bool Graph<T>::idExists(int id) const{
    return (id >= 0 && id < capability && corners[id] != nullptr);
}

template<typename T>
bool Graph<T>::addCorners(int id, const char* name, double prob, const T& extra){
    if(id < 0 || id >= capability){
        std::cout<<"Fuera de rango: "<<id<<"\n";
        return false;
    }
    if(corners[id] != nullptr){
        std::cout<<"Ya existe un vertice con id "<<id<<"\n";
        return false;
    }
    corners[id] = new Node<T>(id, name, prob, extra);
    ++cornerNum;
    return true;
}

template<typename T>
bool Graph<T>::addEdges(int idA, int idB){
    if(!idExists(idA) || !idExists(idB)){
        std::cout<<"No se puede crear arista "<<idA<<" - "<<idB<<" (uno no existe)\n";
        return false;
    }
    if(idA == idB){
        std::cout<<"No se permiten lazos sobre el mismo vertice ("<<idA<<")\n";
        return false;
    }
    // Como es un grafo no dirigido, agregamos en ambos sentido
    corners[idA]->addNeighbor(idB);
    corners[idB]->addNeighbor(idA);
    return true;
}

template<typename T>
Node<T>* Graph<T>::search(int id){
    if(id < 0 || id >= capability) return nullptr;
    return corners[id];
}

template<typename T>
const Node<T>* Graph<T>::search(int id) const{
    if(id < 0 || id >= capability) return nullptr;
    return corners[id];
}

template<typename T>
void Graph<T>::printCheatBFS(int start, int end) const{
    if(start < 0 || start >= capability || end < 0 || end >= capability){
        std::cout<<"los id's estan fuera de rango\n";
        return;
    } 
    if(!idExists(start) || !idExists(end)){
        std::cout<<"no existe inicio o fin\n";
        return;
    }
    if(start == end){
        std::cout<<"Ruta: "<<start<<"\n";
        return;
    }

    // Estructuras
    int* queue = new int[capability];
    bool* visit = new bool[capability];
    int* father = new int[capability];
    for(int i = 0; i < capability; ++i){
        queue[i] = -1;
        visit[i] = false;
        father[i] = -1;
    }
    int front = 0, back = 0;
    queue[back++] = start;
    visit[start] = true;
    bool founded = false;

    // BFS
    while(front < back && !founded){
        int u = queue[front++];
        const Node<T>* node = corners[u];
        if(!node) continue;

        // recorremos los vecinos
        const int* neig = node->getNeighbor(); 
        int n = node->getNeighborNum();
        for(int i = 0; i < n; ++i){
            int v = neig[i];
            if(v < 0 || v >= capability) continue;
            if(!visit[v] && idExists(v)){
                visit[v] = true;
                father[v] = u;
                queue[back++] = v;
                if(v == end){
                    founded = true;
                    break;
                }
            }
        }
    }
    if(!founded){
        std::cout<<"No hay ruta, gg\n";
    } else {
        // reconstruimos la ruta en un arreglo temporal
        int* path = new int[capability];
        int size = 0;
        for(int v = end; v != -1; v = father[v]){
            path[size++] = v;
        }
        std::cout<<"Ruta: ";
        for(int i = size - 1; i >= 0; --i){
            std::cout<<path[i];
            if(i > 0) std::cout<<" -> ";
        }
        std::cout<<"\n";
        delete[] path;
    }
    delete[] queue;
    delete[] visit;
    delete[] father;
}

template<typename T>
void Graph<T>::printSummary() const{
    std::cout<<"Graph summary ("<<cornerNum<<"/"<<capability<<")\n";
    for(int i = 0; i < capability; ++i){
        const Node<T>* node = corners[i];
        if(!node) continue;
        std::cout<<"["<<node->getId()<<"] "<<node->getName()
                 <<" prob="<<node->getEncounterProb()
                 <<" vecinos="<<node->getNeighborNum()<<"\n";
    }
}
