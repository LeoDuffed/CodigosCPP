#ifndef FRACCIONES_H
#define FRACCIONES_H
#include <iostream> 
using namespace std;

class Fracciones{
    private:
    int numerador;
    int denominador;

    public:
    Fracciones();
    ~Fracciones(){}
    Fracciones(int numerador , int denominador);

    // Setters 
    bool setNumerador(int numerador);
    bool setDenominador(int denominador);

    // Getters
    int getNumerador();
    int getDenominador();


    //Funciones y Metodos
    void mostrarFraccion();
    void simplificar();
    int mcd(int numerador, int denominador);


};

#endif