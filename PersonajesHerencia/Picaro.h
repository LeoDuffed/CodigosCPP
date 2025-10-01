//
// Creado por Leonardo Martínez Peña
//
#ifndef Picaro_H
#define Picaro_H
#include "Sacerdote.h"
#include <iostream> 
using namespace std;

class Picaro : public Personaje{

    private: 
        int golpeCritico;
        int ataqueFurtivo;
        int voltereta;  
    
    public:    
        Picaro();
        ~Picaro(){}
        Picaro(string nombre, int vida, int nivel, int defenzaFisica, int defenzaMagica, int velocidadMovimiento, int velocidadATK, int rango, int golpeCritico, int ataqueFurtivo, int voltereta);

        void setGolpeCritico(int golpeCritico);
        void setAtaqueFurtivo(int ataqueFurtivo);
        void setVoltereta(int voltereta);

        int getGolpeCritico();
        int getAtaqueFurtivo();
        int getVoltereta();

        void toString();
        void danioCritico();
        void numeroVolteretas();

};

#endif