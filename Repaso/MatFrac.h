#ifndef MATFRAC_H
#define MATFRAC_H

// Valores de las columnas y las filas Maximo
#define MaxRow 10
#define MaxCol 10

#include <iostream>
#include "Fracciones.h"
using namespace std;

class MatFrac{
    
    private:
    Fracciones matriz; 
    unsigned int row;
    unsigned int col;

    public:
    // Constructores
    MatFrac();
    ~MatFrac(){}
    MatFrac(Fracciones matriz, unsigned int row, unsigned int col);

    //Setters
    void setMatriz(Fracciones matriz);
    void setRow(unsigned int row);
    void setCol(unsigned int col);

    //Getter
    Fracciones getMatriz();
    unsigned int getRow();
    unsigned int getCol();


};

#endif