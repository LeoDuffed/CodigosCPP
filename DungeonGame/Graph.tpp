#pragma once
#include "Graph.h"
#include "NeighborNode.h"
#include <limits>

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

template<typename T> 
void Graph<T>::printCheatDijstrak(int start, int end) const{
    if(start == end){
        std::cout<<"Ruta: "<<start<<"\n";
        return;
    }
    // como mis "pesos" son las probabilidades de encuentro
    // uso la libreria de numeric_limits, para usar doubles
    const double MAX_DOUBLE = std::numeric_limits<double>::infinity();
    // arreglos para el dijstrak
    double* dist = new double[capability];
    int* father = new int[capability];
    bool* visit = new bool[capability];
    for(int i = 0; i < capability; i++){
        dist[i] = MAX_DOUBLE;
        father[i] = -1;
        visit[i] = false;
    }
    dist[start] = 0.0;
    //Disjtrak
    for(int i = 0; i < capability; i++){
        int u = -1;
        double best = MAX_DOUBLE;
        for(int j = 0; j < capability; j++){
            if(!visit[j] && idExists(j) && dist[j] < best){
                best = dist[j];
                u = j;
            }
        }
        // si ya no hay mas o llegamos al tesoro = break;
        if(u == -1) break;
        if(u == end) break;
        visit[u] = true;
        const Node<T>* node = nodes[u];
        if(!node) continue;
        // Empieza la relajacion xd
        const LinkedList<int>& neig = node->getNeighbors();
        NeighborNode<int>* current = neig.getHead();
        while(current){
            int v = current->data;
            if(v >= 0 && v < capability && idExists(v) && !visit[v]){
                const Node<T>* nv = nodes[v];
                double weight = 0.0;
                if(nv){
                    weight = nv->getEncounterProb();
                }
                double cand = dist[u] + weight;
                if(cand < dist[v]){
                    dist[v] = cand;
                    father[v] = u;
                }
            }
            current = current->next;
        }
    }
    if(dist[end] == MAX_DOUBLE){
        std::cout<<"No hay ruta, gg\n";
    } else {
        // ahora reconstruimos el caminito 
        int* path = new int[capability];
        int size = 0;
        for(int v = end; v != -1; v = father[v]){
            path[size++] = v;
        }
        for(int i = size - 1; i >= 0; --i){
            std::cout<<path[i];
            if(i > 0) std::cout<<" -> ";
        }
        std::cout<<"\n";
        delete[] path;
    }
    delete[] dist;
    delete[] father;
    delete[] visit;
}
