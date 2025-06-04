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
    s1->agregarEpisodio("Capítulo 1", 1, 4.5);
    s1->agregarEpisodio("Capítulo 2", 1, 4.7);
    sistema.agregarVideo(s1);

    Serie* s2 = new Serie(2, "The Mandalorian", 0, 40, "accion");
    s2->agregarEpisodio("Chapter 1", 1, 4.8);
    s2->agregarEpisodio("Chapter 2", 1, 4.6);
    sistema.agregarVideo(s2);

    Serie* s3 = new Serie(3, "Breaking Bad", 0, 47, "drama");
    s3->agregarEpisodio("Pilot", 1, 5);
    s3->agregarEpisodio("Cat's in the Bag", 1, 4.9);
    sistema.agregarVideo(s3);

    Serie* s4 = new Serie(4, "The Witcher", 0, 52, "fantasia");
    s4->agregarEpisodio("The End's Beginning", 1, 4.5);
    s4->agregarEpisodio("Four Marks", 1, 4.3);
    sistema.agregarVideo(s4);

    Serie* s5 = new Serie(5, "Loki", 0, 42, "ciencia ficcion");
    s5->agregarEpisodio("Glorious Purpose", 1, 4.6);
    s5->agregarEpisodio("The Variant", 1, 4.4);
    sistema.agregarVideo(s5);

    Serie* s6 = new Serie(6, "WandaVision", 0, 36, "fantasia");
    s6->agregarEpisodio("Filmed Before a Live Studio Audience", 1, 4.3);
    s6->agregarEpisodio("Don't Touch That Dial", 1, 4.2);
    sistema.agregarVideo(s6);

    Serie* s7 = new Serie(7, "Game of Thrones", 0, 58, "drama");
    s7->agregarEpisodio("Winter Is Coming", 1, 4.9);
    s7->agregarEpisodio("The Kingsroad", 1, 4.7);
    sistema.agregarVideo(s7);

    Serie* s8 = new Serie(8, "The Office", 0, 22, "comedia");
    s8->agregarEpisodio("Diversity Day", 1, 4.6);
    s8->agregarEpisodio("Health Care", 1, 4.5);
    sistema.agregarVideo(s8);

    Serie* s9 = new Serie(9, "Friends", 0, 24, "comedia");
    s9->agregarEpisodio("The One Where Monica Gets a Roommate", 1, 4.7);
    s9->agregarEpisodio("The One with the Sonogram at the End", 1, 4.6);
    sistema.agregarVideo(s9);

    Serie* s10 = new Serie(10, "Sherlock", 0, 90, "misterio");
    s10->agregarEpisodio("A Study in Pink", 1, 5);
    s10->agregarEpisodio("The Blind Banker", 1, 4.7);
    sistema.agregarVideo(s10);

    Serie* s11 = new Serie(11, "Dark", 0, 50, "misterio");
    s11->agregarEpisodio("Secrets", 1, 4.8);
    s11->agregarEpisodio("Lies", 1, 4.9);
    sistema.agregarVideo(s11);

    Serie* s12 = new Serie(12, "Black Mirror", 0, 60, "ciencia ficcion");
    s12->agregarEpisodio("The National Anthem", 1, 4.1);
    s12->agregarEpisodio("Fifteen Million Merits", 1, 4.5);
    sistema.agregarVideo(s12);

    Serie* s13 = new Serie(13, "Arcane", 0, 44, "animacion");
    s13->agregarEpisodio("Welcome to the Playground", 1, 4.9);
    s13->agregarEpisodio("Some Mysteries Are Better Left Unsolved", 1, 4.8);
    sistema.agregarVideo(s13);

    Serie* s14 = new Serie(14, "The Boys", 0, 60, "accion");
    s14->agregarEpisodio("The Name of the Game", 1, 4.7);
    s14->agregarEpisodio("Cherry", 1, 4.6);
    sistema.agregarVideo(s14);

    Serie* s15 = new Serie(15, "House of the Dragon", 0, 55, "drama");
    s15->agregarEpisodio("The Heirs of the Dragon", 1, 4.8);
    s15->agregarEpisodio("The Rogue Prince", 1, 4.6);
    sistema.agregarVideo(s15);

    std :: cout << "Bienvenido a servicio de streaming HULUB" << std :: endl;
    std :: cout << "Menu: " << std :: endl;
    std :: cout << "1. Mostrar Peliculas" << std :: endl;
    std :: cout << "2. Mostrar Series" << std :: endl;
    std :: cout << "3. Buscar por genero" << std :: endl;
    std :: cout << "4. Mostrar Todo" << std :: endl;
    std :: cout << "0. Salir" << std :: endl;
    std :: cout << "Elige opcion: ";
    int opp;
    std :: cin >> opp;

    std :: string gen;
    switch(opp)
    {
    case 1:
        sistema.mostrarPeliculas();
        break;
    case 2: 
        sistema.mostrarSeries();
        break;
    case 3: 
        std :: cout << "Ingresa el genero : ";
        std :: cin >> gen;
        sistema.mostrarPorGenero(gen);
        break;
    case 4:
        sistema.mostrarTodos();
    default:
        break;
    }

    return 0;
}
