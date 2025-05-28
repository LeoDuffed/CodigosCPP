#ifndef MATFRAC_H
#define MATFRAC_H

// Valores de las columnas y las filas Maximo
#define MaxRow 10
#define MaxCol 10

#include "Fracciones.h"
#include <iostream>
#include <fstream> // Libreria para cargar archivos
using namespace std;

class MatFrac{
    
    private:
    // Variables
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

    // Funciones
    bool leeArchivos(string fileName);

};

#endif