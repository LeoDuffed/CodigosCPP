#pragma once
#include "Stack.h"
#include <iostream>
#include <stdexcept>
using namespace std;


// Cambio: corregir las operaciones de la pila y validar casos vacíos.

template <typename T>
void Stack<T>::push(const T& v){
    Node<T>* newNode = new Node<T>(v);
    newNode->next = topNode;
    topNode = newNode;
    ++count;
}

template <typename T>
T Stack<T>::pop(){
    if(isEmpty()){
        throw std::underflow_error("Stack vacio");
    }
    Node<T>* tmp = topNode; // Para no perder la referencia
    topNode = topNode->next;
    T returnValue = tmp->data;
    delete tmp;
    --count;
    return returnValue;      
}

template <typename T>
T Stack<T>::top(){
    if(isEmpty()){
        throw std::underflow_error("Stack vacio");
    }
    return topNode->data;
}

template <typename T>
bool Stack<T>::isEmpty() const{
    return count == 0;
}

template <typename T>
void Stack<T>::print() const{
    if (isEmpty()) {
        std::cout<<"Lista vacia!"<<std::endl;
        return;
    }

    // Cambio: recorrer desde topNode para mostrar el contenido.
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
