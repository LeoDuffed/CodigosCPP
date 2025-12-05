#ifndef NEIGHBORNODE_H
#define NEIGHBORNODE_H

// Nodo simple para las listas enlazadas de soporte (p. ej., vecinos).
// No es el vértice del grafo (Node.cpp); aquí solo guardamos data y next
// para no mezclar la lógica de la casilla del mapa con la infraestructura de lista.

template <typename T>
class NeighborNode {
public:
    T data;
    NeighborNode* next;
    NeighborNode(const T& v);
};

#include "NeighborNode.tpp"

#endif
