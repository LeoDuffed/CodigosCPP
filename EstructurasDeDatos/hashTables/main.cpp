#include <iostream>
using namespace std;
#include "hashTable.h"

int main(){
    HashTable<string> table;
    table.insert("A01669629", "Leo");
    cout<<"\nTabla 1: "<<endl;
    table.printTable();
    table.insert("A01669629", "Leonardo Mrtz.");
    cout<<"\nTabla 2: "<<endl;
    table.printTable();
    return 0;
}