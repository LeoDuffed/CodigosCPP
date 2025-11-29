#include <iostream>
using namespace std;

// clase Node
class Node{
    public:
        int data;
        int height;
        Node* izq;
        Node* der;

        Node(int data){
            this->data = data; // asignar al miembro, no al parámetro
            height = 1;
            izq = nullptr;
            der = nullptr;
        }
};

// Clase AVL
class AVL{
    private: 
        Node* root;
        int height(Node* node){ // Funcion que returnea la altura de un nodo
            if(node == nullptr) return 0;
            return node->height;
        }
        int maxInt(int a, int b){
            /* Funcion maxInt
                devuelve el mayor de dos enteros. Lo usas para recalcular la altura de un 
                nodo tras rotar o insertar: 
                altura = 1 + maxEntero(altura(izquierdo), altura(derecho)). 
                Así la altura del nodo es 1 más la mayor de las alturas de sus 
                hijos, que es la definición de altura en un árbol.
            */
            return (a > b) ? a : b;
        }
        int balanceFac(Node* node){ // Funcion para conseguir el factor de balance de un nodo (izq - der)
            if(node == nullptr) return 0;
            return height(node ->izq) - height(node->der);
        }
        Node* rotacionSimpleDer(Node* node){
            // Usamos variables temporales para luego reacomodar los nodos
            Node* tmp = node->izq;
            Node* tmp2 = tmp->der; // es para conservar el subarbol intermedio si es nullptr
            // Rotacion
            tmp->der = node;
            node->izq = tmp2;
            // Actualizamos las alturas
            node->height = 1+maxInt(height(node->izq), height(node->der));
            tmp->height = 1+maxInt(height(tmp->izq), height(tmp->der));
            // retrunemoas el nuevo nodo
            return tmp;
        }
        Node* rotacionSimpleIzq(Node* node){
            // valores temporales
            Node* tmp = node->der;
            Node* tmp2 = tmp->izq;
            // Rotacion
            tmp->izq = node;
            node->der = tmp2; // es para conservar el subarbol intermedio si es nullptr
            // Acutalizamos las alturas
            node->height = 1+maxInt(height(node->izq), height(node->der));
            tmp->height = 1+maxInt(height(tmp->izq), height(tmp->der));
            // Returneamos el nuevo nodo
            return tmp;
        }
        Node* rotacionDerIzq(Node* node){
            // Primero rotamos a la derecha
            node->der = rotacionSimpleDer(node->der);
            // Rotamos a la izquierda y regresamos el nodo
            return rotacionSimpleIzq(node);
        }
        Node* rotacionIzqDer(Node* node){
            // Primero rotamos a la izquierda
            node->izq = rotacionSimpleIzq(node->izq);
            // Rotamos a la derecha y regresamos el nodo
            return rotacionSimpleDer(node);
        }
        Node* insertRec(Node* node, const int value){
            // Si no hay nodo (nullptr), lo metemos
            if(node == nullptr){
                Node* newNode = new Node(value);
                return newNode;
            }
            if(value < node->data){
                node->izq = insertRec(node->izq, value);
            } else if(value > node->data){
                node->der = insertRec(node->der, value);
            } else {
                // Si es valor duplicado no se mete
                return node;
            }
            // Actualizamos la altura
            node->height = 1 + maxInt(height(node->izq), height(node->der));
            // Vemos si esta valanceado ese nodo
            int balance = balanceFac(node);
            // si desbalanceado, pues lo balanceamos
            if(balance > 1 && value < node->izq->data){
                return rotacionSimpleDer(node);
            } else if(balance > 1 && value > node->izq->data){
                return rotacionIzqDer(node);
            } else if(balance < -1 && value < node->der->data){
                return rotacionDerIzq(node);
            } else if(balance < -1 && value > node->der->data){
                return rotacionSimpleIzq(node);
            }
            // si no se necesitaba balancer regresamos el nodo como llego
            return node;
        }
        void print(Node* node) const{
            if(node == nullptr) return;
            cout<<"Nodo: "<<node->data<<" ( Izq: ";
            if(node->izq) cout<<node->izq->data;
            else cout<<"null";
            cout<<", Der: ";
            if(node->der) cout<<node->der->data;
            else cout<<"null";
            cout<<" )"<<endl;
            print(node->izq);
            print(node->der);
        }

    public:
        AVL(){ root = nullptr; }
        void insert(int value){ root = insertRec(root, value); }
        void print(){
            if( root == nullptr) {
                cout<<"El arbol esta vacio"<<endl;
                return;
            }
            print(root);
            cout<<"\n";
        }
};


// Main
int main(){
    AVL tree;

    // Secuencia que provoca rotaciones simples y dobles
    int valores[] = {30, 10, 20, 5, 3, 4, 40, 50, 45};
    int n = 9;
    cout << "Insertando valores en el AVL:\n";
    for (int i = 0; i < n; i++) {
        tree.insert(valores[i]);
    }
    tree.print();
    return 0;
}
