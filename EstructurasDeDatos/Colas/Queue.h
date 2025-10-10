#ifndef QUEUE_H
#define QUEUE_H
#include "Node.h"

template <typename T>
class Queue{
    private:
        Node<T>* topNode;
        Node<T>* firstNode;
        unsigned int count;
    public:
        Queue():topNode(nullptr), firstNode(nullptr), count(0) {}
        ~Queue(){
            while (topNode){
                Node<T>* tmp = topNode;
                topNode = topNode->next;
                delete tmp;
            }
            count = 0;
        }
        void enQueue(const T& v);
        T deQueue();
        int front();
        bool isEmpty() const;
        void print() const;
};

#include "Queue.tpp"

#endif