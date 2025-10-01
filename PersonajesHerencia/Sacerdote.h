//
// Creado por Leonardo Martinez Peña
//
#ifndef Sacerdote_H
#define Sacerdote_H
#include "Mago.h"
#include <iostream>
using namespace std;

class Sacerdote : public Personaje{

    private: 
        int curacion;
        int proteccion;
        int purificacion;
    public:
        Sacerdote();
        ~Sacerdote(){}
        Sacerdote(string nombre, int vida, int nivel, int defenzaFisica, int defenzaMagica, int velocidadMovimiento, int velocidadATK, int rango, int curacion, int proteccion, int purificacion);

        void setCuracion(int curacion);
        void setProteccion(int proteccion);
        void setPurificacion(int purificacion);

        int getCuracion();
        int getProteccion();
        int getPurificacion();

        void toString();
        void curarEquipo();
        void protejerEquipo();


};

#endif