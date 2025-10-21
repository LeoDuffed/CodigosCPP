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
        // Rotaciones
        Node<T>* rotateRight(Node<T>* node);
        Node<T>* rotateLeft(Node<T>* node);
        Node<T>* rotateLeftRight(Node<T>* node); // rotacion doble a la derecha
        Node<T>* rotateRightLeft(Node<T>* node); // rotacion doble a la izquierda
        // Insertar y Eliminar
        Node<T>* insert(Node<T>* node, const T& value);
        Node<T>* remove(Node<T>* node, const T& value);
        void destroy(Node<T>* node); // limpia cosillas
    public:
        AVL(): root(nullptr) {}
        ~AVL();
        void clear();
        void print();
        void insert(const T& value);

};

#include "AVL.tpp"

#endif