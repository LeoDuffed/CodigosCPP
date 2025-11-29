#include <iostream>
#include <string>
using namespace std;

// clase Node
class Node{
    public: 
        string data;
        Node* next;
        int key;
        Node(int key, const string& value){
            this->key = key;
            this->data = value;
            next = nullptr;
        }
        void print(){ cout<<data; }
};

// clase TableHash
class HashTable{
    private:
        static const int TABLE_SIZE = 20; // Definimos el tamaño de la tabla
        int hashFunction(int key) const{ // funcion de hashe (int`s)
            return key%TABLE_SIZE;
        }
        // Creamos una tabla de tipo Nodo con un tamaño de TABLE_SIZE
        Node* table[TABLE_SIZE]; 
    public:
        HashTable(){ // inizializamos la tabla con valores en null
            for(int i = 0; i < TABLE_SIZE; i++) table[i] = nullptr;
        }
        void insert(int key, string value){
            // Calcula índice por hash (bucket) y recorre la lista de ese bucket
            // Si la llave ya existe, solo actualiza el dato. Si no existe, crea nodo y lo encadena al inicio.
            int index = hashFunction(key);
            Node* current = table[index];
            while(current != nullptr){
                if(current->key == key){    // clave repetida: actualizar
                    current->data = value;  // sobrescribe el valor anterior
                    return;                  // y termina
                }
                // seguimos al siguiente en la lista (encadenamiento por colisión)
                current = current->next;
            }
            // se inserta al inicio de la lista ligada
            Node* newNode = new Node(key, value);
            newNode->next = table[index];
            table[index] = newNode;
        }
        void remove(int key){
            // Busca en la lista del bucket y elimina el nodo que coincide con la llave
            int index = hashFunction(key);
            Node* current = table[index];
            Node* prev = nullptr;
            while(current != nullptr && current->key != key){
                prev = current;
                current = current->next;
            } 
            if(current == nullptr){
                return;
            }
            if(prev == nullptr){
                table[index] = current->next;
            } else {
                prev->next = current->next;
            }
            delete current;
        }
        void printTable() const {
            // Recorre todos los buckets y muestra sus nodos enlazados
            for(int i = 0; i < TABLE_SIZE; i++){
                Node* current = table[i];
                if(table[i] != nullptr){
                    cout<<"[ "<<table[i]->key<<" -> ";
                } else {
                    cout<<"[ Vacio ";
                }
                while(current != nullptr){
                    current->print();
                    current = current->next;
                }
                cout<<" ]"<<endl;
            }
        }
        bool search(int key, string& outValue){
            // Busca la llave en su bucket; si existe, coloca el valor en outValue y devuelve true
            int index = hashFunction(key);
            Node* current = table[index];
            while(current != nullptr && current->key != key){
                current = current->next;
            }
            if(!current) return false;
            outValue = current->data;
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
    cout<<"Tabla 2: "<<endl;
    table.printTable();
    return 0;
};
