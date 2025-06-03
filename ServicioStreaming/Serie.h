#ifndef SERIE_H
#define SERIE_H

#include "Video.h"
#include "Episodio.h"

class Serie : public Video {
private:
    Episodio* episodios;
    int totalEpisodios;
    int capacidad;

public:
    Serie(std::string id, std::string nombre, float duracion, std::string genero);
    ~Serie();
    void agregarEpisodio(std::string titulo, int temporada, float calif);
    void mostrar() const override;
};

#endif
