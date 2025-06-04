#include "SistemaStreaming.h"
#include <iostream>

int main() {
    SistemaStreaming sistema;

    // Agregamos películas
    sistema.agregarVideo(new Pelicula(1, "Inception", 1, 48, "ciencia ficcion", 5));
    sistema.agregarVideo(new Pelicula(2, "Titanic", 3,18, "drama", 4));

    // Agregamos serie
    Serie* s1 = new Serie(1, "Stranger Things", 0, 45, "misterio");
    s1->agregarEpisodio("Capítulo 1", 1, 4.5);
    s1->agregarEpisodio("Capítulo 2", 1, 4.7);
    sistema.agregarVideo(s1);

    // Reportes
    sistema.mostrarTodos();
    std::cout << "\n--- Solo películas ---\n";
    sistema.mostrarPeliculas();

    std::cout << "\n--- Series de misterio ---\n";
    sistema.mostrarPorGenero("misterio");

    return 0;
}
