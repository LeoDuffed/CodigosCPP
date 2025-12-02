#include <iostream>
using namespace std;

class Node{
public: 
    int data;
    int height;
    Node* left;
    Node* right;
    Node(int data){
        this->data = data;
        height = 1;
        left = nullptr;
        right = nullptr;
    }
};
class AVL{
private:
    Node* root;
    int height(Node* node){
        if(node == nullptr) return 0;
        return node->height;
    }
    int maxInt(int a, int b){
        if(a > b) return a;
        else return b;
    }
    int balaceFactor(Node* node){
        if(node == nullptr) return 0;
        return height(node->left) - height(node->right);
    }
    Node* leftRotation(Node* node){
        Node* tmp = node->right;
        Node* tmp2 = tmp->left;
        tmp->left = node;
        node->right = tmp2;
        node->height = 1 + maxInt(height(node->left), height(node->right));
        tmp->height = 1 + maxInt(height(tmp->left), height(tmp->right));
        return tmp;
    }
    Node* rightRotation(Node* node){
        Node* tmp = node->left;
        Node* tmp2 = tmp->right;
        tmp->right = node;
        node->left = tmp2;
        node->height = 1 + maxInt(height(node->left), height(node->right));
        tmp->height = 1 + maxInt(height(tmp->left), height(tmp->right));
        return tmp;
    }
    Node* rightLeftRotation(Node* node){
        node->right = rightRotation(node->right);
        return leftRotation(node);
    }
    Node* leftRightRotation(Node* node){
        node->left = leftRotation(node->left);
        return rightRotation(node);
    }
    Node* insertRec(Node* node, int value){
        if(node == nullptr){
            Node* newNode = new Node(value);
            return newNode;
        }
        if(value > node->data){
            node->right = insertRec(node->right, value);
        } else if(value < node->data){
            node->left = insertRec(node->left, value);
        } else {
            return node;
        }
        /* mas grandes a la izquierda, mas pequeños a la derecha
        if(value < node->data){
            node->left = insertRec(node->left, value);
        } else if( value > node->data){
            node->right = insertRec(node->right, value); 
        } else {
            return node; 
        }
        */
        node->height = 1 + maxInt(height(node->left), height(node->right));
        int bf = balaceFactor(node);
        if(bf > 1 && value < node->left->data) {  
            return rightRotation(node);
        } else if(bf < -1 && value < node->right->data) {
            return rightLeftRotation(node);
        } else if(bf > 1 && value > node->left->data) {
            return leftRightRotation(node);
        } else if(bf < -1 && value > node->right->data) {
            return leftRotation(node);
        }
        /* mas grandes a la izquierda, mas pequeños a la derecha
        if(bf > 1 && value > node->left->data){
            return rightRotation(node);
        } else if(bf > 1 && value < node->left->data){
            return leftRightRotation(node);
         } else if(bf < -1 && value < node->right->data){
            return leftRotation(node);  
        } else if(bf < -1 && value > node->right->data){
            return rightLeftRotation(node); 
        }
        */
        return node;
    }
    void print(Node* node) const{
        if(node == nullptr) return;
        cout<<"Nodo: "<<node->data<<" ( Izq: ";
        if(node->left) cout<<node->left->data;
        else cout<<"null";
        cout<<", Der: ";
        if(node->right) cout<<node->right->data;
        else cout<<"null";
        cout<<" )"<<endl;
        print(node->left);
        print(node->right);
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
int main(){
    AVL tree;
    int valores[] = {30, 10, 20, 5, 3, 4, 40, 50, 45};
    int n = 9;
    cout << "Insertando valores en el AVL:\n";
    for (int i = 0; i < n; i++) tree.insert(valores[i]);
    tree.print();
    return 0;
};