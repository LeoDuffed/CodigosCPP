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
    grafo.addEdge("CDMX", "GDL",true);
    grafo.addEdge("MTY", "GDL",true);
    grafo.addEdge("GDL", "QRO",false);
    grafo.addEdge("MTY", "CDMX",false);
    grafo.addEdge("CDMX", "GDL",true);
    grafo.print();
    return 0;

}