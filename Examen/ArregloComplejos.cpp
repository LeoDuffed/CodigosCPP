#include <iostream> 
#include "ArregloComplejos.h"

// Funciones y Metodos
// Funcion para ir agregando los numeros complejos al arreglo
bool ArregloComplejos :: agregar(const NumComplejo& num){
    if(nextSpace < CAP){
        arreglo[nextSpace++] = num;
        return true;
    } 
    
    std::cout << "\nEl arreglo esta lleno\n";
    return false;
}
// Funcion de resta total de lo numeros del arreglo
NumComplejo  ArregloComplejos :: restaTotal() const {

    if (nextSpace == 0) return NumComplejo(0,0);
    NumComplejo r = arreglo[0];
    for(int i = 1; i < nextSpace; i++) r = r - arreglo[i];
    return r;
}
// No se pide, pero es para mostrar los numeros complejos
void ArregloComplejos :: mostrarArray() const{
    for(int i = 0; i < nextSpace; i++){
        std::cout << "Numero Complejo " << (i + 1) << " : " << arreglo[i] << "\n";
    }
}