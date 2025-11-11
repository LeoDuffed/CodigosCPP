// Pequeño main para probar Graph
#include "Graph.h"
#include <iostream>

int main() {
    Graph<int> g(5);

    g.addVertex(1);
    g.addVertex(2);
    g.addVertex(3);
    g.addVertex(4);

    // Arista no dirigida 1-2 con peso 1
    g.addEdge(1, 2);

    // Arista dirigida 2->3 con peso 2
    g.addEdge(2, 3, 2, true);

    // Arista no dirigida 3-4 con peso 5
    g.addEdge(3, 4, 5, false);

    g.primtMatrix();

    return 0;
}
