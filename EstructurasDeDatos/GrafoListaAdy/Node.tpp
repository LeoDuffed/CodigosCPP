//
// Creado por Leonardo Martínez 
//
#pragma once
#include "Node.h"

template <typename T>
Node<T>::Node(const T& v): data(v), next(nullptr){}
template class Node<int>;
