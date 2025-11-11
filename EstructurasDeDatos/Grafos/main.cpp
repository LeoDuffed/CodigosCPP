#include "Graph.h"
#include <string>

using namespace std;


int main () {
    Graph<string > grafo(10);

    grafo.addVertex("CDM");
    grafo.addVertex("GDL");
    grafo.addVertex("MTY");
    grafo.addVertex("TOL");
    grafo.addVertex("QRO");
    grafo.addVertex("MOR");
    grafo.addEdge("CDM", "TOL");
    grafo.addEdge("TOL", "GDL");
    grafo.addEdge("MOR", "GDL");
    grafo.addEdge("CDM", "QRO");
    grafo.addEdge("QRO", "MTY");

    grafo.BFS("MTY");

    grafo.printMatrix();

    return 0;
}