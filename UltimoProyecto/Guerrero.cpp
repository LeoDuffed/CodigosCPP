//
// Creado por Leonardo Martinez Peña
//
#include "Guerrero.h"
#include <iostream> 
using namespace std;

Guerrero :: Guerrero() : Personaje(){

    fuerza = 0;
    regeneracionVida = 0;
    bloqueo = 0;
}

Guerrero :: Guerrero(string nombre, int vida, int nivel, int defenzaFisica, int defenzaMagica, int velocidadMovimiento, int velocidadATK, int rango, int fuerza, int regeneracionVida, int bloqueo) 
: Personaje(nombre, vida, nivel, defenzaFisica, defenzaMagica, velocidadMovimiento, velocidadATK, rango){

    this -> fuerza = fuerza;
    this -> regeneracionVida = regeneracionVida;
    this -> bloqueo = bloqueo;

}

void Guerrero :: setFuerza(int fuerza){
    this -> fuerza = fuerza;
}
void Guerrero :: setRegeneracionVida(int regeneracionVida){
    this -> regeneracionVida = regeneracionVida;
}
void Guerrero :: setBloqueo(int bloqueo){
    this -> bloqueo = bloqueo;
}

int Guerrero :: getFuerza(){
    return fuerza;
}
int Guerrero :: getRegeneracionVida(){
    return regeneracionVida;
}
int Guerrero :: getBloqueo(){
    return bloqueo;
}

