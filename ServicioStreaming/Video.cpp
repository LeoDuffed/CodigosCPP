#include "Video.h"

Video :: Video(int id, std :: string nombre, int hora, int min, std :: string genero, int calificacion){
    this -> id = id;
    this -> nombre = nombre;
    this -> hora = hora;
    this -> min = min;
    this -> genero = genero;
    this -> calificacion = calificacion;
}
void Video :: setCalificacion(int calificacion){
    this -> calificacion = calificacion;
}
std :: string Video :: getNombre() const{
    return nombre;
}
int Video :: getCalificacion() const{
    return calificacion;
}
std :: string Video :: getGenero() const{ // Maybe no la usare.
    return genero;
}