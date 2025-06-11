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
