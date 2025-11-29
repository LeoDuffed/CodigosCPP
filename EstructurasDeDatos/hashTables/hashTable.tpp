#pragma once
#include "hashTable.h"
#include <iostream>
using namespace std;

template <typename T>
int HashTable<T>::hashFunction(const string& key) const {
    int hash = 0;
    for (unsigned int i = 0; i < key.length(); i++) {
        hash += key[i];
    }
    return hash % TABLE_SIZE;
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
        while(current != nullptr){
            Node<T>* tmp = current;
            current = current->next;
            delete tmp;
        }
        table[i] = nullptr;
    }
}

template<typename T>
void HashTable<T>::insert(const string& key, const T& value){
    int hashKey = hashFunction(key);
    int index = hashKey;
    Node<T>* current = table[index];
    // Guardamos la matricula + el nombre, asi los imprimimos junticos
    string combinado = key + " - " + value;
    while(current != nullptr){
        if(current->key == hashKey){
            current->data = combinado;
            return;
        }
        current = current->next;
    }
    // se inserta al inicio de la lista ligada
    Node<T>* newNode = new Node<T>(hashKey, combinado);
    newNode->next = table[index];
    table[index] = newNode;
}

template<typename T>
void HashTable<T>::remove(const string& key){
    int hashKey = hashFunction(key);
    int index = hashKey;
    Node<T>* current = table[index];
    Node<T>* prev = nullptr;
    while(current != nullptr && current->key != hashKey){
        prev = current;
        current = current->next;
    }
    if(current == nullptr){
        return;
    }
    if(prev == nullptr){
        table[index] = current->next;
    } else {
        prev->next = current->next;
    }
    delete current;
}

template<typename T>
void HashTable<T>::printTable() const{
    for(int i = 0; i < TABLE_SIZE; i++){
        Node<T>* current = table[i];
        if(i < 9){
            cout<<i+1<<":  ";
        } else {
            cout<<i+1<<": ";
        }
        if(table[i] != nullptr){
            cout<<"[ (";
        } else {
            cout<<"[ Vacio ";
        }
        while(current != nullptr){
            current->print();
            if(current->next != nullptr){
                cout<<" -> ";
            }
            current = current->next;
            cout<<" ) ";
        }
        cout<<"]"<<endl;
    }
}

template<typename T>
T* HashTable<T>::search(const string& key){
    int hashKey = hashFunction(key);
    int index = hashKey;
    Node<T>* current = table[index];
    while(current != nullptr && current->key != hashKey){
        current = current->next;
    }
    if(current != nullptr){
        return &(current->data);
    }
    return nullptr;
}
