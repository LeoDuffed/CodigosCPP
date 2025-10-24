#pragma once
#include <iostream>
#include "AVL.h"

template<typename T>
bool AVL<T>::isEmpty() const{
    return root == nullptr;
}

template<typename T>
AVL<T>::~AVL(){}

template<typename T>        
int AVL<T>::height(Node<T>* n) const{
    return n ? n->getHeight() : 0;
}

template<typename T>  
int AVL<T>::balanceFac(Node<T>* n)const{
    if(!n) return 0;
    return height(n->getLeft()) - height(n->getRight());
}

template<typename T>  
int AVL<T>::maxValue(int a, int b) const{
    return (a > b) ? a : b;
}

template<typename T>
void AVL<T>::print(){
    if(isEmpty()){ 
        std::cout<<"El arbol esta vacio\n"; 
        return;
    }
    print(root);
    std::cout<<"\n";
}
        
template <typename T>
void AVL<T>::print(Node<T>* node) const {
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
Node<T>* AVL<T>::rotateRight(Node<T>* node){
    Node<T>* tmp = node->getLeft();
    Node<T>* tmp2 = tmp->getRight();
    tmp->setRight(node);
    node->setLeft(tmp2);
    node->setHeight(1 + maxValue(height(node->getLeft()), height(node->getRight())));
    tmp->setHeight(1 + maxValue(height(tmp->getRight()), height(tmp->getLeft())));
    return tmp;
}
        
template<typename T>  
Node<T>* AVL<T>::rotateLeft(Node<T>* node){
    Node<T>* tmp = node->getRight();
    Node<T>* tmp2 = tmp->getLeft();
    tmp->setLeft(node);
    node->setRight(tmp2);
    node->setHeight(1 + maxValue(height(node->getLeft()), height(node->getRight())));
    tmp->setHeight(1 + maxValue(height(tmp->getRight()), height(tmp->getLeft())));
    return tmp;
}
        
template<typename T>  
Node<T>* AVL<T>::rotateLeftRight(Node<T>* node){
    node->setLeft(rotateLeft(node->getLeft()));
    return rotateRight(node);
}

template<typename T>  
Node<T>* AVL<T>::rotateRightLeft(Node<T>* node){
    node->setRight(rotateRight(node->getRight()));
    return rotateLeft(node);
}

template<typename T>  
Node<T>* AVL<T>::insert(Node<T>* node, const T& value){
    if(!node) return new Node<T>(value);

    if(value < node->getData()) node->setLeft(insert(node->getLeft(), value));
    else if( value > node->getData()) node->setRight(insert(node->getRight(), value));
    else return node;

    node->setHeight(1 + maxValue(height(node->getLeft()), height(node->getRight())));
    const int bf = balanceFac(node);
    if(bf > 1 && value < node->getLeft()->getData()){
        return rotateRight(node);
    } else if(bf < -1 && value > node->getRight()->getData()){
        return rotateLeft(node);
    } else if(bf > 1 && value > node->getLeft()->getData()){
        return rotateLeftRight(node);
    } else if(bf < -1 && value < node->getRight()->getData()){
        return rotateRightLeft(node);
    }
    return node;
}

template<typename T>
void AVL<T>::insert(const T& value){
    root = insert(root ,value);
}

template<typename T>
Node<T>* AVL<T>::smallestNode(Node<T>* node) const{
    if(!node) return nullptr;
    Node<T>* n = node;
    while(n->getLeft() != nullptr) n = n->getLeft();
    return n;
}

template<typename T>
bool AVL<T>::deleteNode(const T& v){
    bool removed = false;
    root = deleteNode(root, v, removed);
    return removed;
}

template<typename T>  
Node<T>* AVL<T>::deleteNode(Node<T>* node, const T& v, bool& removed){
    if(!node) return nullptr;
    if(v < node->getData()){
        node->setLeft(deleteNode(node->getLeft(), v, removed));
    } else if(v > node->getData()){
        node->setRight(deleteNode(node->getRight(), v, removed));
    } else {
        removed = true;
        Node<T>* left = node->getLeft();
        Node<T>* right = node->getRight();
        // Quitar hoja
        if(!left && !right){
            delete node;
            return nullptr;
        }
        // Un solo hijo
        if(!left && right){ // solo hijo derecho
            Node<T>* tmp = right;
            delete node;
            return tmp;
        }
        if(left && !right){ // solo hijo izquierdo
            Node<T>* tmp = left;
            delete node;
            return tmp;
        }
        // Dos hijos
        Node<T>* successor = smallestNode(right);
        node->setData(successor->getData());
        bool tmp = false;
        node->setRight(deleteNode(right, successor->getData(), tmp));
    }

    // Nueva altura y balancear
    node->setHeight(1 + maxValue(height(node->getLeft()), height(node->getRight())));
    const int bf = balanceFac(node);
    if(bf > 1){
        if(balanceFac(node->getLeft()) >= 0) return rotateRight(node);   
        else return rotateLeftRight(node);                               
    }
    if(bf < -1){
        if(balanceFac(node->getRight()) <= 0) return rotateLeft(node);   
        else return rotateRightLeft(node);                               
    }
    return node;
}

template<typename T>
void AVL<T>::clear(){

}

template<typename T>  // metodo priv
void AVL<T>::clear(Node<T>* node){

}

template<typename T>
bool AVL<T>::searchPath(Node<T>* root, const T& v) const{
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
bool AVL<T>::searchPath(const T& v) const{
    return searchPath(root, v);
}
