#ifndef SPLAYTREE_H
#define SPLAYTREE_H

#include "Node.h"

template <typename T>
class SplayTree {
        Node<T>* root;
        // Metodos utiles
        bool isEmpty() const;   
        int height(Node<T>* n) const;
        int balanceFac(Node<T>* n)const;
        int maxValue(int a, int b) const;
        void print(Node<T>* node) const;
        bool searchPath(Node<T>* root, const T& v) const;
        // Rotaciones
        Node<T>* rotateRight(Node<T>* node);
        Node<T>* rotateLeft(Node<T>* node);
        // Insertar y Eliminar
        Node<T>* insert(Node<T>* node, const T& value);
        Node<T>* deleteNode(Node<T>* node, const T& value, bool& removed);
        Node<T>* smallestNode(Node<T>* node) const;
        void clear(Node<T>* node); // limpiar arbol completo
        Node<T>* rotateLeftRight(Node<T>* node); // rotacion doble a la derecha
        bool search(Node<T>* root, const T& v) const;
        Node<T>* rotateRightLeft(Node<T>* node); // rotacion doble a la izquierda
        bool search(Node<T>* root, const T& v) const;
    public:
        SplayTree(): root(nullptr) {}
        ~SplayTree();
        void clear();
        bool deleteNode(const T& v);
        void print();
        void insert(const T& value);
        bool searchPath(const T& node) const;
        bool search(const T& v) const;


};

#endif