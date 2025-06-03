#include "Pelicula.h"
#include <iostream>

Pelicula::Pelicula(std::string id, std::string nombre, float duracion, std::string genero, float calif)
    : Video(id, nombre, duracion, genero, calif) {}

void Pelicula::mostrar() const {
    std::cout << "🎬 Pelicula: " << nombre << " | Genero: " << genero
              << " | Duracion: " << duracion << " mins"
              << " | Calificación: " << calificacion << "/5\n";
}

bool Pelicula::operator>(const Pelicula& otra) const {
    return calificacion > otra.calificacion;
}
