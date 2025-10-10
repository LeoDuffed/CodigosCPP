#pragma once

template<typename T>
T Node<T>::getData(){
    return data;
}

template<typename T>
int Node<T>::getPriority() const{
    return priority;
}

template<typename T>
Node<T>* Node<T>::getNext(){
    return next;
}

template<typename T>
void Node<T>::setNext(Node* n){
    next = n;
}
