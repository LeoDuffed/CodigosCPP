// 4/11/2025
// Codigo hecho por Leonardo Martínez y Juan Eduardo Barrón

#pragma once
#include <iostream>
#include "Node.h"

template<typename T>       
T Node<T>::getData(){ return data; }

template<typename T>
Node<T>* Node<T>::getLeft(){ return left; }

template<typename T>
Node<T>* Node<T>::getRight(){ return right; }

template<typename T>
int Node<T>::getHeight() const{ return height; }

template<typename T>
void Node<T>::setData(const T& v){ data = v; }

template<typename T>
void Node<T>::setRight(Node<T>* right){ this->right = right; }

template<typename T>
void Node<T>::setLeft (Node<T>* left){ this->left = left; }