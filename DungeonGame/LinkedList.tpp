#pragma once
#include "LinkedList.h"

template<typename T>
LinkedList<T>::LinkedList():head(nullptr), n(0){}

template<typename T>
LinkedList<T>::~LinkedList() {
    NeighborList<T>* current=head;
    while (current) {
        NeighborList<T>* nxt = current->next;
        delete current;
        current = nxt;
    }
    head = nullptr;
    n = 0;
}

template<typename T>
bool LinkedList<T>::empty() const {
    return n==0;
}

template<typename T>
int LinkedList<T>::size() const{
    return n;
}

template<typename T>
void LinkedList<T>::pushBack(const T &value) {
    NeighborList<T>* newNode= new NeighborList<T>(value);
    if (!head) {
        head= newNode;
    }else {
        NeighborList<T>* current= head;
        while (current->next) {
            current= current->next;
        }
        current->next= newNode;
    }
    ++n;
}

template<typename T>
NeighborList<T>* LinkedList<T>::getHead() const{
    return head;
}

template<typename T>
NeighborList<T>* LinkedList<T>::search(const T& value) const{
    NeighborList<T>* current = head;
    while (current) {
        if (current->data == value) {
            return current;
        }
        current= current->next;
    }
    return nullptr;
}
