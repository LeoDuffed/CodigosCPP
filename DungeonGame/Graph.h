#ifndef GRAPH_H
#define GRAPH_H
#include <iostream>
#include "Node.h"

// Grafo usando lista de adyacencia
template<typename T>
class Graph{
    private: 
        Node<T>** corners; 
        int capability;
        int cornerNum;
        bool idExists(int id) const;
    public:
        Graph(int maxCorners = 64);
        ~Graph();
        int maxCapability() const;
        int totalCorners() const;
        bool addCorners(int id, const char* name, double prob, const T& extra = T{});
        bool addEdges(int idA, int idB);
        Node<T>* search(int id);
        const Node<T>* search(int id) const;
        void printCheatBFS(int start, int end) const;
        void printSummary() const;
};  

#include "Graph.tpp"

#endif
