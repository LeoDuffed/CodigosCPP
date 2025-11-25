//
// Creado por Leonardo Martínez 
//
#pragma once
#include "Node.h"
#include <iostream>
using namespace std;

template <typename T>
Node<T>::Node(int k, const T& v): key(k), data(v), next(nullptr){}
template class Node<int>;

template<typename T>
void Node<T>::print(){
    cout<<data;    
}
