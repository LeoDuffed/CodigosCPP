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
                break;
            case 2: 
                break;
            case 3:
                break;
            case 4: 
                break;
            case 0:
                cout << "Saliendo del programa..." << endl;
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