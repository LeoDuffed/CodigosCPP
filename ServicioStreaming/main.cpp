#include "StreamHub.h"
#include <fstream>
#include <sstream>

// Esta funcion que recibe por referencia un objeto de tipo StreamHub
void cargarDatos(StreamHub& sistem){ 
    
    // Codigo para cargar las Peliculas
    std :: ifstream archivoMovies("db/movies.csv");
    std :: string allMovies;

    while(getline(archivoMovies, allMovies)){
        std :: stringstream ss(allMovies);
        std :: string idStr, nombre, horaStr, minStr, genero, calificacionStr;

        getline(ss, idStr, ',');
        getline(ss, nombre, ',');
        getline(ss, horaStr, ',');
        getline(ss, minStr, ',');
        getline(ss, genero, ',');
        getline(ss, calificacionStr, ',');

        /*
            La funcion "stoi" es una abreviatura de "cadena a entero"
            y sirve para convertir una cadena de caracteres (string) 
            a un valor entero (int).
        */
        int id = std :: stoi(idStr);
        int hora = std :: stoi(horaStr);
        int min = std :: stoi(minStr);
        int calificacion = std :: stoi(calificacionStr);

        // Vamos agegando las peliculas que vamos sacando del .csv
        sistem.addVideos(new Movies(id, nombre, hora, min, genero, calificacion));
    }
    archivoMovies.close();

    // Codigo para cargar Series
    std :: ifstream archivoSeries("db/series.csv");
    std :: string allSeries;
    getline(archivoSeries, allSeries);

    const int MAX_SERIES = 50; // Maximo 50 series 
    Serie* seriesCargadas[MAX_SERIES];// Creamos un arreglo de la clase Serie con 50 espacios
    int seriesTotal = 0;

    /*
        Los datos se leen en std, por eso el nombre de mis variables que tienen valores int
        llevan el Str al final, para luego cambiarlos a int.
    */ 
    while(getline(archivoSeries, allSeries)){
        std :: stringstream ss(allSeries);
        std :: string idStr, nombre, horaStr, minStr, genero, calificacionStr;
        std :: string tituloCap, tempStr, calificacionCapStr;

        getline(ss, idStr, ',');
        getline(ss, nombre, ',');
        getline(ss, horaStr, ',');
        getline(ss, minStr, ',');
        getline(ss, genero, ',');
        getline(ss, calificacionStr, ',');
        getline(ss, tituloCap, ',');
        getline(ss, tempStr, ',');
        getline(ss, calificacionCapStr, ',');

        int id = stoi(idStr);
        int hora = stoi(horaStr);
        int min = stoi(minStr);
        int calificacion = stoi(calificacionStr);
        int temporada = stoi(tempStr);
        int calificacionCap = stoi(calificacionCapStr);

        Serie* authSerie = nullptr;

        // Para ver si ya cargamos una serie con el mismo nombre
        for(int i = 0; i < seriesTotal; i++){
            if(seriesCargadas[i] -> getNombre() == nombre){
                authSerie = seriesCargadas[i];
                break;
            }
        }

        // Si no existia, la cargamos 
        if(!authSerie){
            authSerie = new Serie(id, nombre, hora, min, genero, calificacion);
            seriesCargadas[seriesTotal++] = authSerie;
            sistem.addVideos(authSerie);
        }

        authSerie -> addEpisod(tituloCap, temporada, calificacionCap); // Agregamos los episodios
        
    }

    archivoSeries.close();

    std :: cout << "Se han cargado las series con exito :))" <<  std :: endl;
}

