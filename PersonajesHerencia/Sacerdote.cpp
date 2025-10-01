// 
// Creado por Leonardo Martínz Peña
// 
#include "Sacerdote.h"
#include <iostream> 
using namespace std;

Sacerdote :: Sacerdote() : Personaje(){

    curacion = 0; 
    proteccion = 0; 
    purificacion = 0;

}

Sacerdote :: Sacerdote(string nombre, int vida, int nivel, int defenzaFisica, int defenzaMagica, int velocidadMovimiento, int velocidadATK, int rango, int curacion, int proteccion, int purificacion)
:Personaje(nombre, vida, nivel, defenzaFisica, defenzaMagica, velocidadMovimiento, velocidadATK, rango){

    this -> curacion = curacion;
    this -> proteccion = proteccion;
    this -> purificacion = purificacion;

}

void Sacerdote :: setCuracion(int curacion){
    this -> curacion = curacion;
}
void Sacerdote :: setProteccion(int proteccion){
    this -> proteccion = proteccion;
}
void Sacerdote :: setPurificacion(int purificacion){
    this -> purificacion = purificacion;
}

int Sacerdote :: getCuracion(){
    return curacion;
}
int Sacerdote :: getProteccion(){
    return proteccion;
}
int Sacerdote :: getPurificacion(){
    return purificacion;
}

void Sacerdote :: toString(){

    Personaje :: toString();
    cout << "Curacion: " << curacion << endl;
    cout << "Proteccion: " << proteccion << endl;
    cout << "Purificacion: " << purificacion << endl;

}

void Sacerdote :: curarEquipo(){
    cout << nombre << " ha curado al equipo " << curacion << " de su vida inicial" << endl;
}
void Sacerdote :: protejerEquipo(){
    cout << nombre << " ha protegido al equipo " << proteccion << " del daño enemigo" << endl;
}
