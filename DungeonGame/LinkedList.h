#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "NeighborList.h"

template <typename T>
class LinkedList {
private:
    NeighborList<T>* head;
    int n;
public:
    LinkedList();
    ~LinkedList();
    int size() const;
    void pushBack(const T& value);
    NeighborList<T>* getHead() const;
    bool empty() const;
    NeighborList<T>* search(const T& value) const;
};

#include "LinkedList.tpp"

#endif
