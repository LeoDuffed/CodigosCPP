#ifndef LINKEDLIST_H
#define LINKEDLIST_H

template <typename T>
class ListNode;

template <typename T>
class LinkedList {
private:
    ListNode<T>* head;
    int n;
public:
    LinkedList();
    ~LinkedList();
    int size() const;
    void pushBack(const T& value);
    ListNode<T>* getHead() const;
    bool empty() const;
    ListNode<T>* search(const T& value) const;
};

#include "LinkedList.tpp"

#endif
