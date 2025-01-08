// 
// Creado por Leonardo Martínez Peña
//
#ifndef Caballero_H
#define Caballero_H
#include "Picaro.h"
#include <iostream> 
using namespace std;

class Caballero : public Personaje{

    private:
        int carga;
        int intimidar;
        int fortalecer;
    
    public:
        Caballero();
        ~Caballero(){}
        Caballero(string nombre, int vida, int nivel, int defenzaFisica, int defenzaMagica, int velocidadMovimiento, int velocidadATK, int rango, int carga, int intimidar, int fortalecer);

        void setCarga(int carga);
        void setIntimidar(int intimidar);
        void setFortalecer(int fortalecer);

        int getCarga();
        int getIntimidar();
        int getFortalecer();

        void toString();
        void danioCarga();
        void intimidacion();

};

#endif