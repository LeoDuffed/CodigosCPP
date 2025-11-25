#ifndef GRAPH_H
#define GRAPH_H
#include <iostream>
#include "Node.h"

// Grafo usando lista de adyacencia (Grafo no dirigido)
// El grafo es un arreglo de punteros a node, y 
// cada node tiene una lista de vicinos, loquisimo
// (lista enlazada de ids)
template<typename T>
class Graph{
    private: 
        Node<T>** nodes; 
        int capability;
        int cornerNum;
        bool idExists(int id) const;
    public:
        Graph(int maxNodes = 65);
        ~Graph();
        int maxCapability() const;
        int totalNodes() const;
        bool addNodes(int id, const char* name, double prob);
        bool addEdges(int idA, int idB);
        Node<T>* search(int id);
        const Node<T>* search(int id) const;
        void printCheatDijstrak(int start, int end) const;
};  

#include "Graph.tpp"

#endif
