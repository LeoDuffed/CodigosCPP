#ifndef MOVIES_H
#define MOVIES_H
#include "Video.h"

class Movies : public Video{
    public: 
        Movies(int id, std :: string nombre, int hora, int min, std :: string genero, int calificacion);
        void mostrarVideos() const override;
};

#endif