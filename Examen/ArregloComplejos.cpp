#include <iostream> 
#include "ArregloComplejos.h"

// Constructores
ArregloComplejos :: ArregloComplejos(){
    this -> nextSpace = 0;
}
ArregloComplejos :: ArregloComplejos(int nextSpace){
    this -> nextSpace = nextSpace;
}

// Funciones y Metodos
// Funcion para ir agregando los numeros complejos al arreglo
bool ArregloComplejos :: agregar(NumComplejo newNumComp){
    if(nextSpace < 6){
        arreglo[nextSpace] = newNumComp;
        nextSpace++;
    } else {
        std :: cout << "\nEl arreglo esta lleno" << std :: endl;
        return false;
    }
    return true;
}
// Funcion de resta total de lo numeros del arreglo
NumComplejo  ArregloComplejos :: restaTotal(){

    if (nextSpace == 0){
        return NumComplejo();
    }

    NumComplejo restaTotal = arreglo[0];

    for(int i = 0; i < nextSpace; i++){
        restaTotal = restaTotal.resta(arreglo[i].getA(), arreglo[i].getB());
    }

    return restaTotal;
}
// No se pide, pero es para mostrar los numeros complejos
void ArregloComplejos :: mostrarArray(){
    for(int i = 0; i < nextSpace; i++){
        std :: cout << "Numero Complejo " << i + 1 << " : " << std :: endl;
        arreglo[i].imprimir();
    }
}