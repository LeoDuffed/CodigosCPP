#pragma once
#include <iostream>
#include "Graph.h"

using namespace std;

template <typename T>
int Graph<T>::indexOf(const T& v) const {
    for (int i = 0; i < count; i++) {
        if(vertices[i] == v) {
            return i;
        }
    }
    
    return -1;
}

template<typename T>
bool Graph<T>::addVertex(const T& v) {
    // Si llego al limite no puedo meter más
    if (count >= n) {
        return false;
    }

    // Ya existe
    if(indexOf(v) != -1) {
        return false;
    }

    vertices[count] = v;
    count++;

    return true;
}

template<typename T>
bool Graph<T>::addEdge(const T& v, const T& u, int weight = 1, bool directed = false) {

    int iu = indexOf(u);
    int iv = indexOf(v);

    if(iu == -1 || iv == -1) return false;

    matrix[iu][iv] = weight;
    if(directed) {
        matrix[iu][iv] = weight;
    }

    return true;
}

template<typename T>
void Graph<T>::primtMatrix() const {
    for (int i = 0; i < count; i++) {
        for (int j = 0; j < count; j++) {
            cout << matrix[i][j] << endl;
        }
    }
}
