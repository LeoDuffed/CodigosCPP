#pragma once
#include "Graph.h"
#include <iostream>
using namespace std;
template <typename T>
Node<Vertex<T>>* Graph<T>::findVertexNode(const T& v){
    Node<Vertex<T>>* current= vertices.getHead();
    while (current) {
        if (current->data.getData() == v) {
            return current;
        }
        current= current->next;
    }
    return nullptr;
}

template <typename T>
bool Graph<T>::addVertex(const T& v) {
    if (findVertexNode(v) !=nullptr) {
        return false;
    }
    Vertex<T> vertex(v);
    vertices.pushBack(vertex);
    return true;
}

template <typename T>
bool Graph<T>::addEdge(const T& from,const T& to, const bool directed) {
    Node<Vertex<T>>* originNode = findVertexNode(from);
    Node<Vertex<T>>* toNode = findVertexNode(to);
    if (!originNode || !toNode) {
        return false;
    }

    if (!originNode->data.adj.search(to)) {
        originNode->data.adj.pushBack(to);
    }
    if (!directed) {
        if (!toNode->data.adj.search(from)) {
            toNode->data.adj.pushBack(from);
        }
    }
    return true;
}

template <typename T>
void Graph<T>::print() const {
    Node<Vertex<T>>* current = vertices.getHead();
    while (current) {
        cout << current->data.getData() <<": ";
        current->data.adj.print();
        current= current->next;
        cout<<endl;
    }
}