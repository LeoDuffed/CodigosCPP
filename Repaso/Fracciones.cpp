#include "Fracciones.h"

Fracciones :: Fracciones(){
    int numerador = 0;
    int denominador = 1;
}

Fracciones :: Fracciones(int numerador, int denominador){
    this -> numerador = numerador;
    this -> denominador = denominador;
}

// Setters
bool Fracciones :: setNumerador(int numerador){
    if(numerador < 0){ 
        cout << "Valor no permitido"<< endl;
        return false;
    } 
    this -> numerador = numerador;
    return true;
}
bool Fracciones :: setDenominador(int denominador){
        if(denominador <= 0){ 
        cout << "Valor no permitido"<< endl;
        return false;
    } 
    this -> denominador = denominador; 
    return true;
}

// Getters
int Fracciones :: getNumerador(){
    return numerador;
}
int Fracciones :: getDenominador(){
    return denominador;
}

// Funciones
void Fracciones :: mostrarFraccion(){
    cout << "Fraccion reducida: " << endl;
    cout << numerador << " / " << denominador << endl;
}
int Fracciones :: mcd(int a, int b) { // Me fusile esta funcion del net
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
void Fracciones :: simplificar(){
    int divisor = mcd(numerador, denominador);
    numerador /= divisor;
    denominador /= divisor;

    Fracciones frac(numerador, denominador);
    frac.mostrarFraccion();

}
void Fracciones :: suma(int num, int den){
    int newDen = denominador * den;
    int a = numerador * den;
    int b = num * denominador;
    int newNum = a + b;

    Fracciones resultado(newNum, newDen);
    cout << "Resultado de la suma: " << endl;
    resultado.simplificar();
}



