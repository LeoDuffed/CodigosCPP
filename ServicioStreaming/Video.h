#ifndef VIDEO_H
#define VIDEO_H
#include <iostream>

class Video{
    
    protected:
        int id;
        std :: string nombre;
        int hora;
        int min;
        std :: string genero;
        int calificacion;

    public:
        Video(int id, std :: string nombre, int hora, int min, std :: string genero, int calificacion);
        virtual ~Video(){} 
        void setCalificacion(int calificacion); // Para asignar una nueva calificacion
        std :: string getNombre() const ;
        int getCalificacion() const;
        std :: string getGenero() const;
        virtual void mostrarVideos() const = 0;
        /* Por que use const = 0:
        En C++, const = 0 en una función virtual indica que 
        se trata de una función virtual pura. 
        Esto implica que la clase que la declara es una 
        clase abstracta y que las clases derivadas deben 
        sobrescribir (implementar) la función virtual pura. 
        const = 0 asegura que la clase base no tenga una 
        implementación para la función, obligando a las clases 
        derivadas a proporcionar una. 
        */

};

#endif