#ifndef STACK_H
#define STACK_H
#include "Node.h"

// Cambio: usar Node<T> en miembros y ajustar firmas const donde aplica.
template <typename T>
class Stack{
    
    private:
        Node<T>* topNode;
        unsigned int count;
    public:
        Stack():topNode(nullptr), count(0) {}
        ~Stack(){
            while (topNode){
                Node<T>* tmp = topNode; // Para no perder la referencia
                topNode = topNode->next;
                delete tmp;
            }
            count = 0;
        }
        void push(const T& v);
        T pop(); // Mejor no usar bool
        T top();
        bool isEmpty() const;
        void print() const;
};  

#include "Stack.tpp"

#endif
