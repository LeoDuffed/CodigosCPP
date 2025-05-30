#ifndef ARREGLOCOMPLEJOS_H
#define ARREGLOCOMPLEJOS_H
#include <iostream> 
#include "NumComplejo.h"

class ArregloComplejos{
    private:
    NumComplejo arreglo[6];
    int nextSpace;

    public: 
    // Constructores y Destructor
    ArregloComplejos();
    ~ArregloComplejos(){}
    ArregloComplejos(int nextSpace);

    // Funciones y Metodos
    bool agregar(NumComplejo arreglo);
    NumComplejo restaTotal();
    void mostrarArray();

};

#endif