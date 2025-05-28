#include "MatFrac.h"

// Constructores
MatFrac :: MatFrac(){
    Fracciones matriz[row][col];
    unsigned int row = 0;
    unsigned int col = 0;
}

MatFrac :: MatFrac(Fracciones matriz, unsigned int row, unsigned int col){
    this -> matriz = matriz;
    this -> row = row;
    this -> col = col;
}

// Setter
void MatFrac :: setMatriz(Fracciones matriz){
    this -> matriz = matriz;
}
void MatFrac :: setRow(unsigned int row){
    if(row >10){
        this -> row = MaxRow;
    } else {
        this -> row = row;
    }
}
void MatFrac :: setCol(unsigned int col){
    if(col >10){
        this -> col = MaxCol;
    } else {
        this -> col = col;
    }
}

// Getter
Fracciones MatFrac :: getMatriz(){
    return matriz;
}
unsigned int MatFrac :: getRow(){
    return row;
}
unsigned int MatFrac :: getCol(){
    return col;
}
