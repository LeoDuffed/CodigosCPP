#include "Node.h"
#include<iostream>
using namespace std;

int main(){
    
    Node<string> node1("A");
    std::cout<<node1.getData()<<"\n";

    
    return 0;
}