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
/* Que es un struct?
    En C++, un struct (abreviatura de structure) es una estructura 
    de datos que sirve para agrupar múltiples variables 
    (campos o miembros) bajo un mismo nombre. Estas variables 
    pueden ser de distintos tipos. Un struct te permite organizar 
    información relacionada de una forma más lógica y manejable.
*/
struct Episodio{
    std :: string titulo;
    int temporada;
    int calificacion;
};

#endif

/* Aclaracion: 
    Ya habia hecho yo programas en C++ usando structs, en mi GitHub 
    hay varios programas en C++ con structs.
    Este es mi GitHub: https://github.com/LeoDuffed
*/ 