#include <iostream>
#include <string>
using namespace std;

// class nodo
class Node{
    public: 
        string data;
        Node* next;
        int key;
        Node(int key, const string& data){
            this->key = key;
            this->data = data;
            next = nullptr;
        }
        void print(){ cout<<data; }
};

// class Table Hash
class HashTable{
    private: 
        static const int TABLE_SIZE = 20;
        int hashFunction(int key) const{ 
            return key % TABLE_SIZE;
        }
        Node* table[TABLE_SIZE];
    public:
        HashTable(){
            for(int i = 0; i < TABLE_SIZE; i++) table[i] = nullptr;
        }
        void insert(int key, string data){
            int index = hashFunction(key);
            Node* current = table[index];
            while(current != nullptr){
                if(current->key == key){
                    current->data = data;
                    return;
                }
                current = current->next;
            }
            Node* newNode = new Node(key, data);
            newNode->next = table[index];
            table[index] = newNode;
        }
        void remove(int key){
            int index = hashFunction(key);
            Node* current = table[index];
            Node* prev = nullptr;
            while(current != nullptr && current->key != key){
                prev = current;
                current = current->next;
            }
            if(current == nullptr) return;
            if(prev == nullptr) table[index] = current->next;
            else prev->next = current->next;
            delete current;
        }
        void printTable() const{
            for(int i = 0; i < TABLE_SIZE; i++){
                Node* current = table[i];
                if(table[i] != nullptr){
                    cout<<"[ "<<table[i]->key<<" -> ";
                } else {
                    cout<<" vacio ";
                }
                while(current != nullptr){
                    current->print();
                    current = current->next;
                }
                cout<<" ]"<<endl;
            }
        }
        bool search(int key, string& value){
            int index = hashFunction(key);
            Node* current = table[index];
            while(current != nullptr && current->key != key){
                current = current->next;
            }
            if(!current) return false;
            value = current->data;
            return true;
        }
};

// main
int main(){
    HashTable table;
    table.insert(742, "Leonardo");
    table.insert(83, "Julslol");
    cout<<"Tabla 1: "<<endl;
    table.printTable();
    table.insert(742, "Duffed");
    cout<<"\nTabla 2: "<<endl;
    table.printTable();
    return 0;
};