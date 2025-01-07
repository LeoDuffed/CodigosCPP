// Creado por Leonardo Martinez Peña
#ifndef Personaje_H
#define Personaje_H
#include <iostream> 
using namespace std;

class Personaje{

    protected: 
    string nombre;
    int vida;
    int nivel;
    int defenzaFisica;
    int defenzaMagica;
    int velocidadMovimiento;
    int velocidadATK;
    int rango;
    public:

    Personaje();
    ~Personaje(){}
    Personaje(string nombre, int vida, int nivel, int defenzaFisica, int defenzaMagica, int velocidadMovimiento, int velocidadATK, int rango);
    
    void setNombre(string nombre);
    void setVida(int vida);
    void setNivel(int nivel);
    void setDefenzaFisica(int defenzaFisica);
    void setDefenzaMagica(int defenzaMagica);
    void setVelocidadMovimiento(int velocidadMovimiento);
    void setVelocidadATK(int velocidadATK);
    void setRango(int rango);

    string getNombre();
    int getNivel();
    int getVida();
    int getDefenzaFisica();
    int getDefenzaMagica();
    int getVelocidadMovimiento();
    int getVelocidadATK();
    int getRango();

    void toString();

};

#endif
