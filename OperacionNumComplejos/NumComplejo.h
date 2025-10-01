#ifndef NUMCOMPLEJO_H
#define NUMCOMPLEJO_H
#pragma once
#include <iostream> 

class NumComplejo{
    int a{};
    int b{};

    public: 
    // Constructores y Destructor
    NumComplejo() = default;
    NumComplejo(int a, int b) : a(a), b(b) {}
    ~NumComplejo() = default;

    // Setter
    void setA(int v) {a = v;}
    void setB(int v) {b = v;}

    // Getters
    int getA() const {return a;}
    int getB() const {return b;}

    // Operadores de salida
    NumComplejo operator+(const NumComplejo& o) const;
    NumComplejo operator-(const NumComplejo& o) const;
    friend std::ostream& operator<<(std::ostream& os, const NumComplejo& c);

};

#endif