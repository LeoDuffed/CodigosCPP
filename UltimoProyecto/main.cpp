//
// Creado por Leonardo Martinez Peña
// Programa usando Herencia y POO
//
#include "Personaje.h"
#include "Guerrero.h"
#include "Arquero.h"
#include <iostream>
using namespace std;

int main() {

    Personaje miPersonaje("Rick", 100,1, 20, 5, 10, 10, 1 ); // Peronaje uno
    cout << "\nPersonaje 1" << endl;
    miPersonaje.toString();

    Guerrero miGuerrero("Thor", 100, 5, 20, 15, 10, 8, 5, 30, 5, 10);// Guerrero 1 
    cout << "\nGuerrero 1" << endl;
    miGuerrero.toString();

    // Nuevos atributos para el guerrero
    miGuerrero.setFuerza(50);
    miGuerrero.setRegeneracionVida(10);
    cout << "\nNuevos atributos Guerrero 1: " << endl;
    miGuerrero.toString();

    // Metodo de intimidar de la clase Guerrero
    cout << "\nHaciendo que el guerrero intimide..." << endl;
    miGuerrero.intimidar();

    // Metodo de embestir de la clase Guerrro
    cout << "\nHaciendo que el guerrero embista..." << endl;
    miGuerrero.embestir();

    Arquero miArquero("Ojo verde",100,1, 20, 5, 10, 10, 1, 80, 3, 90, 30); // Arquerio uno
    cout << "\nArquero 1" << endl;
    miArquero.toString();

    cout << "\nHaciendo que el archero lanze una flecha venenosa..." << endl;
    miArquero.flechaVenenosa();

    cout << "\nHaciendo que el arquero haga un disparo preciso..." << endl;
    miArquero.DisparoPreciso();

    return 0;
}
