// 4/11/2025
// Codigo hecho por Leonardo Martínez y Juan Eduardo Barrón

#ifndef NODE_H
#define NODE_H

template<typename T>
class Node{
    private: 
        T data;
        Node<T>* left;
        Node<T>* right;
        int height;
    public:
        Node (const T& v) : data(v), left (nullptr), right (nullptr), height(1) {}
        T getData();
        Node<T>* getLeft();
        Node<T>* getRight();
        int getHeight() const;
        void setData(const T& v);
        void setRight(Node<T>* right);
        void setLeft (Node<T>* left);
};

#include "Node.tpp"

#endif