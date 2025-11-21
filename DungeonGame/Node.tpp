#pragma once
#include "Node.h"
#include <cstring>

// Constructor por defecto
template<typename T>
Node<T>::Node(){
    id = -1;
    name[0] = '\0';
    encounterProb = 0.0;
    visited = false;
    extra = T{};
}

// Contructor 
template<typename T>
Node<T>::Node(int id, const char* name, double prob, const T& extra){
    this->id = id;
    if(name){
        std::strncpy(this->name, name, 63);
        this->name[63] = '\0';
    } else {
        this->name[0] = '\0';
    }
    this->encounterProb = prob;
    visited = false;
    this->extra = extra;
}

// Getters
template<typename T>
int Node<T>::getId() const { return id; }

template<typename T>
const char* Node<T>::getName() const { return name; }

template<typename T>
double Node<T>::getEncounterProb() const { return encounterProb; }

template<typename T>
bool Node<T>::isVisited() const { return visited; }

template<typename T>
int Node<T>::getNeighborNum() const { return neighbors.size(); }

template<typename T>
const LinkedList<int>& Node<T>::getNeighbors() const { return neighbors; }

template<typename T>
LinkedList<int>& Node<T>::getNeighbors() { return neighbors; }

// Setters
template<typename T>
void Node<T>::setId(int id){ this->id = id; }

template<typename T>
void Node<T>::setName(const char* name){
    if(name){
        std::strncpy(this->name, name, 63);
        this->name[63] = '\0';
    } else {
        this->name[0] = '\0';
    }
}

template<typename T>
void Node<T>::setEncounterProb(double prob){ encounterProb = prob; }

template<typename T>
void Node<T>::setVisited(bool visited) { this->visited = visited; }

// Aristas
template<typename T>
void Node<T>::addNeighbor(int neighborId){
    if(!hasNeighbor(neighborId)){
        neighbors.pushBack(neighborId);
    }
}

template<typename T>
bool Node<T>::hasNeighbor(int neighborId) const{
    return neighbors.search(neighborId) != nullptr;
}
