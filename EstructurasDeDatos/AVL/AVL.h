#ifndef AVL_H
#define AVL_H
#include "Node.h"

template<typename T>
class AVL{
    private:
        Node<T>* root;
        // Metodos utiles
        bool isEmpty() const;   
        int height(Node<T>* n) const;
        int balanceFac(Node<T>* n)const;
        int maxValue(int a, int b) const;
        void print(Node<T>* node) const;
        bool search(Node<T>* root, const T& v) const;
        // Rotaciones
        Node<T>* rotateRight(Node<T>* node);
        Node<T>* rotateLeft(Node<T>* node);
        Node<T>* rotateLeftRight(Node<T>* node); // rotacion doble a la derecha
        Node<T>* rotateRightLeft(Node<T>* node); // rotacion doble a la izquierda
        // Insertar y Eliminar
        Node<T>* insert(Node<T>* node, const T& value);
        Node<T>* deleteNode(Node<T>* node, const T& value, bool& removed);
        Node<T>* smallestNode(Node<T>* node) const;
        void clear(Node<T>* node); // limpiar arbol completo
    public:
        AVL(): root(nullptr) {}
        ~AVL();
        void clear();
        bool deleteNode(const T& v);
        void print();
        void insert(const T& value);
        bool search(const T& node) const;
};

#include "AVL.tpp"

#endif