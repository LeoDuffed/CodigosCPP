#pragma once
#include <iostream>
using namespace std;

template<typename T>
void PriorityQueue<T>::enque(const T& value, int priority){
    Node<T>* newNode = new Node<T>(value, priority);
    if(!head || priority > head->getPriority()){
        newNode->setNext(head);
        head = newNode;
    } else {
        Node<T>* current = head;
        while(current->getNext() && current->getNext()->getPriority() >= priority){
            current = current->getNext();
        }
        newNode->setNext(current->getNext());
        current->setNext(newNode);
    }
    count++;
}

template<typename T>
T PriorityQueue<T>::dequeue(){
    if(isEmpty()){
        cout << "Esta vacia" << endl;
        return T();
    } else {
        Node<T>* tmp = head;
        head = head->getNext();
        T returnValue = tmp->getData();
        delete tmp;
        count--;
        return returnValue;
    }
}

template<typename T>
T PriorityQueue<T>::peek() const{
    if(isEmpty()){
        cout << "Esta vacia" << endl;
        return T();
    } else {
        return head->getData();
    }
}

template<typename T>
bool PriorityQueue<T>::isEmpty() const{
    return count == 0;
}

template<typename T>
int PriorityQueue<T>::size() const {
    return count;
}

template<typename T>
void PriorityQueue<T>::print(){
    if(isEmpty()){
        cout<<"Esta vacia"<<endl;
    } else {
        cout<<"Inicio: ";
        Node<T>* current = head;
        while(current){
            cout<<current->getData()<<" prio: "<<current->getPriority()<<" -> ";
            current = current->getNext();
        }
        cout<<" Fin "<<endl;
    }
}
