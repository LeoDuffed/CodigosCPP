#include "Pelicula.h"
#include <iostream>

Pelicula::Pelicula(int id, std::string nombre, int hora, int min, std::string genero, int calif)
    : Video(id, nombre, hora, min, genero, calif) {}

void Pelicula::mostrar() const {
    std::cout << "Pelicula: " << nombre << " | Genero: " << genero
              << " | Duracion: " << hora << " : " << min 
              << " | Calificación: " << calif << "/5\n";
}

bool Pelicula::operator>(const Pelicula& otra) const {
    return calif > otra.calif;
}
