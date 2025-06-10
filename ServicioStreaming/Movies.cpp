#include "Movies.h"

Movies :: Movies(int id, std :: string nombre, int hora, int min, std :: string genero, int calificacion) : 
Video(id, nombre, hora, min, genero, calificacion){}

void Movies :: mostrarVideos() const{
    std :: cout << "\n\nPelicula: " << nombre << std :: endl;
    std :: cout << "Genero: " << genero << std :: endl;
    std :: cout << "Duracion: " << hora << " : " << min << std :: endl;
    std :: cout << "Calificacion: " <<  calificacion << std :: endl;
}