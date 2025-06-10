#ifndef STREAMHUB_H
#define STREAMHUB_H
#include "Video.h"
#include "Movies.h"
#include "Serie.h"

class StreamHub{
    private: 
        Video* videos[50];
        int total;
    public: 
        StreamHub();
        //Esta función sirve para acceder a un video guardado en la posición index del arreglo videos.
        Video* getVideo(int index) const;
        void addVideos(Video* vid);
        void mostrarTodo() const;
        void mostrarMovies() const;
        void mostrarSeries() const;
        void mostrarPorCalif(int calificacion) const;
};

#endif