//
// Creado por Leonardo Martinez Peña
//
#include <iostream> 
#include "Caballero.h"
using namespace std;

Caballero :: Caballero() : Personaje(){

    carga = 0;
    intimidar = 0;
    fortalecer = 0;

}

Caballero :: Caballero(string nombre, int vida, int nivel, int defenzaFisica, int defenzaMagica, int velocidadMovimiento, int velocidadATK, int rango, int carga, int intimidar, int fortalecer)
:Personaje(nombre, vida, nivel, defenzaFisica, defenzaMagica, velocidadMovimiento, velocidadATK, rango){
    
    this -> carga = carga;
    this -> intimidar = intimidar;
    this -> fortalecer = fortalecer;

}

void Caballero :: setCarga(int carga){
    this -> carga = carga;
}
void Caballero :: setIntimidar(int intimidar){
    this -> intimidar = intimidar;
}
void Caballero :: setFortalecer(int fortalecer){
    this -> fortalecer = fortalecer;
}

int Caballero :: getCarga(){
    return carga;
}
int Caballero :: getIntimidar(){
    return intimidar;
}
int Caballero :: getFortalecer(){
    return fortalecer;
}

void Caballero :: toString(){

    Personaje :: toString();
    cout << "Carga: " << carga << endl;
    cout << "Intimidar: " << intimidar << endl;
    cout << "Fortalecer: " << fortalecer << endl;

}

void Caballero :: danioCarga(){
    cout << nombre << " ha hecho una carga con un daño de " << carga << endl;
}
void Caballero :: intimidacion(){
    cout << nombre << " ha hecho un intimidacion de " << intimidar << endl;
}