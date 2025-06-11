#include "Serie.h"

Serie :: Serie(int id, std :: string nombre, int hora, int min, std :: string genero, int calificacion) :
Video(id, nombre, hora, min, genero, calificacion), numCap(0), maxCap(10){
    /* 
        Pedimos memoria dinamica para crear un arreglo de 
        maxCap de elementos de tipo Episodio.

        capSeries guarda la direccion de memoria de inicio del bloque.
    */
    capSeries = new Episodio[maxCap];
}

Serie :: ~Serie(){
    // Como estamos usando new, destruimos con delete
    delete[] capSeries; 
}

std :: string Serie :: getNombre() const{
    return nombre;
}

void Serie :: addEpisod(std :: string titulo, int temporada, int calificacion){
    // Este metodo esta hecho para agregar los episodios de cada serie

    if(numCap >= maxCap){
        return;
    }
    capSeries[numCap++] = {titulo, temporada, calificacion};

    float suma = 0;

    for(int i = 0; i < numCap; i++){
        suma += capSeries[i].calificacion;
    }
}
void Serie :: mostrarVideos() const{
    std :: cout << "\n\nSerie: " << nombre << std :: endl;
    std :: cout << "Genero: " << genero << std :: endl;
    std :: cout << "Calificacion de la serie: " << calificacion << std :: endl;
    for(int i = 0; i < numCap; i++){
        std :: cout << "    -T" << capSeries[i].temoporada << ": " << capSeries[i].titulo << " (" << capSeries[i].calificacion << "/5)" << std :: endl;
    }
}