//
// Creado por Leonardo Martínez 
//
#include <iostream>
#include "Graph.h"
#include <string>
using namespace std;

int main() {
    Graph<string> grafo;
    grafo.addVertex("CDMX");
    grafo.addVertex("GDL");
    grafo.addVertex("MTY");
    grafo.addVertex("QRO");
    grafo.addVertex("PUE");

    grafo.addEdge("CDMX", "GDL", false);
    grafo.addEdge("CDMX", "MTY", true);
    grafo.addEdge("GDL", "QRO", false);
    grafo.addEdge("QRO", "PUE", false);
    grafo.addEdge("MTY", "PUE", true);

    cout<<"Lista de adyacencia:"<<endl;
    grafo.print();

    cout<<"\nRecorrido BFS desde CDMX:"<<endl;
    grafo.BFS("CDMX");

    cout<<"\nRecorrido DFS desde CDMX:"<<endl;
    grafo.DFS("CDMX");

    return 0;
}
