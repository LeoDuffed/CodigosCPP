#ifndef GRAPH_H
#define GRAPH_H
#include <iostream>
#include "Node.h"

// PD. las variables que se llaman corner son los vertices del grafo
template<typename T>
class Graph{
    private: 
        Node<T>** corners; 
        int capability;
        int cornerNum;
        // Funcion para ver si existe un vertice con un id dado
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