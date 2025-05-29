#ifndef ARREGLOVECTOR_H
#define ARREGLOVECTOR_H
#include <iostream> 
#include "Vector.h"

/*
Clase ArregloVectores
Esta clase contendrá los siguientes elementos:
- Un arreglo que almacenará 6 vectores.
- Un método para agregar nuevos elementos al arreglo de vectores, en la posición que se encuentre vacía. Es decir, primero en la cero, luego en la 1, etc.
- Un método para sumar los vectores presentes en el arreglo.
*/

class ArregloVectores{
    private:
    Vector arreglo;
    int vecSave;

    public:
    // Constructores
    ArregloVectores();
    ~ArregloVectores(){}
    ArregloVectores(Vector arreglo, int vecSave);

    // Setters
    void setArreglo(Vector arreglo);
    void setVecSave(int vecSave);

    // Getter
    Vector getArreglo();
    int getVecSave();

    // Funciones

};

#endif