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

    for(unsigned int i = 0; i < nRow; i++){
        for(unsigned int j = 0; j < nCol; j++){
            int n, d;

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
void MatFrac :: Mostrar(){
    for(unsigned int i = 0; i < row; i++){
        for(unsigned int j = 0; j < col; j++){
            cout << "[" << matriz[i][j].getNumerador() << " / " << matriz[i][j].getDenominador() << "]  ";
        }
        cout << endl;
    }
}
MatFrac MatFrac :: suma(MatFrac matriz2){
    MatFrac resultado;

    if(row != matriz2.row || col != matriz2.col){
        resultado.row = 0;
        resultado.col = 0;
        return resultado;
    }

    resultado.row = row;
    resultado.col = col;

    for(unsigned int i = 0; i < row; i++){
        for(unsigned int j = 0; j < col; j++){
            int num1 = matriz[i][j].getNumerador();
            int den1 = matriz[i][j].getDenominador();

            int num2 = matriz2.matriz[i][j].getNumerador();
            int den2 = matriz2.matriz[i][j].getDenominador();

            int newNum = num1 * den2 + num2 * den1;
            int newDen = den1 * den2;

            Fracciones suma(newNum, newDen);
            resultado.matriz[i][j] = suma;
        }
    }
    return resultado;
}
void MatFrac :: guardarEnArchivo(string nombre){
    ofstream file(nombre);

    if(!file.is_open()){
        cout << "No se puedo habrir el archivo" << endl;
        return;
    }

    file << row << " " << col << endl;
    for(unsigned int i = 0; i < row; i++){
        for(unsigned int j = 0; j < col; j++){
            file << matriz[i][j].getNumerador() << " " << matriz[i][j].getDenominador() << "  ";
        }
        file << endl;
    }
    file.close();
}