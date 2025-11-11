// 4/11/2025
// Codigo hecho por Leonardo Martínez y Juan Eduardo Barrón

#pragma once
#include <iostream>
#include "SplayTree.h"

template<typename T>
SplayTree<T>::~SplayTree() {};

template<typename T>
bool SplayTree<T>::isEmpty() const{
    return root == nullptr;
}

template<typename T>
void SplayTree<T>::print(){
    if(isEmpty()){ 
        std::cout<<"El arbol esta vacio\n"; 
        return;
    }
    print(root);
    std::cout<<"\n";
}
        
template <typename T>
void SplayTree<T>::print(Node<T>* node) const {
    if (node == nullptr) return;
    std::cout<<"Nodo: "<< node->getData() <<" (Izq: ";
    if (node->getLeft()) std::cout << node->getLeft()->getData();
    else std::cout << "null";
    std::cout<<", Der: ";
    if (node->getRight()) std::cout << node->getRight()->getData();
    else std::cout << "null";
    std::cout << ")\n";
    print(node->getLeft());
    print(node->getRight());
}

template<typename T>  
Node<T>* SplayTree<T>::rotateRight(Node<T>* node){
    Node<T>* tmp = node->getLeft();
    Node<T>* tmp2 = tmp->getRight();
    tmp->setRight(node);
    node->setLeft(tmp2);
    return tmp;
}
        
template<typename T>  
Node<T>* SplayTree<T>::rotateLeft(Node<T>* node){
    Node<T>* tmp = node->getRight();
    Node<T>* tmp2 = tmp->getLeft();
    tmp->setLeft(node);
    node->setRight(tmp2);
    return tmp;
}

template<typename T>
void SplayTree<T>::insert(const T& value){
    if(isEmpty()){
        root = new Node<T>(value);
        return;
    }
    
    root = splay(root, value);
    
    if(root->getData() == value) return;
    
    Node<T>* newNode = new Node<T>(value);
    
    if(value < root->getData()){
        newNode->setRight(root);
        newNode->setLeft(root->getLeft());
        root->setLeft(nullptr);
    } else {
        newNode->setLeft(root);
        newNode->setRight(root->getRight());
        root->setRight(nullptr);
    }
    
    root = newNode;
}

template<typename T>
bool SplayTree<T>::deleteNode(const T& value){
    if(isEmpty()) return false;
    
    root = splay(root, value);
    
    if(root->getData() != value) return false;
    
    Node<T>* leftSubtree = root->getLeft();
    Node<T>* rightSubtree = root->getRight();
    
    delete root;
    
    if(leftSubtree == nullptr){
        root = rightSubtree;
        return true;
    }
    
    root = splay(leftSubtree, value); 
    root->setRight(rightSubtree);
    
    return true;
}


template<typename T>
void SplayTree<T>::clear(){
    clear(root);
    root = nullptr;
}

template<typename T> 
void SplayTree<T>::clear(Node<T>* node){
    if(!node) return;
    clear(node->getRight());
    clear(node->getLeft());
    delete node;
}

template<typename T>
Node<T>* SplayTree<T>::splay(Node<T>* root, const T& v) {
    if (root == nullptr || root->getData() == v)
        return root;

    // Izquierda
    if (v < root->getData()) {
        if (root->getLeft() == nullptr) 
            return root; 

        // Zig-Zig 
        if (v < root->getLeft()->getData()) {
            root->getLeft()->setLeft(splay(root->getLeft()->getLeft(), v));
            root = rotateRight(root);
        }
        // Zig-Zag 
        else if (v > root->getLeft()->getData()) {
            root->getLeft()->setRight(splay(root->getLeft()->getRight(), v));
            if (root->getLeft()->getRight() != nullptr)
                root->setLeft(rotateLeft(root->getLeft()));
        }

        return (root->getLeft() == nullptr) ? root : rotateRight(root);
    }

    // Caso derecha
    else {
        if (root->getRight() == nullptr) 
            return root; 

        // Zig-Zig 
        if (v > root->getRight()->getData()) {
            root->getRight()->setRight(splay(root->getRight()->getRight(), v));
            root = rotateLeft(root);
        }
        // Zig-Zag 
        else if (v < root->getRight()->getData()) {
            root->getRight()->setLeft(splay(root->getRight()->getLeft(), v));
            if (root->getRight()->getLeft() != nullptr)
                root->setRight(rotateRight(root->getRight()));
        }

        return (root->getRight() == nullptr) ? root : rotateLeft(root);
    }
}

template<typename T>
bool SplayTree<T>::search(const T& v) {
    root = splay(root, v);
    return (root != nullptr && root->getData() == v);
}