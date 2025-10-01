#include <iostream> 
#include "ArregloVectores.h"

// Constructores
ArregloVectores :: ArregloVectores(){
    this -> vecSave = 0;
}
ArregloVectores :: ArregloVectores(int vecSave){
    this -> vecSave = vecSave;
}

// Funciones
void ArregloVectores :: agregarVec(Vector newVec){
    if (vecSave < MAX_ELEME){
        arreglo[vecSave] = newVec;
        vecSave++;
    } else {
        std :: cout << "El arreglo ya esta lleno" << std :: endl;
    }
}
Vector ArregloVectores :: sumaVectores(){
    Vector sumTotal;

    for(int i = 0; i < vecSave; i++){
        sumTotal = sumTotal.suma(
                arreglo[i].getX(), 
                arreglo[i].getY(),
                arreglo[i].getZ()
                );
    }
    return sumTotal;
}
void ArregloVectores :: MostrarArreglo(){
    for(int i = 0; i < vecSave; i++){
        std :: cout << "Vector " << i + 1 << " : " << std :: endl;
        arreglo[i].MostrarVec();
    }
}

