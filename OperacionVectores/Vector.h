#ifndef VECTOR_H
#define VECTOR_H
#pragma once
#include <iostream> 

class Vector{

    private: 
    int x;
    int y;
    int z;

    public: 
    // Constructores y Desctructor
    Vector();
    ~Vector(){}
    Vector(int x, int y, int z);

    // Setter
    void setX(int x);
    void setY(int y);
    void setZ(int z);

    // Getter
    int getX();
    int getY();
    int getZ();
    

    // Funciones y Metodos
    void MostrarVec();
    Vector suma(int x, int y, int z);
    Vector resta(int x, int y, int z);

};

#endif