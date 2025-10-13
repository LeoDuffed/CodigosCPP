// 
// Creado por Leonardo Martínez 10/10/25
//

#ifndef BST_H
#define BST_H
#include <iostream>

template<typename T>
class BST{
    private:
        Node<T>* root;
        bool search(Node<T>* root, const T& v) const;
        void clear(Node<T>* n);
        int height(Node<T>* n) const;
        int powersOfTwo(int h);
    public:
        BST();
        ~BST();
        bool isEmpty() const;
        void print();
        void clear();
        void insert(const T& v);
        bool search(const T& v) const;
}; 

#include "BST.tpp"

#endif