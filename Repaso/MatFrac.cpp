#include "MatFrac.h"

// Constructores
MatFrac :: MatFrac(){
    unsigned int row = 0;
    unsigned int col = 0;
}

MatFrac :: MatFrac(unsigned int row, unsigned int col, Fracciones valores[MaxRow][MaxCol]){
    this -> row = row;
    this -> col = col;
}

// Setter
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
Fracciones MatFrac :: getElemento(unsigned int i, unsigned int j){
    return matriz[i][j];
}
unsigned int MatFrac :: getRow(){
    return row;
}
unsigned int MatFrac :: getCol(){
    return col;
}

// Funciones
bool MatFrac :: leeArchivos(string nombre){
    ifstream file; // Lo cargamos
    unsigned int nRow, nCol;
    file.open(nombre); // Lo abrimos


    if(!file.is_open()){
        return false;
    } 
    if(!(file >> nRow) || !(file >> nCol)){
        file.close();
        return false;
    }

    cout << nRow << " , " << nCol << endl;

    if(nRow > MaxRow && nCol > MaxCol){
        file.close();
        return false;
    }

    cout << "Sigue funcionando" << endl;

    for(unsigned int i = 0; i < nRow; i++){
        for(unsigned int j = 0; j < nCol; j++){
            int n, d;

            cout << "Sigue funcionando" << endl;

            if(!(file >> n) || !(file >> d)){                
                file.close();
                return false;
            }

            Fracciones tmp(n,d);
            matriz[i][j] = tmp;
        }
    }

    row = nRow;
    col = nCol;

    file.close(); 
    return true;
}