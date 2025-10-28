#pragma once
#include "Node.h"

// Constructor por defecto
template<typename T>
Node<T>::Node(){
    id = -1;
    name[0] = '\0';
    encounterProb = 0.0;
    visited = false;
    neighborNum = 0;
    neighbors = nullptr;
    extra = T{};
}

// Contructor 
template<typename T>
Node<T>::Node(int id, const char* name, double prob, const T& extra){
    this->id = id;
    int i = 0;
    if(name){
        for(; name[i] != '\0' && i < 63; ++i){
            this->name[i] = name[i];
        }
        this->name[i] = '\0';
    } else {
        this->name[0] = '\0';
    }
    this->encounterProb = prob;
    visited = false;
    neighborNum = 0;
    neighbors = nullptr;
    this->extra = extra;
}

// Destructor
template<typename T>
Node<T>::~Node(){
    delete[] neighbors;
    neighbors = nullptr;
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
int Node<T>::getNeighborNum() const { return neighborNum; }

template<typename T>
const int* Node<T>::getNeighbor() const { return neighbors; }

template<typename T>
T& Node<T>::getExtra() { return extra; }

template<typename T>
const T& Node<T>::getExtra() const { return extra; }

// Setters
template<typename T>
void Node<T>::setId(int id){ this->id = id; }

template<typename T>
void Node<T>::setName(const char* name){
    if(name){
        int i = 0;
        for(; name[i] != '\0' && i < 63; ++i){
            this->name[i] = name[i];
        }
        this->name[i] = '\0';
    } else {
        this->name[0] = '\0';
    }
}

template<typename T>
void Node<T>::setEncounterProb(double prob){ encounterProb = prob; }

template<typename T>
void Node<T>::setVisited(bool visited) { this->visited = visited; }

template<typename T>
void Node<T>::setExtra(const T& extra) { this->extra = extra; }

// Aristas
template<typename T>
void Node<T>::addNeighbor(int neighborId){
    // Creamos un nuevo arreglo con +1 espacio, para gragar y copiarlo
    int* newArray = new int[neighborNum + 1];
    for(int i = 0; i<neighborNum; ++i) newArray[i] = neighbors[i];
    newArray[neighborNum] = neighborId;
    delete[] neighbors;
    neighbors = newArray;
    ++neighborNum;
}
