#ifndef VIDEO_H
#define VIDEO_H
#include <string>

class Video {
protected:
    int id;
    std::string nombre;
    int hora;
    int min;
    std::string genero;
    int calif;

public:
    // Contructor y Destructor
    Video(int id, std::string nombre, int hora,int min, std::string genero, int calif);
    virtual ~Video() {}
    // Getter
    int getCalificacion() const;
    std::string getGenero() const;
    // Funciones
    virtual void mostrar() const = 0;
    
};

#endif
