#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "Node.h"

template <typename T>
class LinkedList {
private:
    Node<T>* head;
    unsigned int n;
public:
    LinkedList();
    ~LinkedList();
    void pushBack(const T& value);
    Node<T>* getHead();
    bool empty() const;
    void print();
    bool insert(unsigned int index, const T& value);
    Node<T>* search(const T& value);


};

#include "LinkedList.tpp"
#endif //LINKEDLIST_H