// Main
int main(){
    StreamHub sistema;

    std :: cout << "\n\nNecesitas cargar los datos antes de usar el programa" << std :: endl;

    int eleccion = -1;
    // Menu 
    while(eleccion != 0){
        std :: cout << "\n\n\nBienvenido a servicio de streaming DUFF" << std :: endl;
        std :: cout << "Menu:" << std :: endl;
        std :: cout << "1. Cargar archivo de datos" << std :: endl;
        std :: cout << "2. Mostrar videos por calificación o género "<< std :: endl;
        std :: cout << "3. Mostrar series con cierta calificación" << std :: endl;
        std :: cout << "4. Mostrar películas con cierta calificación" << std :: endl;
        std :: cout << "5. Mostrar los episodios de una determinada serie con una calificacion determinada" << std :: endl;
        std :: cout << "6. Calificar un video" << std :: endl;
        std :: cout << "0. Salir" << std :: endl;
        std :: cout << "Elige opción: ";
        std :: cin >> eleccion;

        switch (eleccion) {
            case 1: {
                cargarDatos(sistema);
                break;
            }
            case 2:{
                int calif;
                std :: string genero;
                std :: cout << "\n\nIngresa calificación (-1 si no aplica): ";
                std :: cin >> calif;
                // Mostramos los generos que hay 
                std::cout << "\nGéneros disponibles:\n";
                std::cout << " - accion\n";
                std::cout << " - animacion\n";
                std::cout << " - aventura\n";
                std::cout << " - biografia\n";
                std::cout << " - ciencia ficcion\n";
                std::cout << " - comedia\n";
                std::cout << " - drama\n";
                std::cout << " - fantasia\n";
                std::cout << " - guerra\n";
                std::cout << " - misterio\n";
                std::cout << " - musical\n";
                std::cout << " - romance\n";
                std :: cout << "\nIngresa género (deja vacío si no aplica): ";
                std :: cin.ignore();
                /*
                    Se usa getline() para leer una linea completa de texto en un 
                    flujo de entrada, incluyendo espacios y otros caracteres.
                    Se almacena en una cadena str.
                */
                getline(std :: cin, genero);

                for (int i = 0; i < 100; ++i) {
                    if (sistema.getVideo(i)) {
                        if ((calif == -1 || sistema.getVideo(i) -> getCalificacion() == calif) && (genero.empty() || sistema.getVideo(i) -> getGenero() == genero)) {
                            sistema.getVideo(i) -> mostrarVideos();
                        }
                    }
                }
                break;
            }
            case 3:{
                int calificacion;
                std :: cout << "\n\nSeries" << std :: endl; 
                std :: cout << "Que calificacion buscas: ";
                std :: cin >> calificacion;
                sistema.mostrarSeriesPorCalif(calificacion); 
                break;
            }
            case 4:{
                int calificacion;
                std :: cout << "\n\nPeliculas" << std :: endl;
                std :: cout << "Que calificacion buscas: ";
                std :: cin >> calificacion;
                sistema.mostrarMoviesPorCalif(calificacion); 
                break;
            }
            case 5:{
                /*
                    Ocupe cin.ignore para ignorar caracteres en el flujo de entrada
                    es util para limpiar el bufer de entrada, en especial despues de
                    leer datos con cin.
                */
                std :: cin.ignore();
                std :: string nomSerie;
                int calif;
                // Mostramos las series disponibles
                std::cout << "\nSeries disponibles:\n";
                std::cout << " - Peaky Blinders\n";
                std::cout << " - Mindhunter\n";
                std::cout << " - Better Call Saul\n";
                std::cout << " - Mr. Robot\n";
                std::cout << " - Narcos\n";
                std::cout << " - Ozark\n";
                std::cout << " - The Haunting of Hill House\n";
                std::cout << " - The Umbrella Academy\n";
                std::cout << " - BoJack Horseman\n";
                std::cout << " - The Last Kingdom\n";
                std::cout << " - Hannibal\n";
                std::cout << " - Brooklyn Nine-Nine\n";
                std::cout << " - The Expanse\n";
                std::cout << " - The Good Place\n";
                std::cout << " - Fargo\n";
                std::cout << " - Succession\n";
                std::cout << " - Severance\n";
                std::cout << " - The Bear\n";
                std::cout << " - Barry\n";
                std::cout << " - Ted Lasso\n";
                std::cout << " - Foundation\n";
                std::cout << " - Invincible\n";
                std::cout << " - Reacher\n";
                std::cout << " - Vikings\n";
                std::cout << " - Resident Alien\n";
                std :: cout << "\nIngresa el nombre de la serie: ";
                std :: getline(std :: cin, nomSerie);

                std :: cout << "\nIngresa la calificacion que buscas: ";
                std :: cin >> calif;

                sistema.buscarCapPorCalif(nomSerie, calif);
                break;
            }
            case 6:{
                std :: cin.ignore(); 
                std :: string titulo;
                int newCalif;

                std :: cout << "\n\nIngresa el título: ";
                getline(std :: cin, titulo);

                bool encontrado = false;

                for (int i = 0; i < 100; ++i) {
                    /*
                        Se obtiene el video en la posición i 
                        (puede ser una película o serie), ya 
                        que Video es una clase abstracta
                    */
                    Video* vid = sistema.getVideo(i);
                    if (vid && vid -> getNombre() == titulo) {
                        vid -> mostrarVideos();

                        std :: cout << "Que calificacion le das? (1 al 5): ";
                        std :: cin >> newCalif;

                        if (newCalif >= 1 && newCalif <= 5) {
                            vid -> setCalificacion(newCalif);
                            std :: cout << "Nueva calificacion!!\n";
                        } else {
                            std :: cout << "Calificación inválida.\n";
                        }

                        encontrado = true;
                        break;
                    }
                }
                if (!encontrado) {
                    std :: cout << "\n\nNo se encontró ningún video con ese título :(.\n";
                }
                break;
            }
            case 0: {
                std :: cout << "\n\nGracias por usar el programa. :) " << std :: endl;
                break;
            }
            default: {
                std :: cout << "\n\nOpción no válida." << std :: endl;
                break;
            }
        }
    }
}