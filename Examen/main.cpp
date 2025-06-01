#include <iostream>
#include "NumComplejo.h"
#include "ArregloComplejos.h"

int main(){

    ArregloComplejos arreglo;
    for (unsigned int index = 0; index < 10; index++) {
    NumComplejo tmp(index + 1, index + 2);
    if (!arreglo.agregar(tmp)) {
    std::cout << "No se pudo agregar: ";
    tmp.imprimir();
    }
    }
    NumComplejo restaTotal = arreglo.restaTotal();
    std::cout << "\nLa resta total de los complejos en el arreglo es: ";
    restaTotal.imprimir();
    return 0;

};