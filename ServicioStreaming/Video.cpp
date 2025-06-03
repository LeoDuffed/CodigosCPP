#include "Video.h"
#include <iostream>

Video::Video(std::string id, std::string nombre, float duracion, std::string genero, float calif)
    : id(id), nombre(nombre), duracion(duracion), genero(genero), calificacion(calif) {}

float Video::getCalificacion() const {
    return calificacion;
}

std::string Video::getGenero() const {
    return genero;
}
