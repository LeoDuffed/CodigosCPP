#ifndef SERIE_H
#define SERIE_H
#include "Video.h"
#include "Episodio.h"

class Serie : public Video{
    private: 
        Episodio* capSeries;
        int numCap;
        int maxCap;
    public: 
        Serie(int id, std :: string nombre, int hora, int min, std :: string genero, int calificacion);
        ~Serie();
        std :: string getNombre() const;
        void agregarEpisodio(std :: string titulo, int temp, int calificacion);
        void mostrarVideos() const override;
};

#endif