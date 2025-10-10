#ifndef BST_H
#define BST_H
#include <iostream>

template<typename T>
class BST{
    private:
        Node<T>* root;
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