#ifndef ARREGLOVECTOR_H
#define ARREGLOVECTOR_H
#include <iostream> 
#include "Vector.h"

#define MAX_ELEME 6

/*
Clase ArregloVectores
Esta clase contendrá los siguientes elementos:
- Un arreglo que almacenará 6 vectores.
- Un método para agregar nuevos elementos al arreglo de vectores, en la posición que se encuentre vacía. Es decir, primero en la cero, luego en la 1, etc.
- Un método para sumar los vectores presentes en el arreglo.
*/

class ArregloVectores{
    private:
    Vector arreglo[MAX_ELEME];
    int vecSave;

    public:
    // Constructores
    ArregloVectores();
    ~ArregloVectores(){}
    ArregloVectores(int vecSave);

    // Funciones
    void agregarVec(Vector newVec);
    Vector sumaVectores();
    void MostrarArreglo();

};

#endif