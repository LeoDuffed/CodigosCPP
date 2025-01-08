//
// Creado por Leonardo Martinez Peña
// Programa usando Herencia y POO
//
#include "Personaje.h"
#include "Guerrero.h"
#include "Arquero.h"
#include "Sacerdote.h"
#include "Mago.h"
#include "Picaro.h"
#include "Caballero.h"
#include <iostream>
using namespace std;

int main() {

    Personaje miPersonaje("Rick", 100,1, 20, 5, 10, 10, 1 ); // Peronaje uno
    cout << "\nPersonaje" << endl;
    miPersonaje.toString();

    Guerrero miGuerrero("Thor", 100, 5, 20, 15, 10, 8, 5, 30, 5, 10);// Guerrero 1 
    cout << "\nGuerrero" << endl;
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

    Arquero miArquero("Ojo verde",100,1, 20, 5, 10, 10, 1, 80, 3, 90, 30); // Arquero uno
    cout << "\nArquero" << endl;
    miArquero.toString();

    // Metodo flechaVenenosa de la clse Arquero
    cout << "\nHaciendo que el archero lanze una flecha venenosa..." << endl;
    miArquero.flechaVenenosa();

    // Metodo disparoPreciso de la clase Arquero
    cout << "\nHaciendo que el arquero haga un disparo preciso..." << endl;
    miArquero.DisparoPreciso();

    Mago miMago("Valtazar", 100, 5, 23, 20, 10, 8, 40, "Volver de la muerte", 3, "De lo muertos", 3); // Mago uno
    cout << "\nMago" << endl;
    miMago.toString();

    // Metodo echizado de la clase Mago
    cout << "\nHaciendo que el mago lanze echizo..." << endl;
    miMago.echizado();

    // Metodo teletransportado de la clase Mago
    cout << "\nHaciendo que el mago se teletransporte..." << endl;
    miMago.teletransportado();

    Sacerdote miSacerdote("Popope", 100, 5, 23, 20, 10, 8, 40, 20, 90, 100); // Sacerdote uno
    cout << "\nSacerdote" << endl;
    miSacerdote.toString();

    // Metodo curarEquipo de la clase Sacerdote
    cout << "\nHaciendo que el mago cure al equipo..." << endl;
    miSacerdote.curarEquipo();

    // Metodo protejerEquipo de la clase Sacerdote
    cout << "\nHaciendo que el mago proteja al equipo..." << endl;
    miSacerdote.protejerEquipo();

    Picaro miPicaro("Julslol", 100,1, 20, 5, 10, 10, 1, 50, 30, 4); // Picaro uno
    cout << "\nPicaro" << endl;
    miPicaro.toString();

    // Metodo danioCritico de la clase Picaro
    cout << "\nHaciendo que el picaro haga daño critico..." << endl;
    miPicaro.danioCritico();

    // Metodo numeroVolteretas de la clase Picaro
    cout << "\nHaciendo que el picaro haga volteretas..." << endl;
    miPicaro.numeroVolteretas();

    Caballero miCaballero("Duffed", 100,21, 20, 5, 10, 10, 1, 70, 80, 50); // Caballero uno
    cout << "\nCaballero: " << endl;
    miCaballero.toString();

    // Metodo danioCarga de la clase Caballero
    cout << "\nHaciendo que el caballero haga una carga..." << endl;
    miCaballero.danioCarga();

    // Metodo intimidacion de la clase Caballero
    cout << "\nHaciendo que el cabalero intimide..." << endl;
    miCaballero.intimidacion();

    return 0;
}
