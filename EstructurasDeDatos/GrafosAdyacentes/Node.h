#ifndef NODE_H
#define NODE_H
template <typename T>
class Node {
public:
    T data;
    Node* next;
    Node(const T& v);

};
#include "Node.tpp"
#endif //NODE_H
