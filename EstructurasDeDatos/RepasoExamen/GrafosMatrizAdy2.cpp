#include <iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
        explicit Node(const int& v) : data(v), next(nullptr) {}
};

class Stack{
    private:
        Node* topNode;
        unsigned int count;
    public:
        Stack() : topNode(nullptr), count(0) {}
        ~Stack(){
            while(topNode){
                Node* tmp = topNode;
                topNode = topNode->next;
                delete tmp;
            }
            count = 0;
        }
        void push(const int& v){
            Node* newNode = new Node(v);
            newNode->next = topNode;
            topNode = newNode;
            count++;
        }
        int pop(){
            if(count == 0) {
                cout<<"Empty Stack"<<endl; 
                return -1;
            }
            Node* tmp = topNode;
            topNode = topNode->next;
            int returnValue = tmp->data;
            delete tmp;
            --count;
            return returnValue;
        }
        int top(){
            if(count == 0) {
                cout<<"Empty Stack"<<endl;
                return -1;
            }
            return topNode->data;
        }
        int isEmpty(){ return count == 0; }
};

class Queue{
    private:
        Node* topNode;
        Node* firstNode;
        unsigned int count;
    public:
        Queue(){
            topNode = nullptr;
            firstNode = nullptr;
            count = 0;
        }
        ~Queue(){
            while (topNode) {
                Node* tmp = topNode;
                topNode = topNode->next;
                delete tmp;
            }
            count = 0;
        }
        void enQueue(const int& v){
            Node* newNode = new Node(v);
            if(count == 0){
                topNode = firstNode = newNode;
            } else {
                firstNode->next = newNode;
                firstNode = newNode;
            }
            count++;
        }
        int deQueue(){
            if(count == 0){
                cout<<"Empty queue"<<endl;
                return -1;
            }
            Node* tmp = topNode;
            topNode = topNode->next;
            if(topNode == nullptr) firstNode = nullptr;
            int returnValue = tmp->data;
            delete tmp;
            --count;
            return returnValue;
        }
        int front(){
            if(count == 0){
                cout<<"Empty queue"<<endl;
                return -1;
            } else return topNode->data;
        }
        int isEmpty(){ return count == 0; }
};

class Graph{
    private:
        int capacity;
        int count;
        int* vertex;
        int** matrix;
        bool* visited;
        int indexOf(int v) const{
            for(int i = 0; i < count; i++) if(vertex[i] == v) return i;
            return -1;
        }
        void resetVisited(){
            for(int i = 0; i < count; i++) visited[i] = false;
        }
    public:
        Graph(int capacity){
            this->capacity = capacity;
            count = 0;
            vertex = new int[capacity];
            visited = new bool[capacity];
            matrix = new int*[capacity];
            for(int i = 0; i < capacity; i++){
                matrix[i] = new int[capacity];
                visited[i] = false;
                for(int j = 0; j < capacity; j++) matrix[i][j] = 0;
            }
        }
        ~Graph(){
            for(int i = 0; i < capacity; i++) delete[] matrix[i];
            delete[] matrix;
            delete[] vertex;
            delete[] visited;
        }
        bool addVertex(int v){
            if(count >= capacity) return false;
            if(indexOf(v) != -1) return false;
            vertex[count] = v;
            count++;
            return true;
        }
        bool addEdge(int from, int to, int weight = 1, bool directed = false){
            int i = indexOf(from);
            int j = indexOf(to);
            if( j == -1 || i == -1) return false;
            matrix[i][j] = weight;
            if(!directed){
                matrix[i][j] = weight;
            }
            return true;
        }
        
};