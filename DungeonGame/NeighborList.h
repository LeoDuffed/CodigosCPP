#ifndef NEIGHBORLIST_H
#define NEIGHBORLIST_H

// Nodo simple para las listas enlazadas de soporte (p. ej., vecinos).
// No es el vértice del grafo (Node.cpp); aquí solo guardamos data y next
// para no mezclar la lógica de la casilla del mapa con la infraestructura de lista.

template <typename T>
class NeighborList {
public:
    T data;
    NeighborList* next;
    NeighborList(const T& v);
};

#include "NeighborList.tpp"

#endif
