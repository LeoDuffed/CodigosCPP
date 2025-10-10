#pragma once
#include "BST.h"
#include <iostream>
using namespace std;

template<typename T>
bool BST<T>::isEmpty() const{

}

template<typename T>
void BST<T>::print(){

}

template<typename T>
void BST<T>::clear(){

}

template<typename T>
void BST<T>::insert(const T& v){
    Node<T>* newNode = new Node<T>(v);
    if(root == nullptr){
        root = newNode;
        return;
    }
    Node<T>* tmp = root;
    Node<T>* parent = nullptr;
    while(tmp != nullptr){
        parent = tmp;
        if(v < tmp->getData()){
            tmp = tmp->getLeft();
        } else if (v > tmp->getData()){
            tmp = tmp->getRight();
        } else {
            delete newNode;
            return;
        }
    }
    if(v < parent->getData()){
        parent->setLeft(newNode);
    } else {
        parent->setRight(newNode);
    }
    delete tmp;
}

template<typename T>
bool BST<T>::search(const T& v) const{
    return searchRec(root, v);
}

template<typename T>
bool BST<T>::searchRec(Node<T>* root, const T& v){
    if(root == nullptr){
        return false;
    }
    cout<<"Visitando: "<<root->getData();
    if(v == root->getData()){
        return true;
    }
    if(v < root->getData()){
        return search(root->getLeft(), v);
    } else {
        return search(root->getRight(), v);
    }
}