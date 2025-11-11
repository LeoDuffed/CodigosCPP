// 4/11/2025
// Codigo hecho por Leonardo Martínez y Juan Eduardo Barrón

#ifndef SPLAYTREE_H
#define SPLAYTREE_H

#include "Node.h"

template <typename T>
class SplayTree {
        Node<T>* root;
        // Metodos utiles
        bool isEmpty() const;   
        int height(Node<T>* n) const;
        int maxValue(int a, int b) const;
        void print(Node<T>* node) const;
        bool searchPath(Node<T>* root, const T& v) const;
        // Rotaciones
        Node<T>* rotateRight(Node<T>* node);
        Node<T>* rotateLeft(Node<T>* node);
        // Insertar y Eliminar
        Node<T>* smallestNode(Node<T>* node) const;
        void clear(Node<T>* node); 
        Node<T>* rotateLeftRight(Node<T>* node);
        Node<T>* rotateRightLeft(Node<T>* node);
        Node<T>* search(Node<T>* root, const T& v);
        Node<T>* splay(Node<T>* root, const T& v);

    public:
        SplayTree(): root(nullptr) {}
        ~SplayTree();
        void clear();
        bool deleteNode(const T& v);
        void print();
        void insert(const T& value);
        bool searchPath(const T& node) const;
        bool search(const T& v);


};

#include "SplayTree.tpp"

#endif