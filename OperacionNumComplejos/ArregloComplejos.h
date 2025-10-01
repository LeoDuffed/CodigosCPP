#ifndef ARREGLOCOMPLEJOS_H
#define ARREGLOCOMPLEJOS_H
#include <iostream> 
#include "NumComplejo.h"

class ArregloComplejos{
    static constexpr int CAP = 6;
    NumComplejo arreglo[CAP]{};
    int nextSpace{0};

    public: 
    // Constructores y Destructor
    ArregloComplejos() = default;
    explicit ArregloComplejos(int next) : nextSpace(next){}

    // Funciones y Metodos
    bool agregar(const NumComplejo& num);
    NumComplejo restaTotal() const;
    void mostrarArray() const;

};

#endif