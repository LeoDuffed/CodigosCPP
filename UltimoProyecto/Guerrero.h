//
// Creado por Leonardo Martinez Peña
//
#ifndef Guerrero_H
#define Guerrero_H
#include "Personaje.h"
#include <iostream> 
using namespace std;

class Guerrero : public Personaje{

    private:
        int fuerza;
        int regeneracionVida;
        int bloqueo;

    public: 
        Guerrero();
        ~Guerrero(){}
        Guerrero(string nombre, int vida, int nivel, int defenzaFisica, int defenzaMagica, int velocidadMovimiento, int velocidadATK, int rango, int fuerzam, int regeneracionVida, int bloqueo);

        void setFuerza(int fuerza);
        void setRegeneracionVida(int regeneracionVida);
        void setBloqueo(int bloqueo);

        int getFuerza();
        int getRegeneracionVida();
        int getBloqueo();

        void intimidar();
        void emebestir();


};

#endif