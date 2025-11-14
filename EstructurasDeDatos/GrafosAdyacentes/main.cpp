#include "Graph.h"
#include <iostream>
using namespace std;

int maint(){
    Graph<string> grafo;
    grafo.addVertex("CDMX");
    grafo.addVertex("GDL");
    grafo.addVertex("MTY");
    grafo.addVertex("QRO");
    grafo.print();
    grafo.addEdge("CDMX","GDL", true);
    grafo.addEdge("MTY","GDL", true);
    return 0;
}