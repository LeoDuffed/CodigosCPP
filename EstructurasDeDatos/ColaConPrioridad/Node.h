#ifndef COLACONPRIORIDAD_H
#define COLACONPRIORIDAD_H

template <typename T>
class Node{
    private:
        T data;
        int priority;
        Node* next;
    public:
        T getData();
        int getPriority() const;
        Node* getNext();
        void setNext(Node* n);
        Node(const T& v, int p): data(v), priority(p), next(nullptr) {}
};

#include "Node.tpp"

#endif
