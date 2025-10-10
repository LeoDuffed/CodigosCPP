#pragma once
#include "Queue.h"
#include <iostream>
#include <stdexcept>

template <typename T>
void Queue<T>::enQueue(const T& v){
    Node<T>* newNode = new Node<T>(v);
    if (isEmpty()) {
        topNode = firstNode = newNode;
    } else {
        firstNode->next = newNode;
        firstNode = newNode;
    }
    ++count;
}

template <typename T>
T Queue<T>::deQueue(){
    if (isEmpty()) {
        cout<<"La cola esta vacia"
    }

    Node<T>* tmp = topNode;
    topNode = topNode->next;
    if (topNode == nullptr) {
        firstNode = nullptr;
    }

    T returnValue = tmp->data;
    delete tmp;
    --count;
    return returnValue;
}

template <typename T>
int Queue<T>::front(){
    if(isEmpty()){
        cout<<"La cola esta vacia"<<endl;
    } else {
        return topNode->data;
    }
}

template <typename T>
bool Queue<T>::isEmpty() const {
    return count == 0;
}

template <typename T>
void Queue<T>::print() const{
    if (isEmpty()) {
        std::cout<<"Lista vacia!"<<std::endl;
        return;
    }

    const Node<T>* current = topNode;
    std::cout<<"[";
    bool first = true;
    while (current) {
        if (!first) {
            std::cout<<" ->";
        }
        std::cout<<" "<<current->data;
        first = false;
        current = current->next;
    }
    std::cout<<" ]"<<std::endl;
}