#include "AVL.h"
#include "Node.h"

int main(){
    AVL<int> avl;
    avl.insert(8);
    avl.insert(4);
    avl.insert(10);
    avl.insert(2);
    avl.insert(9);
    avl.insert(14);
    avl.insert(3);
    avl.insert(7);
    avl.insert(5);
    avl.insert(15);
    avl.print();

    avl.deleteNode(8);
    avl.print();

    avl.search(15);
}