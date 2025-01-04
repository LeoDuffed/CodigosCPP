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

    cout << "\nIngrese nombre completo: ";
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
        cout << "\nNo hay nadie en la fila" << endl;
    } else {
        cout << "\nNombre: " << cola->primero->nombre << endl;
        cout << "Servicio solicitado: " << cola->primero->servicioSolicitado << endl;
    }

}
void MostrarTodosLosClientes(){

    if (cola == NULL){

        cout << "\nNo hay nadie en la fila " << endl;
    } else {

        Nodo *aux = cola->primero;

        while (aux != NULL) {

            cout << "\nNombre: " << aux->nombre << endl;
            cout << "Servicio solicitado: " << aux->servicioSolicitado << endl;

            aux = aux->sig;
        }
    }


}

void EliminarCliente(){

    if (cola == NULL){

        cout << "No hay nadie en la fila" << endl;
    } else {

        if (cola->primero->sig == NULL){

            delete cola->primero;
            delete cola;
            cola = NULL;
        } else {

            Nodo *aux = cola->primero->sig;
            delete (cola->primero);
            cola->primero = aux;
            cola->longitudCola = (cola->longitudCola) - 1;
        } 
    }
}

void Menu(){

    int resp = 0, cont = 1;

    while(cont == 1){

        cout << "\n\n1. Agregar cliente" << endl;
        cout << "2. Mostrar primer cliente en cola" << endl;
        cout << "3. Mostrar todos los clientes" << endl;
        cout << "4. Eliminar cliente" << endl;
        cout << "5. Destruir cola" << endl;
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
                MostrarTodosLosClientes();
                break;
            case 4: 
                EliminarCliente();
                break;
            case 5: 
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