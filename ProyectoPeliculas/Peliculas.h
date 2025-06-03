#ifndef PELICULAS_H
#define PELICULAS_H
#include <iostream>

// Struct's
struct Genero{ // Generos posibles de cada pelicula
	bool accion;
	bool aventura;
	bool comedia;
	bool fantasia;
	bool terror;
	bool infantil;
	bool drama;
	bool cienciaFiccion;
	bool romance;
	bool animacion;
};
struct Duracion{
    int horas;
    int min;
};
struct Pelicula{
    std :: string nombre;
    struct Duracion *duracion;
    struct Genero genero;
    struct Pelicula *ant, *sig; // Todas las peliculas estan enlazadas entre si (variables para el doble enlace).
};
struct Catalogo{ // Estructura mas grande
    int longitud;
    struct Pelicula *pelicula;
};

class Peliculas{
    private: 
    Catalogo *lista;
    Pelicula *CrearNodo(std :: string nombre, std :: string genero1, std :: string genero2, std :: string genero3, int hora, int min);


    public:
    Peliculas();
    ~Peliculas(){}

    int AgregarPelicula(std :: string nombre, std :: string genero1, std :: string genero2, std :: string genero3, int hora, int min);
    void BuscarPorGenero(std :: string genero);
    void MostrarNodo(Pelicula *aux);
    void MostrarPorGenero();
    void MostrarLista();
    Pelicula *BuscarPorNombre();

};

#endif