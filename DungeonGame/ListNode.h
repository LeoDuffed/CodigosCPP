#ifndef LISTNODE_H
#define LISTNODE_H

template <typename T>
class ListNode {
public:
    T data;
    ListNode* next;
    ListNode(const T& v);
};

#include "ListNode.tpp"

#endif
