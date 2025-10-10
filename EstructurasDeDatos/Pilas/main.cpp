#include "Stack.h"
#include "Node.h"
#include <iostream>
using namespace std;

int main(){
    Stack<int> stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);
    stack.push(5);
    stack.push(6);
    stack.push(7);
    stack.print();

    
    return 0;
}