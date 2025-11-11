// 4/11/2025
// Codigo hecho por Leonardo Martínez y Juan Eduardo Barrón

#ifndef SPLAYTREE_H
#define SPLAYTREE_H

#include "Node.h"

template <typename T>
class SplayTree {
        Node<T>* root;
        bool isEmpty() const;   
        void print(Node<T>* node) const;
        Node<T>* rotateRight(Node<T>* node);
        Node<T>* rotateLeft(Node<T>* node);
        void clear(Node<T>* node); 
        Node<T>* splay(Node<T>* root, const T& v);

    public:
        SplayTree(): root(nullptr) {}
        ~SplayTree();
        void clear();
        bool deleteNode(const T& v);
        void print();
        void insert(const T& value);
        bool search(const T& v);


};

#include "SplayTree.tpp"

#endif