#include "Serie.h"

Serie :: Serie(int id, std :: string nombre, int hora, int min, std :: string genero, int calificacion) :
Video(id, nombre, hora, min, genero, calificacion), numCap(0), maxCap(10){
    capSeries = new Episodio[maxCap];
}