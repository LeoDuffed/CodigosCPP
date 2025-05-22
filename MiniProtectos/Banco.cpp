// Hecho por Leonardo Martínez Peña
// Programa usando Colas 
// Fecha 4/01/2025

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

Nodo *CrearNodo(){ // Funcion para que el usario pueda ingresar y se alamacene en la cola

    Nodo *aux = new Nodo;

    cout << "\nIngrese nombre completo: ";
    fflush(stdin);
    getline(cin, aux->nombre);
    cout << "Ingrese el servicio que desea: ";
    fflush(stdin);
    getline(cin, aux->servicioSolicitado);

    aux->sig = NULL; // Le damos valor al siguiente elemento de la cola 

    return aux;
}

void AgregarCliente(){ // Metodo para agregar clientes a la cola

    if (cola == NULL){ // Si es el primer elemento de la cola

        cola = new Banco; // Pedimos memoria para empezar a hacer la cola
        cola->primero = CrearNodo();
        cola->longitudCola = 1;

    } else { // Si no es el primer elemento de la cola 

        Nodo *aux = cola->primero;
        while (aux->sig != NULL){

            aux = aux->sig;
        }

        aux->sig = CrearNodo();

        cola->longitudCola = (cola->longitudCola) + 1; // Vamos incremenentado la longitud en 1 

    }

}

void MostrarPrimerCliente(){ // Metodo para mostrar solo el primer cliente de la cola 

    if (cola == NULL){
        cout << "\nNo hay nadie en la fila" << endl;
    } else {
        cout << "\nNombre: " << cola->primero->nombre << endl;
        cout << "Servicio solicitado: " << cola->primero->servicioSolicitado << endl;
    }

}
void MostrarTodosLosClientes(){ // Metodo que muestra a todos los clientes de la cola 

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

void EliminarCliente(){ // Metodo para eliminar clientes (FIFO)

    if (cola == NULL){

        cout << "No hay nadie en la fila" << endl;
    } else {

        if (cola->primero->sig == NULL){ // En caso de que solo haya un dato en la cola

            delete cola->primero;
            delete cola;
            cola = NULL; // Le damos el valor a la cola
        } else { // Si hay mas de un elemento en la cola 

            Nodo *aux = cola->primero->sig;
            delete (cola->primero);
            cola->primero = aux;
            cola->longitudCola = (cola->longitudCola) - 1; // La longitud de la cola decrese en 1 
        } 
    }

}

void DestruirCola(){ // Borramos todos los elementos de la cola 

    if (cola == NULL){
        cout << "No hay nadie en la fila" << endl;

    } else {
        
        Nodo *aux = cola->primero;
        while (aux != NULL){ // Vamos borrando uno por uno los datos de la cola

            Nodo *aux2 = aux->sig;
            delete aux;
            aux = aux2;

        }
        cola = NULL;

        cout << "La fila se ha reiniciado con exito" << endl;
    }

}

void Menu(){ // Menu del programa 

    int resp = 0, cont = 1;

    while(cont == 1){

        cout << "\n\n1. Agregar cliente" << endl;
        cout << "2. Mostrar primer cliente en cola" << endl;
        cout << "3. Mostrar todos los clientes" << endl;
        cout << "4. Eliminar cliente" << endl;
        cout << "5. Reiniciar cola" << endl;
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
                DestruirCola();
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