#ifndef SERIE_H
#define SERIE_H
#include "Video.h"
#include "Episodio.h"

// Clase Padre, esta es la clase abstracta
// Movies y Series heredan de esta

class Serie : public Video{
    private: 
        Episodio* capSeries;
        int numCap;
        int maxCap;
    public: 
        Serie(int id, std :: string nombre, int hora, int min, std :: string genero, int calificacion);
        ~Serie();
        std :: string getNombre() const;
        Episodio getEpisodio(int index) const;
        void addEpisod(std :: string titulo, int temp, int calificacion);
        void mostrarVideos() const override;
};

#endif