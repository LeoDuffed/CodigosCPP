// 4/11/2025
// Codigo hecho por Leonardo Martínez y Juan Eduardo Barrón

#include <iostream>
#include "SplayTree.h"

int main() {
    SplayTree<int> tree;

    int valores[] = {10, 20, 30, 40, 50, 25, 5, 60, 1};
    std::cout << "Insertando: ";
    for (int v : valores) {
        std::cout << v << " ";
        tree.insert(v);
    }
    tree.print();

    std::cout << "\nBuscando 25\n";
    bool encontrado = tree.search(25);
    std::cout << "Encontrado: " << (encontrado ? "sí" : "no") << "\n";
    tree.print();

    std::cout << "\nBuscando 100\n";
    bool encontrado2 = tree.search(100);
    std::cout << "Encontrado: " << (encontrado2 ? "sí" : "no") << "\n";
    tree.print();

    std::cout << "\nEliminando 40\n";
    std::cout << (tree.deleteNode(40) ? "Eliminado" : "No encontrado") << "\n";
    tree.print();

    std::cout << "\nEliminando 25\n";
    std::cout << (tree.deleteNode(25) ? "Eliminado" : "No encontrado") << "\n";
    tree.print();

    std::cout << "\nEliminando 999\n";
    std::cout << (tree.deleteNode(999) ? "Eliminado" : "No encontrado") << "\n";
    tree.print();

    tree.clear();
    tree.print();

    return 0;
}
