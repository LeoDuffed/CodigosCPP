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
        bool ancestors(Node<T>* node, const T& v) const;
        int whatLevelAmI(Node<T>* node, const T& v, int level) const;
        void visit(Node<T>* node) const;
        void inOrder(Node<T>* node) const;
        void postOrder(Node<T>* node) const;
        void preOrder(Node<T>* node) const;
        Node<T>* deleteNode(Node<T>* node, const T& v, bool& removed);
        Node<T>* smallestNode(Node<T>* node) const;

    public:
        BST();
        ~BST();
        bool isEmpty() const;
        void print();
        void clear();
        void insert(const T& v);
        bool search(const T& v) const;
        void ancestors(const T& v) const;
        int whatLevelAmI(const T& v) const;
        void inOrder() const;
        void postOrder() const;
        void preOrder() const;
        bool deleteNode(const T& v);
}; 

#include "BST.tpp"

#endif