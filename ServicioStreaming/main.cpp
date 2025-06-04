#include "SistemaStreaming.h"
#include <iostream>

int main() {
    SistemaStreaming sistema;

    // Agregamos películas
    sistema.agregarVideo(new Pelicula(1, "Inception", 1, 48, "ciencia ficcion", 5));
    sistema.agregarVideo(new Pelicula(2, "Titanic", 3,18, "drama", 4));
    sistema.agregarVideo(new Pelicula(3, "Interstellar", 2, 49, "ciencia ficcion", 5));
    sistema.agregarVideo(new Pelicula(4, "The Dark Knight", 2, 32, "accion", 5));
    sistema.agregarVideo(new Pelicula(5, "Shrek", 1, 35, "comedia", 4));
    sistema.agregarVideo(new Pelicula(6, "Toy Story", 1, 21, "animacion", 5));
    sistema.agregarVideo(new Pelicula(7, "The Matrix", 2, 16, "ciencia ficcion", 5));
    sistema.agregarVideo(new Pelicula(8, "Avatar", 2, 42, "fantasia", 4));
    sistema.agregarVideo(new Pelicula(9, "Gladiator", 2, 35, "accion", 4));
    sistema.agregarVideo(new Pelicula(10, "Coco", 1, 45, "infantil", 5));
    sistema.agregarVideo(new Pelicula(11, "Joker", 2, 2, "drama", 4));
    sistema.agregarVideo(new Pelicula(12, "Finding Nemo", 1, 40, "aventura", 5));
    sistema.agregarVideo(new Pelicula(13, "Up", 1, 36, "animacion", 5));
    sistema.agregarVideo(new Pelicula(14, "Frozen", 1, 42, "musical", 4));
    sistema.agregarVideo(new Pelicula(15, "Moana", 1, 47, "aventura", 4));
    sistema.agregarVideo(new Pelicula(16, "Spider-Man", 2, 1, "accion", 4));
    sistema.agregarVideo(new Pelicula(17, "Iron Man", 2, 6, "accion", 5));
    sistema.agregarVideo(new Pelicula(18, "Doctor Strange", 1, 55, "fantasia", 4));
    sistema.agregarVideo(new Pelicula(19, "Black Panther", 2, 15, "accion", 4));
    sistema.agregarVideo(new Pelicula(20, "The Lion King", 1, 29, "animacion", 5));
    sistema.agregarVideo(new Pelicula(21, "Encanto", 1, 39, "musical", 4));
    sistema.agregarVideo(new Pelicula(22, "Inside Out", 1, 34, "comedia", 5));


    // Agregamos serie
    Serie* s1 = new Serie(1, "Stranger Things", 0, 45, "misterio");
    s1->agregarEpisodio("Capítulo 1", 1, 4);
    s1->agregarEpisodio("Capítulo 2", 1, 5);
    sistema.agregarVideo(s1);

    Serie* s2 = new Serie(102, "The Mandalorian", 0, 45, "accion");
    s2->agregarEpisodio("Episodio 1 - The Mandalorian", 1, 4);
    s2->agregarEpisodio("Episodio 2 - The Mandalorian", 1, 5);
    s2->agregarEpisodio("Episodio 3 - The Mandalorian", 1, 4);
    s2->agregarEpisodio("Episodio 4 - The Mandalorian", 1, 5);
    sistema.agregarVideo(s2);

    Serie* s3 = new Serie(103, "Breaking Bad", 0, 45, "drama");
    s3->agregarEpisodio("Episodio 1 - Breaking Bad", 1, 4);
    s3->agregarEpisodio("Episodio 2 - Breaking Bad", 1, 5);
    s3->agregarEpisodio("Episodio 3 - Breaking Bad", 1, 4);
    s3->agregarEpisodio("Episodio 4 - Breaking Bad", 1, 5);
    sistema.agregarVideo(s3);

    Serie* s4 = new Serie(104, "The Witcher", 0, 45, "fantasia");
    s4->agregarEpisodio("Episodio 1 - The Witcher", 1, 4);
    s4->agregarEpisodio("Episodio 2 - The Witcher", 1, 5);
    s4->agregarEpisodio("Episodio 3 - The Witcher", 1, 4);
    s4->agregarEpisodio("Episodio 4 - The Witcher", 1, 5);
    sistema.agregarVideo(s4);

    Serie* s5 = new Serie(105, "Loki", 0, 45, "ciencia ficcion");
    s5->agregarEpisodio("Episodio 1 - Loki", 1, 4);
    s5->agregarEpisodio("Episodio 2 - Loki", 1, 5);
    s5->agregarEpisodio("Episodio 3 - Loki", 1, 4);
    s5->agregarEpisodio("Episodio 4 - Loki", 1, 5);
    sistema.agregarVideo(s5);

    Serie* s6 = new Serie(106, "WandaVision", 0, 45, "fantasia");
    s6->agregarEpisodio("Episodio 1 - WandaVision", 1, 4);
    s6->agregarEpisodio("Episodio 2 - WandaVision", 1, 5);
    s6->agregarEpisodio("Episodio 3 - WandaVision", 1, 4);
    s6->agregarEpisodio("Episodio 4 - WandaVision", 1, 5);
    sistema.agregarVideo(s6);

    Serie* s7 = new Serie(107, "Game of Thrones", 0, 45, "drama");
    s7->agregarEpisodio("Episodio 1 - Game of Thrones", 1, 4);
    s7->agregarEpisodio("Episodio 2 - Game of Thrones", 1, 5);
    s7->agregarEpisodio("Episodio 3 - Game of Thrones", 1, 4);
    s7->agregarEpisodio("Episodio 4 - Game of Thrones", 1, 5);
    sistema.agregarVideo(s7);

    Serie* s8 = new Serie(108, "The Office", 0, 45, "comedia");
    s8->agregarEpisodio("Episodio 1 - The Office", 1, 4);
    s8->agregarEpisodio("Episodio 2 - The Office", 1, 5);
    s8->agregarEpisodio("Episodio 3 - The Office", 1, 4);
    s8->agregarEpisodio("Episodio 4 - The Office", 1, 5);
    sistema.agregarVideo(s8);

    Serie* s9 = new Serie(109, "Friends", 0, 45, "comedia");
    s9->agregarEpisodio("Episodio 1 - Friends", 1, 4);
    s9->agregarEpisodio("Episodio 2 - Friends", 1, 5);
    s9->agregarEpisodio("Episodio 3 - Friends", 1, 4);
    s9->agregarEpisodio("Episodio 4 - Friends", 1, 5);
    sistema.agregarVideo(s9);

    Serie* s10 = new Serie(110, "Sherlock", 0, 45, "misterio");
    s10->agregarEpisodio("Episodio 1 - Sherlock", 1, 4);
    s10->agregarEpisodio("Episodio 2 - Sherlock", 1, 5);
    s10->agregarEpisodio("Episodio 3 - Sherlock", 1, 4);
    s10->agregarEpisodio("Episodio 4 - Sherlock", 1, 5);
    sistema.agregarVideo(s10);

    Serie* s11 = new Serie(111, "Dark", 0, 45, "misterio");
    s11->agregarEpisodio("Episodio 1 - Dark", 1, 4);
    s11->agregarEpisodio("Episodio 2 - Dark", 1, 5);
    s11->agregarEpisodio("Episodio 3 - Dark", 1, 4);
    s11->agregarEpisodio("Episodio 4 - Dark", 1, 5);
    sistema.agregarVideo(s11);

    Serie* s12 = new Serie(112, "Black Mirror", 0, 45, "ciencia ficcion");
    s12->agregarEpisodio("Episodio 1 - Black Mirror", 1, 4);
    s12->agregarEpisodio("Episodio 2 - Black Mirror", 1, 5);
    s12->agregarEpisodio("Episodio 3 - Black Mirror", 1, 4);
    s12->agregarEpisodio("Episodio 4 - Black Mirror", 1, 5);
    sistema.agregarVideo(s12);

    Serie* s13 = new Serie(113, "Arcane", 0, 45, "animacion");
    s13->agregarEpisodio("Episodio 1 - Arcane", 1, 4);
    s13->agregarEpisodio("Episodio 2 - Arcane", 1, 5);
    s13->agregarEpisodio("Episodio 3 - Arcane", 1, 4);
    s13->agregarEpisodio("Episodio 4 - Arcane", 1, 5);
    sistema.agregarVideo(s13);

    Serie* s14 = new Serie(114, "The Boys", 0, 45, "accion");
    s14->agregarEpisodio("Episodio 1 - The Boys", 1, 4);
    s14->agregarEpisodio("Episodio 2 - The Boys", 1, 5);
    s14->agregarEpisodio("Episodio 3 - The Boys", 1, 4);
    s14->agregarEpisodio("Episodio 4 - The Boys", 1, 5);
    sistema.agregarVideo(s14);

    Serie* s15 = new Serie(115, "The Crown", 0, 45, "drama");
    s15->agregarEpisodio("Episodio 1 - The Crown", 1, 4);
    s15->agregarEpisodio("Episodio 2 - The Crown", 1, 5);
    s15->agregarEpisodio("Episodio 3 - The Crown", 1, 4);
    s15->agregarEpisodio("Episodio 4 - The Crown", 1, 5);
    sistema.agregarVideo(s15);

    std :: cout << "Bienvenido a servicio de streaming HULUB" << std :: endl;
    std :: cout << "Menu: " << std :: endl;
    std :: cout << "1. Mostrar Peliculas" << std :: endl;
    std :: cout << "2. Mostrar Series" << std :: endl;
    std :: cout << "3. Buscar por calificacion" << std :: endl;
    std :: cout << "4. Mostrar Todo" << std :: endl;
    std :: cout << "0. Salir" << std :: endl;
    std :: cout << "Elige opcion: ";
    int opp;
    std :: cin >> opp;

    std :: string gen;
    int cali;
    switch(opp)
    {
    case 1:
        sistema.mostrarPeliculas();
        break;
    case 2: 
        sistema.mostrarSeries();
        break;
    case 3: 
        std :: cout << "Ingresa la calificacion que buscar: ";
        std :: cin >> cali;
        sistema.mostrarPorCalif(cali);
        break;
    case 4:
        sistema.mostrarTodos();
        break;
    case 0: 
        std :: cout << "\n\nGracias por usar el programa" << std :: endl;
        break;
    default:
        break;
    }

    return 0;
}
