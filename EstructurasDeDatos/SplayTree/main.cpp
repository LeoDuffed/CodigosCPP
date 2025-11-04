// Ejecutable de prueba para el Splay Tree
#include <iostream>
#include "SplayTree.h"

int main() {
    SplayTree<int> tree;

    std::cout << "=== Prueba de Splay Tree ===\n";

    // Inserciones
    int valores[] = {10, 20, 30, 40, 50, 25, 5, 60, 1};
    std::cout << "Insertando: ";
    for (int v : valores) {
        std::cout << v << " ";
        tree.insert(v);
    }
    std::cout << "\nEstructura tras inserciones:\n";
    tree.print();

    // Búsqueda que existe (se debe splayar a la raíz)
    std::cout << "\nBuscando 25 (debería quedar en la raíz)\n";
    bool encontrado = tree.search(25);
    std::cout << "Encontrado: " << (encontrado ? "sí" : "no") << "\n";
    tree.print();

    // Búsqueda que no existe (splay al más cercano)
    std::cout << "\nBuscando 100 (no existe, se splaya el más cercano)\n";
    bool encontrado2 = tree.search(100);
    std::cout << "Encontrado: " << (encontrado2 ? "sí" : "no") << "\n";
    tree.print();

    // Eliminaciones
    std::cout << "\nEliminando 40\n";
    std::cout << (tree.deleteNode(40) ? "Eliminado" : "No encontrado") << "\n";
    tree.print();

    std::cout << "\nEliminando 25 (posible raíz actual)\n";
    std::cout << (tree.deleteNode(25) ? "Eliminado" : "No encontrado") << "\n";
    tree.print();

    std::cout << "\nIntentando eliminar 999 (no existe)\n";
    std::cout << (tree.deleteNode(999) ? "Eliminado" : "No encontrado") << "\n";
    tree.print();

    // Limpieza total
    std::cout << "\nLimpiando árbol completo\n";
    tree.clear();
    tree.print();

    return 0;
}
