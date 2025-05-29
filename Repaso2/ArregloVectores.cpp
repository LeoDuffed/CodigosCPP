#include <iostream> 
#include "ArregloVectores.h"

// Constructores
ArregloVectores :: ArregloVectores(){
    Vector arreglo[6];
    int vecSave = 0;
}
ArregloVectores :: ArregloVectores(Vector arreglo, int vecSave){
    this -> arreglo = arreglo;
    this -> vecSave = vecSave;
}

// Setter
void ArregloVectores :: setArreglo(Vector arreglo){
    this -> arreglo = arreglo;
}
void ArregloVectores :: setVecSave(int vecSave){
    this -> vecSave = vecSave;
}

// Getter
Vector ArregloVectores :: getArreglo(){
    return arreglo;
}
int ArregloVectores :: getVecSave(){
    return vecSave;
}

// Funciones


