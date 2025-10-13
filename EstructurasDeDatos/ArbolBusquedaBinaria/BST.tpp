// 
// Creado por Leonardo Martínez 10/10/25
//

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

/*
    Usamos esta funcione en el metodo print() para calcular
    el número máximo de nodos posibles en un nivel del árbol y
    asi conseguimos la cantidad de espacios necesarios para alinear
    los nodos de forma simétrica cuando imrpimamos el árbol.
*/
template<typename T>
int BST<T>::powersOfTwo(int h){
    int p = 1;
    for (int i = 0; i < h; ++i) p *= 2; 
    return p;
}

template<typename T>
int BST<T>::height(Node<T>* n) const{
    if(!n) return 0;
    int heightLeft = height(n->getLeft());
    int heightRight = height(n->getRight());
    if(heightLeft > heightRight) return 1 + heightLeft;
    else return 1 + heightRight;
}

template<typename T>
void BST<T>::print(){
    if(isEmpty()){
        std::cout<<"Esta vaci el arbol\n";
        return;
    }
    int h = height(root);
    int maxNodes = powersOfTwo(h);
    Node<T>** actualLevel = new Node<T>*[maxNodes];
    Node<T>** nextLevel = new Node<T>*[maxNodes];
    // Nivel 0
    actualLevel[0] = root;
    int actualNum = 1;
    // Recorremos cada nivel
    for(int i = 0; i < h; ++i){
        // Hay que calcular los espacios entre nodos
        int initialSpaces;
        if(h - i - 2 >= 0) initialSpaces = powersOfTwo(h - i - 2) - 1;
        else initialSpaces = 0;
        int betwenSpaces;
        if(h - i - 1 >= 0) betwenSpaces = powersOfTwo(h - i - 1) -1;
        else if (betwenSpaces < 1) betwenSpaces = 1;
        // Espacios iniciales
        for(int n = 0; n < initialSpaces; ++n) std::cout<<" ";
        int nextNum = 0;
        for(int j = 0; j < actualNum; ++j){
            if(actualLevel[j]){
                std::cout<<actualLevel[j]->getData();
                nextLevel[nextNum++] = actualLevel[j]->getLeft();
                nextLevel[nextNum++] = actualLevel[j]->getRight(); 
            } else {
                std::cout<<" ";
                nextLevel[nextNum++] = nullptr;
                nextLevel[nextNum++] = nullptr;
            }
            // Espacios entre los nodos
            if(j != actualNum - 1) for(int n = 0; n < betwenSpaces; ++n) std::cout<<" ";
        }
        std::cout<<"\n";
        // Pasamos al siguiente nivel "actual"
        for(int j = 0; j < nextNum; ++j) actualLevel[j] = nextLevel[j];
        actualNum = nextNum;
    }
    delete[] actualLevel;
    delete[] nextLevel;
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
        if(v < tmp->getData()) tmp = tmp->getLeft();
        else if (v > tmp->getData()) tmp = tmp->getRight();
        else {
            delete newNode;
            return;
        }
    }
    if(v < parent->getData()) parent->setLeft(newNode);
    else parent->setRight(newNode);
}

template<typename T>
bool BST<T>::search(Node<T>* root, const T& v) const{
    if(isEmpty()) return false;
    if(v == root->getData()) return true;
    if(v < root->getData()){
        return search(root->getLeft(), v);
    } else {
        return search(root->getRight(), v);
    }
}

template<typename T>
bool BST<T>::search(const T& v) const{
    return search(root, v);
}