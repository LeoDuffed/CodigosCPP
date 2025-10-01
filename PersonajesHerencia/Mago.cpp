//
// Creado por Leonardo Martinez Peña
//
#include "Mago.h"
#include <iostream> 
using namespace std;

Mago :: Mago() : Personaje(){

    invocacion = " ";
    bolaFuego = 0;
    maldicion = " ";
    teletransportarse = 0;

}

Mago :: Mago(string nombre, int vida, int nivel, int defenzaFisica, int defenzaMagica, int velocidadMovimiento, int velocidadATK, int rango, string invocacion, int bolaFuego, string maldicion, int teletransportarse)
:Personaje (nombre, vida, nivel, defenzaFisica, defenzaMagica, velocidadMovimiento, velocidadATK, rango){

    this -> invocacion = invocacion;
    this -> bolaFuego = bolaFuego;
    this -> maldicion = maldicion;
    this -> teletransportarse = teletransportarse;

}

void Mago :: setInvocacion(string invocacion){
    this -> invocacion = invocacion;
}
void Mago :: setBolaFuego(int bolaFuego){
    this -> bolaFuego = bolaFuego;
}
void Mago :: setMaldicion(string maldicion){
    this -> maldicion = maldicion;
}
void Mago :: setTeletransportarse(int teletransportarse){
    this -> teletransportarse = teletransportarse;
}

string Mago :: getInvocacion(){
    return invocacion;
}
int Mago :: getBolaFuego(){
    return bolaFuego;
}
string Mago :: getMaldicion(){
    return maldicion;
}
int Mago :: getTeletransportarse(){
    return teletransportarse;
}

void Mago :: toString(){

    Personaje :: toString();
    cout << "Invocacion: " << invocacion << endl;
    cout << "Cantidad de bolas de fuego: " << bolaFuego << endl;
    cout << "Maldicion: " << maldicion << endl;
    cout << "Chunks teletransportados: " << teletransportarse << endl;
}

void Mago :: echizado(){
    cout << nombre << " ha hecho el echizo " << maldicion << endl;
}
void Mago :: teletransportado(){
    cout << nombre << " se ha teletransportado " << teletransportarse << " chunks" << endl;
}