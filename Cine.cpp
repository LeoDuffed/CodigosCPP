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
    struct Pelicula *ant, *sig; // Todas las peliculas estan enlazadas entre si.

};

struct Catalogo{ // Estructura mas grande

    int longitud;
    struct Pelicula *pelicula;
};

Catalogo *lista = NULL; // Inicializamos la lista en NULL (vacia)

Pelicula *CrearNodo(string nombre, int precio, string genero1, string genero2, string genero3, int anio, int mes, int dia, int hora, int min){

    Pelicula *aux;

    return aux;
}

void AgregarPelicula (string nombre, int precio, string genero1, string genero2, string genero3, int anio, int mes, int dia, int hora, int min){

    if (lista == NULL){
        lista = new Catalogo; // Pedimos memoria para crear una estructura de tipo Catologo.
        lista->longitud = 1;
        lista->pelicula = CrearNodo(nombre, precio, genero1, genero2, genero3, anio, mes, dia, hora, min);
    }

}

int main(){

	AgregarPelicula("La era del hielo",10000,"aventura","comedia"," ",2022,11,4,1,30);
	AgregarPelicula("titanic",7000,"romance","drama"," ",1997,12,19,3,15);
	AgregarPelicula("Harry Potter y la piedra filosofal",6500,"fantasia","aventura"," ",2001,11,16,2,32);
	AgregarPelicula("Avatar",5200,"animacion","aventura","drama",2009,12,18,2,42);
	AgregarPelicula("El rey Leon",7000,"romance","drama","aventura",1994,6,15,1,28);

    return 0;
}