// 
// Creado por Leonardo Martínez 10/10/25
//

#include "Node.h"
#include "BST.h"
#include<iostream>
using namespace std;

int main(){
    BST<std::string> tree;
    tree.insert("D");
    tree.insert("B");
    tree.insert("A");
    tree.insert("F");
    tree.insert("E");
    tree.insert("G");
    tree.insert("C");
    tree.insert("H");
    tree.insert("J");
    tree.insert("I");

    tree.print();

    std::cout << "\nAncestros de J: ";
    tree.ancestors("J"); 

    std::cout << "Nivel de D: " << tree.whatLevelAmI("D") << "\n"; 
    std::cout << "Nivel de C: " << tree.whatLevelAmI("C") << "\n"; 
    std::cout << "Nivel de Z: " << tree.whatLevelAmI("Z") << "\n"; 

    return 0;
}
