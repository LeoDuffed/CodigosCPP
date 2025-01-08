#ifndef Mago_H
#define Mago_H
#include <iostream>
#include "Arquero.h"
using namespace std;

class Mago : public Personaje{

    private: 
        string invocacion;
        int bolaFuego;
        string maldicion;
        int teletransportarse;

    public: 
        Mago();
        ~Mago(){}
        Mago(string nombre, int vida, int nivel, int defenzaFisica, int defenzaMagica, int velocidadMovimiento, int velocidadATK, int rango, string invocacion, int bolaFuego, string maldicion,int teletransportarse);

        void setInvocacion(string invocacion);
        void setBolaFuego(int bolaFuego);
        void setMaldicion(string maldicion);
        void setTeletransportarse(int teletransportarse);

        string getInvocacion();
        int getBolaFuego();
        string getMaldicion();
        int getTeletransportarse();

        void toString();
        void echizado();
        void teletreansportado();

};

#endif 