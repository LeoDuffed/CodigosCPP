#ifndef EPISODIO_H
#define EPISODIO_H
#include <iostream>

/* 
    Ocupe un struct para usar lo en la clase Serie,
    para poder hacer esta codigo mas reutilizable en caso de que
    le quiera agregar otras opciones mas a mi clase Serie para cada 
    capitulo. Ademas de que mi codigo se ve mas organizado, es mucho
    mas facil manejar arreglos, para los capitulos de cada serie.
*/
struct Episodio{
    std :: string titulo;
    int temoporada;
    int calificacion;
};

#endif