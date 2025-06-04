#ifndef SISTEMA_H
#define SISTEMA_H

#include "Video.h"
#include "Pelicula.h"
#include "Serie.h"

class SistemaStreaming {
private:
    Video* videos[100];
    int total;

public:
    SistemaStreaming();
    void agregarVideo(Video* v);
    void mostrarTodos() const;
    void mostrarPeliculas() const;
    void mostrarSeries() const;
    void mostrarPorGenero(std::string genero) const;
    void mostrarPorCalif(int calif) const;
};

#endif
