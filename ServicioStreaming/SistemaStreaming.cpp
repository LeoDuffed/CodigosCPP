#include "SistemaStreaming.h"
#include <iostream>
#include <typeinfo>

SistemaStreaming::SistemaStreaming() : total(0) {}

void SistemaStreaming::agregarVideo(Video* v) {
    if (total < 100) videos[total++] = v;
}

void SistemaStreaming::mostrarTodos() const {
    for (int i = 0; i < total; ++i)
        videos[i]->mostrar();
}

void SistemaStreaming::mostrarPeliculas() const {
    for (int i = 0; i < total; ++i)
        if (dynamic_cast<Pelicula*>(videos[i]))
            videos[i]->mostrar();
}

void SistemaStreaming::mostrarSeries() const {
    for (int i = 0; i < total; ++i)
        if (dynamic_cast<Serie*>(videos[i]))
            videos[i]->mostrar();
}

void SistemaStreaming::mostrarPorGenero(std::string genero) const {
    for (int i = 0; i < total; ++i)
        if (videos[i]->getGenero() == genero)
            videos[i]->mostrar();
}

void SistemaStreaming :: mostrarPorCalif(int calif) const{
    for(int i = 0; i < total; i++){
        if(videos[i] -> getCalificacion() == calif){
            videos[i] -> mostrar();
        }
    }
} 
