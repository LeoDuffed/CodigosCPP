#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string key;
    string data;
    Node* next;
    Node(const string& k, const string& v) : key(k), data(v), next(nullptr) {}
    void print() const { cout << key << " -> " << data; }
};

class HashTable {
private:
    static const int TABLE_SIZE = 20;
    Node* table[TABLE_SIZE];

    int hashFunction(const string& key) const {
        int hash = 0;
        for (char c : key) hash += static_cast<unsigned char>(c);
        return hash % TABLE_SIZE;
    }

public:
    HashTable() {
        for (int i = 0; i < TABLE_SIZE; ++i) table[i] = nullptr;
    }

    ~HashTable() {
        for (int i = 0; i < TABLE_SIZE; ++i) {
            Node* cur = table[i];
            while (cur) {
                Node* tmp = cur;
                cur = cur->next;
                delete tmp;
            }
            table[i] = nullptr;
        }
    }

    void insert(const string& key, const string& value) {
        int idx = hashFunction(key);
        Node* current = table[idx];
        while (current) {
            if (current->key == key) { // clave ya existe: actualiza
                current->data = value;
                return;
            }
            current = current->next;
        }
        Node* newNode = new Node(key, value);
        newNode->next = table[idx];   // insertar al inicio de la lista
        table[idx] = newNode;
    }

    void remove(const string& key) {
        int index = hashFunction(key);
        Node* current = table[index];
        Node* prev = nullptr;
        while (current && current->key != key) {
            prev = current;
            current = current->next;
        }
        if (!current) return; // no encontrada
        if (!prev) table[index] = current->next;
        else prev->next = current->next;
        delete current;
    }

    string* search(const string& key) {
        int idx = hashFunction(key);
        Node* current = table[idx];
        while (current && current->key != key) current = current->next;
        return current ? &current->data : nullptr;
    }

    void printTable() const {
        for (int i = 0; i < TABLE_SIZE; ++i) {
            cout << i << ": ";
            Node* current = table[i];
            if (!current) { cout << "[vacio]\n"; continue; }
            cout << "[ ";
            while (current) {
                current->print();
                if (current->next) cout << " | ";
                current = current->next;
            }
            cout << " ]\n";
        }
    }
};

int main() {
    HashTable ht;
    ht.insert("abc", "uno");
    ht.insert("cba", "dos");
    ht.insert("abc", "uno-actualizado");
    ht.printTable();
    if (auto p = ht.search("abc")) cout << "Encontrado: " << *p << "\n";
    ht.remove("abc");
    ht.printTable();
    return 0;
}
