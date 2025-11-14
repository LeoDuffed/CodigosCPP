#ifndef VERTEX_H
#define VERTEX_H

#include "LinkedList.h"
#include "ostream"

template<typename T>
class Vertex{
    private:
        T data;
        LinkedList<Vertex> adj;
        bool visited;
    public:
        friend bool ostream& operator==(const Vertex<T> v){
            return data == v.getData();
        }
        Vertex(const T& v): data(v){
            visited = false;
        }
        T getData() const;
        bool isVisited() const;
        void setVisited(bool visited);
        LinkedList<Vertex<T>> getAdj();
};

#include "Vertex.h"

#endif