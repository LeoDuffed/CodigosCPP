#ifndef HASHTABLE_H
#define HASHTABLE_H
#include "Node.h"

template<typename T>
class HashTable{
    private:
        static const int TABLE_SIZE=20;
        int hashFunction(int key) const;
        Node<T>* table[TABLE_SIZE];
    public:
        HashTable();
        ~HashTable();
        void insert(int key, T value);
        void remove(int key);
        T& search(int key);
        void printTable() const;
};

#include "hashTable.tpp"

#endif