//
// Creado por Leonardo Martínez 
//
#ifndef VERTEX_H
#define VERTEX_H

#include "LinkedList.h"

template <typename T>
class Vertex {
private:
    T data;
    bool visited;

public:
    friend ostream& operator<<(ostream& out, const Vertex& v) {
        out<<v.getData();
        return out;
    }

    bool operator==(const Vertex<T>& v) {
        return data==v.getData();
    }

    Vertex(const T& v): data(v) {
        visited=false;
    }
    T getData() const;
    bool isVisited() const;
    void setVisited(bool visited);
    LinkedList<Vertex<T>> adj;

};
#include "Vertex.tpp"
#endif
