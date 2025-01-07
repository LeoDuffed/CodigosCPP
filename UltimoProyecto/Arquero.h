//
// Creado por Leonardo Martinez Peña
//
#ifndef Arquero_H
#define Arquero_H
#include "Guerrero.h"
#include <iostream> 
using namespace std;

class Arquero : public Personaje{

    private:
        int habilidadArco;
        int criticos;
        int precision;
        int evasion;

    public: 
        Arquero();
        ~Arquero(){}
        Arquero(string nombre, int vida, int nivel, int defenzaFisica, int defenzaMagica, int velocidadMovimiento, int velocidadATK, int rango, int habilidadArco, int criticos, int precision, int evasion);

    void setHabilidadArco(int habilidadArco);
    void setCriticos(int criticos);
    void setPrecision(int precision);
    void setEvacion(int evasion);

    int getHabilidadArco();
    int getCriticos();
    int getPrecision();
    int getEvasion();

    void toString();
    void flechaVenenosa();
    void DisparoPreciso();
    void Trampas();

};

#endif