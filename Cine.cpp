// Programa con listas doblemente enlazadas
// Creado por Leonardo Martínez Peña

#include <iostream> 
using namespace std;

struct Genero{

    bool Accion;
    bool Aventura;
    bool Terror;
    bool Fantacia;
    bool Comedia;
    bool Infantil;
    bool Romance;
    bool CienciaFiccion;
    bool Animacion;
    bool Drama;

};

struct Estreno{

    int anio;
    int mes;
    int dia;

};

struct Duracion{

    int horas;
    int min;

};

struct Pelicula{

    string nombre;
    int precio;
    int asientos;
    struct Duracion *duracion;
    struct Estreno *estreno;
    struct Genero genero;
    struct Pelicula *ant, *sig;

};

struct Catalogo{

    int longitud;
    struct Pelicula *pelicula;
};

int main(){

    return 0;
}