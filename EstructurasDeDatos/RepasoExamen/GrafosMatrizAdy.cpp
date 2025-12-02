#include <iostream>
using namespace std;

// clase Nodo 
class Node{
    public:
        int data;
        Node* next;
        explicit Node(const int& v) : data(v), next(nullptr) {}
};

// clase Stack para DFS en el grafo
class Stack{
    private:
        Node* topNode;
        unsigned int count;
    public:
        Stack(): topNode(nullptr), count(0) {}
        ~Stack(){
            while(topNode){
                Node* tmp = topNode;
                topNode = topNode->next;
                delete tmp;
            }
            count = 0;
        }
        void push(const int& v){ // Agrega un nuevo nodo
            Node* newNode = new Node(v);
            newNode->next = topNode; // el ultimo ahora es el penultimo
            topNode = newNode; // el nuevo ingresado ahora es topNode
            count++; 
        }
        int pop(){ // borrar el topNode
            if(count == 0){
                cout<<"Stack empty"<<endl;
                return -1;
            }
            Node* tmp = topNode;
            topNode = topNode->next; // ahora el penultimo es el topNode
            int returnValue = tmp->data; // conseguimos el valor que tenia el topNode
            delete tmp; // borramos ahora si el que era topNode
            --count; // menos un nodo
            return returnValue; // el valor del nodo que borramos
        }
        int top(){ // funcion para sabe el valor de topNode
            if(count == 0){
                cout<<"Stack empty"<<endl;
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
            while(topNode){
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
                // anlazamos el que era el ultimo con el nuevo ultimo
                firstNode->next = newNode;
                // actualizamos el puntero de "ultimo" para que hora sea newNode
                firstNode = newNode;
            }
            ++count;
        }
        int deQueue(){ // tiene casi la misma logica que pop del Stack
            if(count == 0) {
                cout<<"La cola esta vacia"<<endl;
                return -1;
            }
            Node* tmp = topNode;
            topNode = topNode->next; // topNode ahora es el penultimo
            if(topNode == nullptr) firstNode = nullptr; // significa que no hay nada
            int returnValue = tmp->data;
            delete tmp;
            --count;
            return returnValue;
        }
        int front(){
            if(count == 0) {
                cout<<"La cola esta vacia"<<endl;
                return -1;
            }
            else return topNode->data;
        }
        int isEmpty(){ return count == 0; }
};

// Grafo con matriz de adyacencia (solo usa iostream)
class Graph{
    private:
        int capacity;          // capacidad máxima
        int count;      // vértices insertados
        int* vertices;  // valores de los vértices
        int** matrix;   // matriz de adyacencia (0 = sin arista)
        bool* visited;  // apoyo para recorridos

        int indexOf(int v) const{
            for(int i = 0; i < count; i++){
                if(vertices[i] == v){
                    return i;
                }
            }
            return -1;
        }
        void resetVisited(){
            for(int i = 0; i < count; i++){
                visited[i] = false;
            }
        }

    public:
        Graph(int capacity){ // constructor
            this->capacity = capacity;
            count = 0;
            vertices = new int[capacity];
            visited = new bool[capacity];
            matrix = new int*[capacity];
            for(int i = 0; i < capacity; i++){
                matrix[i] = new int[capacity];
                visited[i] = false;
                for(int j = 0; j < capacity; j++){
                    matrix[i][j] = 0;
                }
            }
        }
        ~Graph(){ // desctructor
            for(int i = 0; i < capacity; i++){
                delete[] matrix[i];
            }
            delete[] matrix;
            delete[] vertices;
            delete[] visited;
        }
        bool addVertex(int v){
            // si está lleno o ya existe, no lo agrega
            if(count >= capacity) return false; // count = vertices insertado
            if(indexOf(v) != -1) return false;
            vertices[count] = v;
            // para que toma la siguiente posicion cuando se llame
            // por ejemplo count = 1, count++ -> count = 2
            // para que cuando se llame vertices tome la posicion 2
            // vertices[2] -> antes = vertices[1]
            count++; 
            return true;
        }
        bool addEdge(int from, int to, int weight = 1, bool directed = false){
            int i = indexOf(from);
            int j = indexOf(to);
            if(i == -1 || j == -1) return false; // falta algún vértice
            matrix[i][j] = weight;
            if(!directed){ // para ver si es dirigido 
                // por ejemplo B -> c y de C -> B
                matrix[j][i] = weight;
            }
            return true;
        }
        void printMatrix() const{
            cout<<"\n--- MATRIZ DE ADYACENCIA ---\n\t";
            for(int i = 0; i < count; i++){
                cout<<vertices[i]<<"\t";
            }
            cout<<"\n";
            for(int i = 0; i < count; i++){
                cout<<vertices[i]<<"\t";
                for(int j = 0; j < count; j++){
                    cout<<matrix[i][j]<<"\t";
                }
                cout<<"\n";
            }
        }
        void DFS(const int& start){
            int starIndex = indexOf(start);
            if(starIndex == -1){
                cout<<"No se encontro el index"<<endl;
                return;
            }
            resetVisited();
            Stack s;
            visited[starIndex] = true;
            s.push(starIndex);
            while(!s.isEmpty()){
                int index = s.pop();
                cout<<vertices[index]<<" -> ";
                for(int neiIndex = 0; neiIndex < count; neiIndex++){
                    if(matrix[index][neiIndex] != 0 && !visited[neiIndex]){
                        visited[neiIndex] = true;
                        s.push(neiIndex);
                    }
                }
            }
            cout<<""<<endl;
        }
        void BFS(const int& start){
            int startIndex = indexOf(start);
            if(startIndex == -1){
                cout<<"No se encontro el index"<<endl;
                return;
            }
            resetVisited();
            Queue q;
            visited[startIndex] = true;
            q.enQueue(startIndex);
            while(!q.isEmpty()){
                int index = q.deQueue();
                cout<<vertices[index]<<" -> ";
                for(int neiIndex = 0; neiIndex < count; neiIndex++){
                    if(matrix[index][neiIndex] != 0 && !visited[neiIndex]){
                        visited[neiIndex] = true;
                        q.enQueue(neiIndex);
                    }
                }
            }
            cout<<" "<<endl;
        }
};

// Ejemplo de uso básico
int main(){
    Graph g(6); // capacidad de 6 vértices

    // Insertamos vértices
    g.addVertex(10);
    g.addVertex(20);
    g.addVertex(30);
    g.addVertex(40);
    g.addVertex(50);
    g.addVertex(60);

    // Aristas (no dirigidas por default)
    g.addEdge(10, 20);
    g.addEdge(20, 30, 2);
    g.addEdge(30, 40, 3);
    g.addEdge(10, 50, 4);
    g.addEdge(50, 60, 5);
    g.addEdge(20, 60, 1, true); // dirigida 20 -> 60

    g.printMatrix();

    g.DFS(10);

    g.BFS(10);
    return 0;
}
