#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H
#include "Node.h"

template <typename T>
class PriorityQueue{
    private:
        Node<T>* head;
        int count;
    public:
        PriorityQueue(): head(nullptr), count(0){}
        ~PriorityQueue(){
            while(head){
                Node<T>* tmp = head;
                head = head->getNext();
                delete(tmp);
            }
        }
        void enque(const T& value, int priority);
        T dequeue();
        T peek() const;
        bool isEmpty() const;
        int size() const;
        void print();
};

#include "PriorityQueue.tpp"

#endif
