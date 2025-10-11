#pragma once
#include <iostream>

template<typename T>
BST<T>::BST(): root(nullptr){}

template<typename T>
BST<T>::~BST(){
    clear();
}

template<typename T>
bool BST<T>::isEmpty() const{
    return root == nullptr;
}

template<typename T>
void BST<T>::print(){

}

template<typename T>
void BST<T>::clear(Node<T>* n){
    if(!n) return;
    clear(n->getRight());
    clear(n->getLeft());
    delete n;
}

template<typename T>
void BST<T>::clear(){
    clear(root);
    root = nullptr;
}

template<typename T>
void BST<T>::insert(const T& v){
    Node<T>* newNode = new Node<T>(v);
    if(isEmpty()){
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
}

template<typename T>
bool BST<T>::search(Node<T>* root, const T& v) const{
    if(isEmpty()){
        return false;
    }
    std::cout<<"Visitando: "<<root->getData()<<std::endl;
    if(v == root->getData()){
        return true;
    }
    if(v < root->getData()){
        std::cout<<"Moviendo izquierda"<<std::endl;
        return search(root->getLeft(), v);
    } else {
        std::cout<<"Moviendo derecha"<<std::endl;
        return search(root->getRight(), v);
    }
}

template<typename T>
bool BST<T>::search(const T& v) const{
    return search(root, v);
}