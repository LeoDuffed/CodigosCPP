// Creado por Leonardo Martínez Peña
// Programa usando Pilas 
// Fecha 6/01/2025

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

void AgregarElemento(string nombre){
    
    if (pila == NULL){

        pila = new Historial;
        pila->cantidadPaginas = 1;
        pila->tope = CrearNodo(nombre);

    } else { // Falta terminar de hacer este else 

        Nodo *aux = CrearNodo(nombre);
        aux->sig = pila->tope;
        pila->cantidadPaginas = (pila->cantidadPaginas) + 1;
        pila->tope = aux;

    }

}

void MostrarPaginaVisitada(){

    if (pila = NULL){
        cout << "La pila esta vacia" << endl;
    } else {
        cout << "Nombre pagina web: " << pila->tope->nombreWeb << endl;
    }
}

int main(){

    AgregarElemento("google");
    AgregarElemento("facebook");
    AgregarElemento("Perfil");
    AgregarElemento("fotos");

    return 0;

}