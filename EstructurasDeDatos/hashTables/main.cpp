#include <iostream>
using namespace std;
#include "hashTable.h"

int main(){
    HashTable<string> table;
    table.insert(30, "Leo");
    table.printTable();
    table.search(55);
    return 0;
}