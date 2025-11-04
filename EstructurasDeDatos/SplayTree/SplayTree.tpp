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
int SplayTree<T>::height(Node<T>* n) const{
    return n ? n->getHeight() : 0;
}

template<typename T>  
int SplayTree<T>::maxValue(int a, int b) const{
    return (a > b) ? a : b;
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
    node->setHeight(1 + maxValue(height(node->getLeft()), height(node->getRight())));
    tmp->setHeight(1 + maxValue(height(tmp->getRight()), height(tmp->getLeft())));
    return tmp;
}
        
template<typename T>  
Node<T>* SplayTree<T>::rotateLeft(Node<T>* node){
    Node<T>* tmp = node->getRight();
    Node<T>* tmp2 = tmp->getLeft();
    tmp->setLeft(node);
    node->setRight(tmp2);
    node->setHeight(1 + maxValue(height(node->getLeft()), height(node->getRight())));
    tmp->setHeight(1 + maxValue(height(tmp->getRight()), height(tmp->getLeft())));
    return tmp;
}
        
template<typename T>  
Node<T>* SplayTree<T>::rotateLeftRight(Node<T>* node){
    node->setLeft(rotateLeft(node->getLeft()));
    return rotateRight(node);
}

template<typename T>  
Node<T>* SplayTree<T>::rotateRightLeft(Node<T>* node){
    node->setRight(rotateRight(node->getRight()));
    return rotateLeft(node);
}

template<typename T>
void SplayTree<T>::insert(const T& value){
    if(isEmpty()){
        root = new Node<T>(value);
        return;
    }
    
    // Primero hacemos splay del valor
    // Si existe, quedará en la raíz y no insertamos
    // Si no existe, el nodo más cercano quedará en la raíz
    root = splay(root, value);
    
    // Si el valor ya existe, no hacemos nada
    if(root->getData() == value) return;
    
    // Creamos el nuevo nodo
    Node<T>* newNode = new Node<T>(value);
    
    // Dividimos el árbol en dos según el valor
    if(value < root->getData()){
        // El nuevo nodo va a la izquierda
        newNode->setRight(root);
        newNode->setLeft(root->getLeft());
        root->setLeft(nullptr);
    } else {
        // El nuevo nodo va a la derecha
        newNode->setLeft(root);
        newNode->setRight(root->getRight());
        root->setRight(nullptr);
    }
    
    // El nuevo nodo se convierte en la raíz
    root = newNode;
}

template<typename T>
Node<T>* SplayTree<T>::smallestNode(Node<T>* node) const{
    if(!node) return nullptr;
    Node<T>* n = node;
    while(n->getLeft() != nullptr) n = n->getLeft();
    return n;
}

template<typename T>
bool SplayTree<T>::deleteNode(const T& value){
    if(isEmpty()) return false;
    
    // Hacemos splay del nodo a eliminar
    root = splay(root, value);
    
    // Si el nodo no existe, no hacemos nada
    if(root->getData() != value) return false;
    
    // Guardamos los subárboles
    Node<T>* leftSubtree = root->getLeft();
    Node<T>* rightSubtree = root->getRight();
    
    // Eliminamos el nodo raíz
    delete root;
    
    // Si no hay subárbol izquierdo, la nueva raíz es el subárbol derecho
    if(leftSubtree == nullptr){
        root = rightSubtree;
        return true;
    }
    
    // Si hay subárbol izquierdo, hacemos splay del máximo elemento
    // para que no tenga hijo derecho, luego le agregamos el subárbol derecho
    root = splay(leftSubtree, value); // Esto llevará el máximo a la raíz
    root->setRight(rightSubtree);
    
    return true;
}


template<typename T>
void SplayTree<T>::clear(){
    clear(root);
    root = nullptr;
}

template<typename T>  // metodo priv
void SplayTree<T>::clear(Node<T>* node){
    if(!node) return;
    clear(node->getRight());
    clear(n->getLeft());
    delete node;
}

template<typename T>
bool SplayTree<T>::searchPath(Node<T>* root, const T& v) const{
    if(root == nullptr) return false;
    if(root == this->root) std::cout<<root->getData();
    else std::cout<<" - "<<root->getData();
    if(v == root->getData()){ 
        std::cout<<"\n";
        return true; 
    }
    if(v < root->getData()){
        if(root->getLeft() == nullptr) {
            std::cout<<" - Not Found\n";
            return false;
        }
        return searchPath(root->getLeft(), v);
    } else {
        if(root->getRight() == nullptr){
            std::cout<<" - Not Found\n";
            return false;
        }
        return searchPath(root->getRight(), v);
    }
}

template<typename T>
bool SplayTree<T>::searchPath(const T& v) const{
    return searchPath(root, v);
}

template<typename T>
Node<T>* SplayTree<T>::splay(Node<T>* root, const T& v) {
    if (root == nullptr || root->getData() == v)
        return root;

    // Caso Izquierda
    if (v < root->getData()) {
        if (root->getLeft() == nullptr) 
            return root; // No existe, devuelve el más cercano

        // Zig-Zig (izquierda-izquierda)
        if (v < root->getLeft()->getData()) {
            root->getLeft()->setLeft(splay(root->getLeft()->getLeft(), v));
            root = rotateRight(root);
        }
        // Zig-Zag (izquierda-derecha)
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
            return root; // No existe, devuelve el más cercano

        // Zig-Zig (derecha-derecha)
        if (v > root->getRight()->getData()) {
            root->getRight()->setRight(splay(root->getRight()->getRight(), v));
            root = rotateLeft(root);
        }
        // Zig-Zag (derecha-izquierda)
        else if (v < root->getRight()->getData()) {
            root->getRight()->setLeft(splay(root->getRight()->getLeft(), v));
            if (root->getRight()->getLeft() != nullptr)
                root->setRight(rotateRight(root->getRight()));
        }

        return (root->getRight() == nullptr) ? root : rotateLeft(root);
    }
}


template<typename T>
Node<T>* SplayTree<T>::search(Node<T>* root, const T& v) {
    if (root == nullptr) return nullptr;

    root = splay(root, v);  // mueve el nodo v (o el más cercano) a la raíz
    if (root->getData() == v)
        return root;
    else
        return nullptr;
}

template<typename T>
bool SplayTree<T>::search(const T& v) {
    root = splay(root, v);
    return (root != nullptr && root->getData() == v);
}