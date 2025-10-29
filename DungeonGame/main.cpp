#include <iostream>
#include "Node.h"
#include "Graph.h"

int main(){
    struct EncounterData{
        int difficulty;
        double reward;
    };

    Graph<EncounterData> dungeon(8);

    dungeon.addCorners(0, "Village", 0.05, EncounterData{0, 0.0});
    dungeon.addCorners(1, "Forest", 0.35, EncounterData{2, 50.0});
    dungeon.addCorners(2, "River", 0.25, EncounterData{3, 75.0});
    dungeon.addCorners(3, "Mountain", 0.15, EncounterData{4, 125.0});
    dungeon.addCorners(4, "Castle Gate", 0.45, EncounterData{5, 150.0});

    // Intentamos agregar un vertice repetido para confirmar validación
    dungeon.addCorners(1, "Duplicate Forest", 0.1, EncounterData{1, 10.0});

    // Conexiones del mapa
    dungeon.addEdges(0, 1);
    dungeon.addEdges(1, 2);
    dungeon.addEdges(2, 3);
    dungeon.addEdges(3, 4);
    dungeon.addEdges(4, 0); // ciclo
    dungeon.addEdges(1, 1); // no debería agregarse

    // Consultamos un vértice existente y uno inexistente
    if(Node<EncounterData>* node = dungeon.search(2)){
        std::cout<<"Encontrado nodo 2: "<<node->getName()<<" dificultad="
                 <<node->getExtra().difficulty<<"\n";
    }

    if(const Node<EncounterData>* missing = dungeon.search(6)){
        std::cout<<"Nodo 6 inesperadamente encontrado: "<<missing->getName()<<"\n";
    } else {
        std::cout<<"Nodo 6 no existe en el grafo.\n";
    }

    std::cout<<"\nResumen del grafo:\n";
    dungeon.printSummary();

    std::cout<<"\nRuta sugerida Village -> Castle Gate:\n";
    dungeon.printCheatBFS(0, 4);

    std::cout<<"\nRuta imposible Village -> Nodo inexistente:\n";
    dungeon.printCheatBFS(0, 7);

    return 0;
}
