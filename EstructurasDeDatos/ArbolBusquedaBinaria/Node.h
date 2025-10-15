// 
// Creado por Leonardo Martínez 10/10/25
//

#ifndef NODE_H
#define NODE_H

template <typename T>
class Node{
    private:
        T data;
        Node<T>* left;
        Node<T>* right;
    public:
        Node(const T& v): data(v), left(nullptr), right(nullptr){}
        Node<T>* getLeft();
        void setLeft(Node<T>* node);
        Node<T>* getRight();
        void setRight(Node<T>* node);
        T getData();
        void setData(const T& v);
};

#include "Node.tpp"

#endif