#ifndef VIDEO_H
#define VIDEO_H
#include <iostream>

// Clase Padre, esta es la clase abstracta
// Movies y Series heredan de esta

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
        /*
            En C++ la palabra reservada "virtual" se utiliza para
            declarar una funcion miembro de una clase base qeu se 
            espera que sea redefinida en las clases derivadas.
        */
        virtual ~Video(){} 
        void setCalificacion(int calificacion); // Para asignar una nueva calificacion
        /*
            La palabra recervada const, en este contexto, sirve para indicar
            que una funcion no midificara el objeto o los argumentos que recibe.
            Esto ayuda a la seguridad del codigo.
        */
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