#ifndef VIDEO_H
#define VIDEO_H
#include <string>

class Video {
protected:
    std::string id;
    std::string nombre;
    float duracion;
    std::string genero;
    float calificacion;

public:
    Video(std::string id, std::string nombre, float duracion, std::string genero, float calif);
    virtual void mostrar() const = 0; // método puro
    float getCalificacion() const;
    std::string getGenero() const;
    virtual ~Video() {}
};

#endif
