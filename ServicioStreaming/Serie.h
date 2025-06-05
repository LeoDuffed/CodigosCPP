#ifndef SERIE_H
#define SERIE_H

#include "Video.h"
#include "Episodio.h"

class Serie : public Video {
private:
    Episodio* episodios;
    int capitulos;
    int maxEpisodios;

public:
    // Constructor y Destructor
    Serie(int id, std::string nombre, int hora, int min, std::string genero, int calif);
    ~Serie();
    // Metodos 
    void agregarEpisodio(std::string titulo, int temporada, int calif);
    void mostrar() const override;
};

#endif
