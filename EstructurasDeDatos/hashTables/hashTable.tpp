#pragma once
#include "hashTable.h"
#include <iostream>
using namespace std;

template<typename T>
int HashTable<T>::hashFunction(int key) const{
    return key%TABLE_SIZE;
}

template<typename T>
HashTable<T>::HashTable(){
    for(int i = 0; i < TABLE_SIZE; i++){
        table[i] = nullptr;
    }
}


template<typename T>
HashTable<T>::~HashTable(){
    for(int i = 0; i < TABLE_SIZE; i++){
        Node<T>* current = table[i];
        while(current!= nullptr){
            Node<T>* tmp = current;

        }
    }
}

template<typename T>
void HashTable<T>::insert(int key, T value){
    int index = hashFunction(key);
    Node<T>* current = table[index];
    cout<<"Corresponde al indice: "<<index<<endl;
    while(current != nullptr){
        if(current->key == 0){
            current->data = value;
            return;
        }
        current = current->next;
    }
    // se inserta el inicio de la lista ligada
    Node<T>* newNode = new Node<T>(key, value);
    newNode->next = table[index];
    table[index] = newNode;
}

template<typename T>
void HashTable<T>::printTable() const{
    for(int i = 0; i < TABLE_SIZE; i++){
        Node<T>* current = table[i];
        cout<<i<<": ";
        if(table[i] != nullptr){
            cout<<"["<<table[i]->key<<" -> ";
        } else {
            cout<<"[ Vacio ";
        }
        while(current != nullptr){
            current->print();
            current = current->next;
        }
        cout<<"]"<<endl;
    }
}

template<typename T>
T& HashTable<T>::search(int key){
    int index = hashFunction(key);
    Node<T>* current = table[index];
    while(current->key != key && current != nullptr){
        current = current->next;
    }
    if(current != nullptr){
        return current->data;
    }
    return nullptr;
}