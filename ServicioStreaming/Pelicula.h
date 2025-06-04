#ifndef PELICULA_H
#define PELICULA_H

#include "Video.h"

class Pelicula : public Video {
public:
    Pelicula(int id, std::string nombre, int hora, int min, std::string genero, int calif);
    
    void mostrar() const override;

    bool operator>(const Pelicula& otra) const; // ejemplo de sobrecarga
};

#endif
