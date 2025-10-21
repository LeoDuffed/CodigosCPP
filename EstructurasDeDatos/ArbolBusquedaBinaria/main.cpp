// 
// Creado por Leonardo Martínez 10/10/25
//

#include "Node.h"
#include "BST.h"
#include <iostream>
using namespace std;

int main(){
    // Insercion, print, niveles, ancestros
    cout<<"Casos prueba 1\n";
    BST<string> a;
    if(a.isEmpty()) cout<<"Arbol vacio\n";
    a.insert("D");
    a.insert("B");
    a.insert("A");
    a.insert("F");
    a.insert("E");
    a.insert("G");
    a.insert("C");
    a.insert("H");
    a.insert("J");
    a.insert("I");
    a.print();
    cout<<"Ancestros de J: ";
    a.ancestors("J");
    cout<<"Nivel de D: "<<a.whatLevelAmI("D")<<"\n";
    cout<<"Nivel de C: "<<a.whatLevelAmI("C")<<"\n";
    cout<<"Nivel de Z: "<<a.whatLevelAmI("Z")<<"\n";
    cout<<"\n";

    // Recorridos y busquedas
    cout<<"Casos prueba 2\n";
    BST<string> b;
    b.insert("M");
    b.insert("H");
    b.insert("T");
    b.insert("A");
    b.insert("K");
    b.insert("P");
    b.insert("Z");
    cout<<"Print: ";
    b.print();
    cout<<"PreOrder:\n"; b.preOrder();
    cout<<"InOrder:\n"; b.inOrder();
    cout<<"PostOrder:\n"; b.postOrder();
    if(b.search("K")) cout<<"Se encontro K\n";
    if(!b.search("X")) cout<<"No se encontro X\n";
    cout<<"\n";

    // Borrados y clear
    cout<<"Casos prueba 3\n";
    BST<string> c;
    c.insert("Q");
    c.insert("O");
    c.insert("S");
    c.insert("N");
    c.insert("P");
    c.insert("R");
    c.insert("T");
    cout<<"Inicial: "; c.print();
    if(c.deleteNode("N")) cout<<"Se elimino N\n"; // hoja
    cout<<"Despues: "; c.print();
    if(c.deleteNode("S")) cout<<"Se elimino S\n"; // un hijo
    cout<<"Despues: "; c.print();
    if(c.deleteNode("Q")) cout<<"Se elimino Q\n"; // dos hijos
    cout<<"Despues: "; c.print();
    c.clear();
    cout<<"Clear\n";
    cout<<"Print: "; c.print();
    if(c.isEmpty()) cout<<"Arbol vacio\n";

    return 0;
}
