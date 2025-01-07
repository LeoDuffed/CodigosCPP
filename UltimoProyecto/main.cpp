//
// Creado por Leonardo Martinez Peña
// Programa usando Herencia y POO
//
#include "Personaje.h"
#include "Guerrero.h"
#include <iostream>
using namespace std;

int main() {

    Personaje miPersonaje("Rick", 100,1, 20, 5, 10, 10, 1 ); // Peronaje uno
    cout << "\nPersonaje 1" << endl;
    cout << "Nombre: " << miPersonaje.getNombre() << endl;
    cout << "Vida: " << miPersonaje.getVida() << endl;
    cout << "Nivel: " << miPersonaje.getNivel() << endl;
    cout << "Velocidad de ATK: " << miPersonaje.getVelocidadATK() << endl;

    Guerrero miGuerrero("Thor", 100, 5, 20, 15, 10, 8, 5, 30, 5, 10);// Guerrero 1
    cout << "\nGuerrero 1" << endl;
    cout << "Nombre: " << miGuerrero.getNombre() << endl;
    cout << "Vida: " << miGuerrero.getVida() << endl;
    cout << "Nivel: " << miGuerrero.getNivel() << endl;
    cout << "Fuerza: " << miGuerrero.getFuerza() << endl;
    cout << "Regeneración de Vida: " << miGuerrero.getRegeneracionVida() << endl;
    cout << "Bloqueo: " << miGuerrero.getBloqueo() << endl;

    // Nuevos atributos para el guerrero
    miGuerrero.setFuerza(50);
    miGuerrero.setRegeneracionVida(10);

    cout << "\nFuerza actualizada: " << miGuerrero.getFuerza() << endl;
    cout << "Regeneración de Vida actualizada: " << miGuerrero.getRegeneracionVida() << endl;

    return 0;
}
