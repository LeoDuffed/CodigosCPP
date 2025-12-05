#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "NeighborNode.h"

template <typename T>
class LinkedList {
private:
    NeighborNode<T>* head;
    int n;
public:
    LinkedList();
    ~LinkedList();
    int size() const;
    void pushBack(const T& value);
    NeighborNode<T>* getHead() const;
    bool empty() const;
    NeighborNode<T>* search(const T& value) const;
};

#include "LinkedList.tpp"

#endif
