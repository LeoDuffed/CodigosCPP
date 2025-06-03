#include "Serie.h"
#include <iostream>

Serie::Serie(std::string id, std::string nombre, float duracion, std::string genero)
    : Video(id, nombre, duracion, genero, 0), totalEpisodios(0), capacidad(10) {
    episodios = new Episodio[capacidad];
}

Serie::~Serie() {
    delete[] episodios;
}

void Serie::agregarEpisodio(std::string titulo, int temporada, float calif) {
    if (totalEpisodios >= capacidad) return; // sin redimensionar para simplicidad
    episodios[totalEpisodios++] = {titulo, temporada, calif};

    float suma = 0;
    for (int i = 0; i < totalEpisodios; ++i)
        suma += episodios[i].calificacion;
    calificacion = suma / totalEpisodios;
}

void Serie::mostrar() const {
    std::cout << "📺 Serie: " << nombre << " | Genero: " << genero
              << " | Calificación promedio: " << calificacion << "/5\n";
    for (int i = 0; i < totalEpisodios; ++i) {
        std::cout << "   - T" << episodios[i].temporada << ": " << episodios[i].titulo
                  << " (" << episodios[i].calificacion << "/5)\n";
    }
}
