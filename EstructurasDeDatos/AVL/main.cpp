#include "AVL.h"
#include "Node.h"

int main(){
    AVL<int> avl;
    avl.insert(8);
    avl.insert(4);
    avl.insert(10);
    avl.insert(2);
    avl.insert(9);
    avl.insert(1);
    avl.print();
}