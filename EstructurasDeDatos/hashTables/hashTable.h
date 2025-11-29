#ifndef HASHTABLE_H
#define HASHTABLE_H
#include <iostream>
using namespace std;
#include "Node.h"

template<typename T>
class HashTable{
    private:
        static const int TABLE_SIZE=20;
        int hashFunction(const string& key) const;
        Node<T>* table[TABLE_SIZE];
    public:
        HashTable();
        ~HashTable();
        void insert(const string& key, const T& value);
        void remove(const string& key);
        T* search(const string& key);
        void printTable() const;
};

#include "hashTable.tpp"

#endif
