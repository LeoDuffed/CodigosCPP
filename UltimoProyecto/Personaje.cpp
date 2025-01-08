// Creado por Leonardo Martinez Peña
#include "Personaje.h"
#include <iostream> 
using namespace std;

Personaje :: Personaje(){

    nombre = "";
    vida = 0;
    nivel = 0;
    defenzaFisica = 0;
    defenzaMagica = 0;
    velocidadMovimiento = 0;
    velocidadATK = 0;
    rango = 0;

}

Personaje :: Personaje (string nombre, int vida, int nivel, int defenzaFisica, int defenzaMagica, int velocidadMovimiento, int velocidadATK, int rango){

    this -> nombre = nombre;
    this -> vida = vida;
    this -> nivel = nivel;
    this -> defenzaFisica = defenzaFisica;
    this -> defenzaMagica = defenzaMagica;
    this -> velocidadMovimiento = velocidadMovimiento;
    this -> velocidadATK = velocidadATK;
    this -> rango = rango;

}

void Personaje :: setNombre(string nombre){
    this -> nombre = nombre;
}
void Personaje :: setVida(int vida){
    this -> vida = vida;
}
void Personaje :: setNivel(int nivel){
    this -> nivel = nivel;
}
void Personaje :: setDefenzaFisica(int defenzaFisica){
    this -> defenzaFisica = defenzaFisica;
}
void Personaje :: setDefenzaMagica(int defenzaMagica){
    this -> defenzaMagica = defenzaMagica;
}
void Personaje :: setVelocidadMovimiento(int velocidadMovimiento){
    this -> velocidadMovimiento = velocidadMovimiento;
}
void Personaje :: setVelocidadATK(int velocidadATK){
    this -> velocidadATK = velocidadATK;
}
void Personaje :: setRango(int rango){
    this -> rango = rango;
}

string Personaje :: getNombre(){
    return nombre;
}
int Personaje :: getNivel(){
    return nivel;
}
int Personaje :: getVida(){
    return vida;
}
int Personaje :: getDefenzaFisica(){
    return defenzaFisica;
}
int Personaje :: getDefenzaMagica(){
    return defenzaMagica;
}
int Personaje :: getVelocidadMovimiento(){
    return velocidadMovimiento;
}
int Personaje :: getVelocidadATK(){
    return velocidadATK;
}
int Personaje :: getRango(){
    return rango;
}

void Personaje :: toString(){

    cout << "Nombre: " << nombre << endl;
    cout << "Vida: " << vida << endl;
    cout << "Nivel: " << nivel << endl;
    cout << "Defenza Fisica: " << defenzaFisica << endl;
    cout << "Defenza Magica: " << defenzaMagica << endl;
    cout << "Velocidad Movimiento: " << velocidadMovimiento << endl;
    cout << "Velocidad de ATK: " << velocidadATK << endl;
    cout << "Rango: " << rango << endl;

}
