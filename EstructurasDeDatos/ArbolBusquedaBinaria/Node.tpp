#pragma once

template<typename T>
Node<T>* Node<T>::getLeft(){
    return left;
}

template<typename T>
void Node<T>::setLeft(Node<T>* node){
    left = node;
}

template<typename T>
Node<T>* Node<T>::getRight(){
    return right;
}

template<typename T>
void Node<T>::setRight(Node<T>* node){
    right = node;
}

template<typename T>
T Node<T>::getData(){
    return data;
}

template<typename T>
void Node<T>::setData(T& v){
    data = v;
}