//
// Creado por Leonardo Martínez 
//
#ifndef NODE_H
#define NODE_H
template <typename T>
class Node {
public:
    T data;
    Node* next;
    Node(int k, const T& v);
    int key;
    void print();

};
#include "Node.tpp"
#endif //NODE_H
