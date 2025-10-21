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
        std::cout<<"El arbol esta vacio\n";
        return;
    }
    printNodes(root);
    std::cout<<"\n";
}

template<typename T>
void BST<T>::printNodes(Node<T>* node) const{
    if(!node) return;
    printNodes(node->getLeft());
    std::cout<<node->getData()<<" ";
    printNodes(node->getRight());
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
    if(root == nullptr) return false;
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

template<typename T>
void BST<T>::visit(Node<T>* node) const{
    std::cout<<"Visitando: "<<node->getData()<<"\n";
}

template<typename T>
bool BST<T>::ancestors(Node<T>* node, const T& v) const{
    if(!node) return false;
    if(node->getData() == v) return true;
    if(v < node->getData()){
        if(ancestors(node->getLeft(), v)){
            std::cout<<node->getData()<<" ";
            return true;
        }
    } else {
        if(ancestors(node->getRight(), v)){
            std::cout<<node->getData()<<" ";
            return true;
        }
    }
    return false;
}

template<typename T>
void BST<T>::ancestors(const T& v) const{
    if(isEmpty()){
        std::cout<<"Arbol vacio\n";
        return;
    }
    bool found = ancestors(root, v);
    if(!found) std::cout<<"No se econtro el valor: "<<v<<"\n";
    else std::cout<<"\n";
}

template<typename T>
int BST<T>::whatLevelAmI(Node<T>* node, const T& v, int level) const{
    if(!node) return -1;
    if(node->getData() == v) return level;
    if(v < node->getData()) return whatLevelAmI(node->getLeft(), v, level + 1);
    else return whatLevelAmI(node->getRight(), v, level + 1);
}

template<typename T>
int BST<T>::whatLevelAmI(const T& v) const{
    return whatLevelAmI(root, v, 0);
}

template<typename T>
void BST<T>::inOrder() const{
    inOrder(root);
}

template<typename T>
void BST<T>::inOrder(Node<T>* node) const{
    if(node == nullptr) return;
    inOrder(node->getLeft());
    visit(node);
    inOrder(node->getRight());
}

template<typename T>
void BST<T>::postOrder() const{
    postOrder(root);
}

template<typename T>
void BST<T>::postOrder(Node<T>* node) const{
    if(node == nullptr) return;
    postOrder(node->getLeft());
    postOrder(node->getRight());
    visit(node);
}

template<typename T>
void BST<T>::preOrder() const{
    preOrder(root);
}

template<typename T>
void BST<T>::preOrder(Node<T>* node) const{
    if(node == nullptr) return;
    visit(node);
    preOrder(node->getLeft());
    preOrder(node->getRight());
}

template<typename T>
Node<T>* BST<T>::smallestNode(Node<T>* node) const{
    if(!node) return nullptr;
    Node<T>* n = node;
    while(n->getLeft() != nullptr) n = n->getLeft();
    return n;
}

template<typename T>
bool BST<T>::deleteNode(const T& v){
    bool removed = false;
    root = deleteNode(root, v, removed);
    return removed;
}

template<typename T>
Node<T>* BST<T>::deleteNode(Node<T>* node, const T& v, bool& removed){
    if(!node) return nullptr;
    if(v < node->getData()){
        node->setLeft(deleteNode(node->getLeft(), v, removed));
        return node;
    } else if(v > node->getData()){
        node->setRight(deleteNode(node->getRight(), v, removed));
        return node;
    }
    removed = true;
    Node<T>* left = node->getLeft();
    Node<T>* right = node->getRight();
    // Quitar hoja (sin hijos)
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
    return node;
}
