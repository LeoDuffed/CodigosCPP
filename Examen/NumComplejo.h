#ifndef NUMCOMPLEJO_H
#define NUMCOMPLEJO_H
#pragma once
#include <iostream> 

class NumComplejo{
    private: 
    int a;
    int b;

    public: 
    // Constructores y Destructor
    NumComplejo();
    ~NumComplejo(){}
    NumComplejo(int a, int b);

    // Setter
    void setA(int a);
    void setB(int b);

    // Getters
    int getA();
    int getB();

    // Funciones
    void imprimir();
    NumComplejo suma(int a2, int b2);
    NumComplejo resta(int a2, int b2);

};

#endif