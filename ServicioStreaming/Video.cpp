// Clase base, Pelicula y Episodio Heredan de esta
#include "Video.h"
#include <iostream>

// Constructor 
Video::Video(int id, std::string nombre, int hora, int min, std::string genero, int calif){
    this -> id = id;
    this -> nombre = nombre;
    this -> hora = hora;
    this -> min = min;
    this -> genero = genero;
    this -> calif = calif;
}
// Getters
int Video::getCalificacion() const {
    return calif;
}
std::string Video::getGenero() const {
    return genero;
}