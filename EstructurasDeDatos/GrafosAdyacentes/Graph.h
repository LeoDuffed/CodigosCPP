#ifndef GRAFO_H
#define GRAFO_H
#include "LinkedList.h"
#include "Vertex.h"
#include "Node.h"

template<typename T>
class Graph{
    private:
        LinkedList<Vertex<T>> vertices;
        Node<Vertex<T>>* findVertexNode(const T& v);
    public:
        Graph() = default;
        bool addVertex(const T& v);
        bool addEdge(const T& from, const T& to, const bool directed);
        void print() const;
};

#include "Graph.tpp"

#endif