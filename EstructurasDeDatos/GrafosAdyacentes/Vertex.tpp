#pragma once
#include "Vertex.h"
template <typename T>
T Vertex<T>::getData() const{
    return data;
}
template <typename T>
bool Vertex<T>::isVisited() const {
    return visited;
}
template <typename T>
void Vertex<T>::setVisited(bool visited) {
    this->visited= visited;
}


