#ifndef GRAPH_H
#define GRAPH_H
#include "LinkedList.h"
#include "Vertex.h"
template <typename T>
class Graph {
private:
    int count;
    bool* visited;
    LinkedList<Vertex<T>> vertices;
    Node<Vertex<T>>* findVertexNode(const T& v);
    void resetVisited();
public:
    Graph(int capacity): n(capacity), count(0){

    }
    bool addVertex(const T& v);
    bool addEdge(const T& from,const T& to,const bool directed );
    void print() const;
    void BFS(const T& start);
    void DFS(const T& start);
};

#include "Graph.tpp"

#endif
