#include "StreamHub.h"

StreamHub :: StreamHub() : total(0){}

Video* StreamHub :: getVideo(int index) const{
    if(index >= 0 && index < total){
        return videos[index];
    }
    return nullptr;
}
void StreamHub :: addVideos(Video* vid){
    if(total < 100){
        videos[total++] = vid;
    }
}
void StreamHub :: mostrarTodo() const{
    for(int i = 0; i < total; i++){
        videos[i] -> mostrarVideos();
    }
}
/* Documentacion dynamic_cast: 
    El operador dynamic_cast en C++ es una herramienta para 
    realizar conversiones de tipo en tiempo de ejecución, 
    especialmente útiles en jerarquías de clases. Su principal 
    objetivo es convertir un puntero o una referencia de una 
    clase base a un puntero o una referencia de una clase 
    derivada, asegurando que la conversión sea válida
*/
void StreamHub :: mostrarMoviesPorCalif(int calificacion) const{
    for(int i = 0; i < total; i++){
        if(dynamic_cast<Movies*>(videos[i]) && videos[i] -> getCalificacion() == calificacion){
            videos[i] -> mostrarVideos();
        }
    }
}
void StreamHub :: mostrarSeriesPorCalif(int calificacion) const{
    for(int i = 0; i < total; i++){
        if(dynamic_cast<Serie*>(videos[i]) && videos[i] -> getCalificacion() == calificacion){
            videos[i] -> mostrarVideos();
        }
    }
}
void StreamHub :: buscarCapPorCalif(const std :: string& nomSerie, int calificacion) const{
    bool founded = false; // Para ver si se encontro lo que se busca

    for(int i = 0; i < total; i++){
        Serie* serie = dynamic_cast<Serie*>(videos[i]);

        if(serie && serie -> getNombre() == nomSerie){
            founded = true;
             std :: cout << "\nEpisodios de " << nomSerie << " con calificacion de " << calificacion << ": " << std :: endl;

             bool coinciden = false; 
             for(int j = 0; j < 10; j++){
                Episodio cap = serie -> getEpisodio(j);
                if(!cap.titulo.empty() && cap.calificacion == calificacion){
                    std :: cout << "    -T" << cap.temoporada << ": " << cap.titulo << " (" << cap.calificacion << "/5)" << std :: endl;
                    coinciden = true;
                }
             }
             if(!coinciden){
                std :: cout << "\nNo se encontro ninguna serie con esa calificacion" << std :: endl;
             }
             break;
        }
    }
    if(!founded){
        std :: cout << "\nNo se econtro ninguna serie con el nombre " << nomSerie << std :: endl;
    }
}
