#pragma once
#include "Graph.h"
#include "NeighborList.h"

// Constructor
template<typename T>
Graph<T>::Graph(int maxnodes){
    if(maxnodes <= 0) maxnodes = 1;
    capability = maxnodes;
    cornerNum = 0;
    nodes = new Node<T>*[capability]; // reservamos un arreglo dinamico de punteros a node
    for(int i = 0; i<capability; ++i) nodes[i] = nullptr; // inicializamos todo en nullptr
}

// Destructor
template<typename T>
Graph<T>::~Graph(){
    for(int i = 0; i < capability; ++i){
        if(nodes[i] != nullptr){
            delete nodes[i];
            nodes[i] = nullptr;
        }
    }
    delete[] nodes;
    nodes = nullptr;
}

template<typename T>
int Graph<T>::maxCapability() const { return capability; }

template<typename T>
int Graph<T>::totalNodes() const { return cornerNum; }

template<typename T>
bool Graph<T>::idExists(int id) const{
    return (id >= 0 && id < capability && nodes[id] != nullptr);
}

template<typename T>
bool Graph<T>::addNodes(int id, const char* name, double prob){ // clase para agregar nodos
    if(id < 0 || id >= capability){
        std::cout<<"Error, nodo con el id: "<<id<<"\n";
        return false;
    }
    if(nodes[id] != nullptr){
        std::cout<<"Ya existe un vertice con id: "<<id<<"\n";
        return false;
    }
    nodes[id] = new Node<T>(id, name, prob);
    ++cornerNum;
    return true;
}

template<typename T>
bool Graph<T>::addEdges(int idA, int idB){ // agregamos aristas al grafo
    if(!idExists(idA) || !idExists(idB)){
        std::cout<<"No se puede crear arista "<<idA<<" - "<<idB<<" (uno no existe)\n";
        return false;
    }
    if(idA == idB){
        std::cout<<"No se permiten lazos sobre el mismo vertice ("<<idA<<")\n";
        return false;
    }
    nodes[idA]->addNeighbor(idB);
    nodes[idB]->addNeighbor(idA);
    return true;
}

template<typename T>
Node<T>* Graph<T>::search(int id){
    if(id < 0 || id >= capability) return nullptr;
    return nodes[id];
}

template<typename T>
const Node<T>* Graph<T>::search(int id) const{
    if(id < 0 || id >= capability) return nullptr;
    return nodes[id];
}

template<typename T> // TODO, revisar mas a fondo este metodo
void Graph<T>::printCheatBFS(int start, int end) const{
    if(start < 0 || start >= capability || end < 0 || end >= capability){
        std::cout<<"los id's estan fuera de rango\n";
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
        const Node<T>* node = nodes[u];
        if(!node) continue;

        // recorremos los vecinos
        const LinkedList<int>& neig = node->getNeighbors(); 
        NeighborList<int>* current = neig.getHead();
        while(current){
            int v = current->data;
            if(v >= 0 && v < capability && idExists(v) && !visit[v]){
                visit[v] = true;
                father[v] = u;
                queue[back++] = v;
                if(v == end){
                    founded = true;
                    break;
                }
            }
            current = current->next;
        }
    }
    if(!founded){
        std::cout<<"No hay ruta, gg\n";
    } else {
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

