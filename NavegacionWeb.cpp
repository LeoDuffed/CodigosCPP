// Creado por Leonardo Martínez Peña
// Programa usando Pilas 

#include <iostream> 
using namespace std;

struct Nodo{

    string nombreWeb;
    struct Nodo *sig;
};

struct Historial{

    int cantidadPaginas;
    struct Nodo *tope;
};

Historial *pila = NULL; // Inicializamos la pila   

Nodo *CrearNodo(string nombre){

    Nodo *aux = new Nodo;

    aux->nombreWeb = nombre;

    aux->sig = NULL;

    return aux;

}

void AgreagarElemento(string nombre){
    
    if (pila == NULL){

        pila = new Historial;
        pila->cantidadPaginas = 1;
        pila->tope = CrearNodo(nombre);

    } else { // Falta terminar de hacer este else 

        Nodo *aux;
        while (aux != NULL){

        }

    }

}

/*
AgregarElemento("google");
AgregarElemento("facebook");
AgregarElemento("Perfil");
AgregarElemento("fotos");
*/


int main(){

    return 0;

}