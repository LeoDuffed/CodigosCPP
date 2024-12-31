// Programa con listas doblemente enlazadas
// Creado por Leonardo Martínez Peña

#include <iostream> 
using namespace std;

struct Genero{

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

    Pelicula *aux = new Pelicula;

    aux->nombre = nombre;
    aux->precio = precio;
    aux->asientos = 150;

    aux->duracion = new Duracion;
    aux->duracion->horas = hora;
    aux->duracion->min = min;

    aux->estreno = new Estreno;
    aux->estreno->anio = anio;
    aux->estreno->mes = mes;
    aux->estreno->dia = dia;

    aux->genero.accion=false;
	aux->genero.animacion=false;
	aux->genero.aventura=false;
	aux->genero.cienciaFiccion=false;
	aux->genero.comedia=false;
	aux->genero.drama=false;
	aux->genero.fantasia=false;
	aux->genero.infantil=false;
	aux->genero.romance=false;
	aux->genero.terror=false;
	
	if(genero1.compare("accion")==0 || genero2.compare("accion")==0 || genero3.compare("accion")==0)
		aux->genero.accion=true;
	if(genero1.compare("aventura")==0 || genero2.compare("aventura")==0 || genero3.compare("aventura")==0)
		aux->genero.aventura=true;
	if(genero1.compare("animacion")==0 || genero2.compare("animacion")==0 || genero3.compare("animacion")==0)
		aux->genero.animacion=true;
	if(genero1.compare("comedia")==0 || genero2.compare("comedia")==0 || genero3.compare("comedia")==0)
		aux->genero.comedia=true;
	if(genero1.compare("terror")==0 || genero2.compare("terror")==0 || genero3.compare("terror")==0)
		aux->genero.terror=true;
	if(genero1.compare("infantil")==0 || genero2.compare("infantil")==0 || genero3.compare("infantil")==0)
		aux->genero.infantil=true;
	if(genero1.compare("drama")==0 || genero2.compare("drama")==0 || genero3.compare("drama")==0)
		aux->genero.drama=true;
	if(genero1.compare("fantasia")==0 || genero2.compare("fantasia")==0 || genero3.compare("fantasia")==0)
		aux->genero.fantasia=true;
	if(genero1.compare("romance")==0 || genero2.compare("romance")==0 || genero3.compare("romance")==0)
		aux->genero.romance=true;
	if(genero1.compare("ciencia ficcion")==0 || genero2.compare("ciencia ficcion")==0 || genero3.compare("ciencia ficcion")==0)
		aux->genero.romance=true;

	aux->sig=NULL;
	aux->ant=NULL;

    return aux;
}

void AgregarPelicula (string nombre, int precio, string genero1, string genero2, string genero3, int anio, int mes, int dia, int hora, int min){

    if (lista == NULL){
        lista = new Catalogo; // Pedimos memoria para crear una estructura de tipo Catologo.
        lista->longitud = 1;
        lista->pelicula = CrearNodo(nombre, precio, genero1, genero2, genero3, anio, mes, dia, hora, min);
    } else {

        Pelicula *aux = lista->pelicula;
        while (aux != NULL){

            aux = aux->sig;
        }

        aux->sig = CrearNodo(nombre, precio, genero1, genero2, genero3, anio, mes, dia, hora, min);
        lista->longitud = (lista->longitud) + 1;
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