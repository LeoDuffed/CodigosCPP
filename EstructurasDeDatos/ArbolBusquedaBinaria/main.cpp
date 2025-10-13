// 
// Creado por Leonardo Martínez 10/10/25
//

#include "Node.h"
#include "BST.h"
#include<iostream>
using namespace std;

int main(){
    BST<string> tree;
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
    return 0;
}