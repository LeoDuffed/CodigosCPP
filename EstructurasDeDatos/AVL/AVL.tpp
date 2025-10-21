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
        
template<typename T>  
void AVL<T>::print(Node<T>* node) const{
    if(!node) return;
    print(node->getLeft());
    std::cout<<node->getData()<<" ";
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
Node<T>* AVL<T>::remove(Node<T>* node, const T& value){

}

template<typename T>  
void AVL<T>::destroy(Node<T>* node){

}
