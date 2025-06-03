#include "SistemaStreaming.h"
#include <iostream>

int main() {
    SistemaStreaming sistema;

    // Agregamos películas
    sistema.agregarVideo(new Pelicula("P001", "Inception", 148, "ciencia ficcion", 4.8));
    sistema.agregarVideo(new Pelicula("P002", "Titanic", 195, "drama", 4.9));

    // Agregamos serie
    Serie* s1 = new Serie("S001", "Stranger Things", 45, "misterio");
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
