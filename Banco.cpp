// Hecho por Leonardo Martínez Peña
// Programa usando Colas 

#include <iostream> 
using namespace std;

struct Nodo{

    string nombre;
    string servicioSolicitado;
    struct Nodo *sig; // Estructura simplemente enlazada

};

struct Banco{

    int longitudCola;
    struct Nodo *primero;

};

Banco *cola = NULL; // Inicializamos la cola

Nodo *CrearNodo(){

    Nodo *aux = new Nodo;

    cout << "Ingrese nombre completo: ";
    fflush(stdin);
    getline(cin, aux->nombre);
    cout << "Ingrese el servicio que desea: ";
    fflush(stdin);
    getline(cin, aux->servicioSolicitado);

    aux->sig = NULL;

    return aux;
}

void AgregarCliente(){

    if (cola == NULL){

        cola = new Banco;
        cola->primero = CrearNodo();
        cola->longitudCola = 1;

    } else {

        Nodo *aux = cola->primero;
        while (aux->sig != NULL){

            aux = aux->sig;
        }

        aux->sig = CrearNodo();

        cola->longitudCola = (cola->longitudCola) + 1;

    }

}

void MostrarPrimerCliente(){

    if (cola == NULL){
        cout << "No hay nadie en la fila" << endl;
    } else {
        cout << "Nombre: " << cola->primero->nombre << endl;
        cout << "Servicio solicitado: " << cola->primero->servicioSolicitado << endl;
    }

}

void Menu(){

    int resp = 0, cont = 1;

    while(cont == 1){

        cout << "1. Agregar cliente" << endl;
        cout << "2. Mostrar primer cliente en cola" << endl;
        cout << "3. Eliminar cliente" << endl;
        cout << "4. Destruir cola" << endl;
        cout << "0. Salir" << endl;
        cout << "Ingrese eleccion: ";
        cin >> resp;

        switch (resp){

            case 1: 
                AgregarCliente();
                break;
            case 2: 
                MostrarPrimerCliente();
                break;
            case 3:
                break;
            case 4: 
                break;
            case 0:
                cout << "Saliendo del programa..." << endl;
                cont = 1;
                break;
            default:
                cout << "Opcion invalida" << endl;
        }

    }
}

int main(){

    Menu();

    return 0; 
}