// 
// Creado por Leonardo Martínez Peña
//
#include <iostream> 
#include "Picaro.h"
using namespace std;

Picaro :: Picaro() : Personaje(){

    golpeCritico = 0;
    ataqueFurtivo = 0;
    voltereta = 0;
}

Picaro :: Picaro(string nombre, int vida, int nivel, int defenzaFisica, int defenzaMagica, int velocidadMovimiento, int velocidadATK, int rango, int golpeCritico, int ataqueFurtivo, int voltereta) 
:Personaje(nombre, vida, nivel, defenzaFisica, defenzaMagica, velocidadMovimiento, velocidadATK, rango){

    this -> golpeCritico = golpeCritico;
    this -> ataqueFurtivo = ataqueFurtivo;
    this -> voltereta = voltereta;

}

void Picaro :: setGolpeCritico(int golpeCritico){
    this -> golpeCritico = golpeCritico;
}
void Picaro :: setAtaqueFurtivo(int ataqueFurtivo){
    this -> ataqueFurtivo = ataqueFurtivo;
}
void Picaro :: setVoltereta(int voltereta){
    this -> voltereta = voltereta;
}

int Picaro :: getGolpeCritico(){
    return golpeCritico;
}
int Picaro :: getAtaqueFurtivo(){
    return ataqueFurtivo;
}
int Picaro :: getVoltereta(){
    return voltereta;
}

void Picaro :: toString(){
    
    Personaje :: toString();
    cout << "Golpe critico: " << golpeCritico << endl;
    cout << "Ataque furtivo: " << ataqueFurtivo << endl;
    cout << "Numero de volteretas: " << voltereta << endl;
}

void Picaro :: danioCritico(){
    cout << nombre << " ha hecho un ataque con un daño critico de " << golpeCritico << endl;
}
void Picaro :: numeroVolteretas(){
    cout << nombre << " ha hecho " << voltereta << " volteretas" << endl;
}