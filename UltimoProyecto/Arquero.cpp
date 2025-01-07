#include "Arquero.h"
#include <iostream> 
using namespace std;

Arquero :: Arquero() : Personaje(){

    habilidadArco = 0;
    criticos = 0;
    precision = 0;
    evasion = 0;

}

Arquero :: Arquero(string nombre, int vida, int nivel, int defenzaFisica, int defenzaMagica, int velocidadMovimiento, int velocidadATK, int rango, int habilidadArco, int criticos, int precision, int evasion)
:Personaje(nombre, vida, nivel, defenzaFisica, defenzaMagica, velocidadMovimiento, velocidadATK, rango){

    this -> habilidadArco = habilidadArco;
    this -> criticos = criticos;
    this -> precision = precision;
    this -> evasion = evasion;

}

void Arquero :: setHabilidadArco(int habilidadArco){
    this -> habilidadArco = habilidadArco;
}
void Arquero :: setCriticos(int criticos){
    this -> criticos = criticos;
}
void Arquero :: setPrecision(int precision){
    this -> precision = precision;
}
void Arquero :: setEvacion(int evasion){
    this -> evasion = evasion;
}

int Arquero :: getHabilidadArco(){
    return habilidadArco;
}
int Arquero :: getCriticos(){
    return criticos;
}
int Arquero :: getPrecision(){
    return precision;
}
int Arquero :: getEvasion(){
    return evasion;
}

void Arquero :: toString(){
    
    Personaje :: toString();
    cout << "Habilidad con arco: " << habilidadArco << endl;
    cout << "ATK critico: " << criticos << endl;
    cout << "Precision: " << precision << endl;
    cout << "Evasion de daño: " << evasion << endl;
}

void Arquero :: flechaVenenosa(){
    cout << nombre << " ha lanzado una flecha venenosa con su habilidad de arco de " << habilidadArco << endl; 
}

void Arquero :: DisparoPreciso(){
    cout << nombre << " ha hecho un disparo preciso con su precision de " << precision << endl;
}
