#include "StreamHub.h"
#include <fstream>
#include <sstream>
#include <vector> // Uso vector para guardar los vides en un arreglo

// Esta funcion que recibe por referencia un objeto de tipo StreamHub
void cargarDatos(StreamHub& sistem){ 
    // Codigo para cargar datos de Peliculas
    std :: ifstream archivoPeliculas("movies.csv"); // 
    // Va a almacenar cada linea del archivo leido con 'getline'
    std :: string allPeliculas;

    while(getline(archivoPeliculas, allPeliculas)){
        // Creamos un stream de texto a partir de la linea leida del documetno
        std :: stringstream ss(allPeliculas); 
        // Almacenamos las partes separadas de la linea como el id, el nombre, y las otras
        std :: vector<std :: string> espacios; 
        std :: string espacio;

        while(getline(ss, espacio, ',')){
            espacios.push_back(espacio);
        }

        // Cargamos cada espacio del vector con la informacion de cada pelicula
        if(espacios.size() > 5){
            int id = stoi(espacios[0]);
            std :: string nombre = espacios[1];
            int hora = stoi(espacios[2]);
            int min = stoi(espacios[3]);
            std :: string genero = espacios[4];
            int calificacion = stoi(espacios[5]);

            Movies* newMovie = new Movies(id, nombre, hora, min, genero, calificacion);
            sistem.addVideos(newMovie);
        }
    }

    archivoPeliculas.close();

    // Codigo para cargar datos de Series
    std :: ifstream archivoSeries("Series.csv");
    std :: string allSeries;

    int MAX_SERIES = 50;
    Serie* seriesCargadas[MAX_SERIES]; // Arreglo maximo de 50 espacios
    int totalSeries = 0;

    while(getline(archivoSeries, allSeries)){
        std :: stringstream ss(allSeries);
        std :: vector<std :: string> espacios;
        std :: string espacio;

        while(getline(ss, espacio, ',')){
            espacios.push_back(espacio);
        }

        if(espacios.size() >= 9){
            int id = stoi(espacios[0]);
            std :: string nombre = espacios[1];
            int hora = stoi(espacios[2]);
            int min = stoi(espacios[3]);
            std :: string genero = espacios[4];
            int calificacion = stoi(espacios[5]);
            std :: string tituloEpi = espacios[6];
            int temporada = stoi(espacios[7]);
            int califCap = stoi(espacios[8]);
            
            Serie* authSeries = nullptr;
            /*
                Itera sobre todas las series que se cargaron y si encuentra 
                una serie cuyo nombre coincide con el que se esta leyendo en
                la linea del archivo, se guarda un puntero a esa serie.
            */
            for(int i = 0; i < totalSeries; i++){
                if(seriesCargadas[i] -> getNombre() == nombre){
                    authSeries = seriesCargadas[i];
                    break;
                }
            }
            /*
                Si no encontro una serie con ese nombre en la if pasado, 
                creamos una nueva instancia de la clase Serie, se agrega
                al arreglo de seriesCargadas, se incrementa el contado 
                total de series "totalSeries" y se agrega con addVideos 
                para que se pueda imprimir despues.
            */
            if(!authSeries){ // Si no encuentra una serie con el nombre 
                authSeries = new Serie(id, nombre, hora, min, genero, calificacion);
                seriesCargadas[totalSeries++] = authSeries;
                sistem.addVideos(authSeries);
            }

            authSeries -> addEpisod(tituloEpi, temporada, califCap);
        }
    }
    archivoSeries.close();

    std :: cout << "\n\nDatos cargados con exito!!" << std :: endl;
}

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
        std :: cout << "5. Calificar un video" << std :: endl;
        std :: cout << "0. Salir" << std :: endl;
        std :: cout << "Elige opción: ";
        std :: cin >> eleccion;

        switch (eleccion) {
            case 1: {
                cargarDatos(sistema);
                break;
            }

            case 2: {
                int calif;
                std :: string genero;
                std :: cout << "\n\nIngresa calificación (-1 si no aplica): ";
                std :: cin >> calif;
                std :: cout << "Ingresa género (deja vacío si no aplica): ";
                std :: cin.ignore();
                getline(std :: cin, genero);

                for (int i = 0; i < 100; ++i) {
                    if (sistema.getVideo(i)) {
                        if ((calif == -1 || sistema.getVideo(i) -> getCalificacion() == calif) &&
                            (genero.empty() || sistema.getVideo(i) -> getGenero() == genero)) {
                            sistema.getVideo(i) -> mostrarVideos();
                        }
                    }
                }
                break;
            }

            case 3: {
                int calificacion;
                std :: cout << "\n\nQue calificacion buscas: ";
                std :: cin >> calificacion;
                sistema.mostrarSeriesPorCalif(calificacion); 
                break;
            }

            case 4: {
                int calificacion;
                std :: cout << "\n\nQue calificacion buscas: ";
                std :: cin >> calificacion;
                sistema.mostrarMoviesPorCalif(calificacion); 
                break;
            }

            case 5: {
                std :: cin.ignore(); 
                std :: string titulo;
                int newCalif;

                std :: cout << "\n\nIngresa el título: ";
                getline(std :: cin, titulo);

                bool encontrado = false;

                for (int i = 0; i < 100; ++i) {
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