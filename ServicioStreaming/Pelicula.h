#ifndef PELICULA_H
#define PELICULA_H

#include "Video.h"

class Pelicula : public Video {
public:
    Pelicula(std::string id, std::string nombre, float duracion, std::string genero, float calif);
    void mostrar() const override;

    bool operator>(const Pelicula& otra) const; // ejemplo de sobrecarga
};

#endif
