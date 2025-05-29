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
    Fracciones matriz[MaxRow][MaxCol]; 
    unsigned int row;
    unsigned int col;

    public:
    // Constructores
    MatFrac();
    ~MatFrac(){}
    MatFrac(unsigned int row, unsigned int col, Fracciones valores[MaxRow][MaxCol]);

    //Setters
    void setRow(unsigned int row);
    void setCol(unsigned int col);

    //Getter
    Fracciones getElemento(unsigned int i, unsigned int j);
    unsigned int getRow();
    unsigned int getCol();

    // Funciones
    bool leeArchivos(string fileName);
    MatFrac suma(MatFrac& otra);
    void Mostrar();
    void guardarEnArchivo(string fileName);

};

#endif