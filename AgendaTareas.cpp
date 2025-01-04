// Creado por Leonardo Martinez Peña

#include <iostream> 
#include <cstdlib> 
using namespace std;

struct Tarea{ // Esta anidada a Lista esta estructura

    string nombreTarea;
    string descripcionTarea;
    bool estado;
    struct Tarea * sig;

};

struct Lista{ // Es la estuctura mas grande
    
    int longitud;
    struct Tarea * t; // Anidamos la estructura tarea

};

Tarea *CrearNodo(){ // Funcion de tipo Tarea

    Tarea *aux = new Tarea; // Funcion para que el usario ingrese la tarea.

    cout << "\nIngrese tarea: ";
    fflush(stdin);
    getline(cin, aux -> nombreTarea);

    cout << "Ingrese la descripcion de la tarea: ";
    fflush(stdin);
    getline(cin, aux -> descripcionTarea);

    aux -> estado = false;
    aux -> sig = NULL; // La siguiente posicion es NULL

    cout << "Precion enter para continuar -> " << endl;
    std :: cin.get();

    system("clear");

    return aux; // Regresamos elemento de tipo Tarea

}

void AgregarTarea(Lista *& lista){ // Pasamos por referencia la variable lista de tipo Lista

    if (lista == NULL){ // Si la lista esta bacia (primer elemento de la lista)

        lista = new Lista; // Guardamos espacion en la lista
        lista -> longitud = 1; // La longitud de las lista le definimos en 1 de largo.
        lista -> t = CrearNodo();

    } else {

        Tarea *aux = lista -> t;
        while (aux -> sig != NULL){ // Mientras el siguente elemento de la lista sea diferente a NULL
            aux = aux -> sig;

        }
        aux -> sig = CrearNodo(); // Cambar al siguiente elemento de la lista
        lista -> longitud = (lista -> longitud) + 1; // La longitud de las lista incrementa en uno

    }
}

void MostrarLista(Lista *&lista){ // Metodo muestra todas las tareas

    if (lista == NULL){
        cout << "\nLa lista esta vacia" << endl;

    } else {
        Tarea *aux = lista -> t;
        while (aux != NULL){

            cout << "\n\nTarea: " << aux -> nombreTarea << endl;
            cout << "Descripcion: " << aux -> descripcionTarea << endl;
            if (aux -> estado == true){
                cout << "Estado: Completada" << endl;
            } else {
                cout << "Estado: Incompleta" << endl;
        
            } 
            aux = aux -> sig;

        }
    }

}

void MostrarPorTerminar(Lista *lista){ // Metodo que solo muestra las tareas por termianr
    int leng = 0;
    if (lista == NULL){
        cout << "La lista esta vacia" << endl;

    } else {
        Tarea *aux = lista-> t; 
        while (aux != NULL){
            if (aux -> estado == false){
                leng += 1;
            }

            aux = aux -> sig;

        }

        cout << "Te quedan por realizar " << leng << " tareas." << endl;
    }

}

Tarea *BuscarTareaPorNombre(Lista *lista){ // Funcion para buscar tarea por nombre

    string nombre;

    if (lista == NULL){
        cout << "La lista esta vacia" << endl;
    } else {

        cout << "Ingrese el nombre de la tarea: ";
        fflush(stdin);
        getline(cin, nombre);
        Tarea *aux = lista -> t; // Apuntamos al primer elemento de la lista.

        while (aux != NULL){

            if (nombre.compare(aux -> nombreTarea) == 0){

                cout << "\n\nNombre: " << aux->nombreTarea << endl;
                cout << "Descripcion: " << aux->descripcionTarea << endl;
                if (aux->estado == false) {
                    cout << "Estado: Incompleta" << endl;
                } else {
                    cout << "Estado: Completada" << endl;
                }
                return aux;
            }
            aux = aux -> sig;
        }
        cout << "El nombre ingresado no coincide con ninguna tarea en la lista" << endl;

    }
    return 0;

}

Tarea *CompletarTarea(Lista *lista){ // Verificamos que exista la tarea

    string nombre;

    if (lista == NULL){
        cout << "La lista esta vacia" << endl;
    } else {

        cout << "Ingrese el nombre de la tarea: ";
        fflush(stdin);
        getline(cin, nombre);
        Tarea *aux = lista -> t; // Apuntamos al primer elemento de la lista.

        while (aux != NULL){

            if (nombre.compare(aux -> nombreTarea) == 0){

                cout << "\n\nEl estado de la tarea ha cambiado" << endl;
                cout << "\nNombre: " << aux->nombreTarea << endl;
                cout << "Estado: Completada" << endl;

                return aux;
            }
            aux = aux -> sig;
        }
        cout << "El nombre ingresado no coincide con ninguna tarea en la lista" << endl;

    }
    return 0;

}

void TerminarTarea(Lista *&lista){ // Marcamos como completada una tarea

    if (lista == NULL){
        cout << "La lista esta vacia" << endl;
    } else{
        Tarea *aux = CompletarTarea(lista);
        if (aux != 0){
            
            aux->estado = true;
        }
    }
}

void MostrarTareasCompletadas(Lista *lista){ // Muestra todas la tareas completadas

    cout << "\n\nTareas terminadas: " << endl;

    if (lista == NULL){
        cout << "La lista esta vacia" << endl;
    } else {
        Tarea *aux = lista->t;
        while (aux != NULL){
            if (aux->estado == true){
                cout << "\nNombre: " << aux->nombreTarea << endl;
                cout << "Descripcion: " << aux->descripcionTarea << endl;
                cout << "Estado: Completado" << endl;

            } else {
                cout << "Aun no hay tareas completadas" << endl;
            }

            aux = aux->sig;
        }
    }

}

void MostrarTareasIncompletas(Lista *lista){ //Muestra las tareas incompletas

    cout << "\n\nTareas por terminar: " << endl;

    if (lista == NULL){
        cout << "La lista esta vacia" << endl;
    } else {
        Tarea *aux = lista->t;
        while (aux != NULL){
            if (aux->estado == false){
                cout << "\nNombre: " << aux->nombreTarea << endl;
                cout << "Descripcion: " << aux->descripcionTarea << endl;
                cout << "Estado: Incompleta" << endl;

            aux = aux->sig;
            }
        }
    }

}

int EliminarTarea(Lista *&lista){ // Metodo para borrar tareas de la lista

    string nombre;

    if(lista == NULL){
        cout << "La lista esta vacia" << endl;
    } else {

        cout << "Ingrese el nombre de la tarea que deseas elimimnar: ";
        fflush(stdin);
        getline(cin, nombre);

        Tarea *aux = lista -> t;
        Tarea *respaldoAnt = aux;
        Tarea *respaldoSig = aux;

        if (aux->sig == NULL){
            
            if (nombre.compare(aux->nombreTarea) == 0){ // Primer caso, si es el unico elemento de la lista
                delete aux;
                lista = NULL;

                cout << "Se ha eliminado con exito la tarea: " << nombre << endl;

                return 0;
            } 

        } else {

            if (lista -> t -> nombreTarea.compare(nombre) == 0){ // Segundo caso, si es el primer elemento de la lista

                respaldoSig = aux->sig;
                delete aux;
                lista ->longitud = (lista->longitud - 1);
                lista->t = respaldoSig;

                cout << "La tarea " << nombre << " ha sido eliminada con exito" << endl;

                return 0;

            } else { // Tercer caso, si es cualquier otro elemento de la lista.
                while (aux != NULL){

                    if (nombre.compare(aux->nombreTarea) == 0){
                        respaldoSig = aux->sig;
                        delete aux;
                        respaldoAnt->sig = respaldoSig;

                        cout << "La tarea " << nombre << " ha sido eliminada con exito" << endl;

                        return 0;

                    }

                    respaldoAnt = aux;
                    aux = aux->sig;
                }

            }
        }

        cout << "La tarea " << nombre << " no fue encontrada en la lista" << endl;
    }

    return 0;
}

void ReiniciarLista(Lista *&lista){ // Metodo para reiniciar la lista 

    if (lista == NULL){
        cout << "La lista esta vacia" << endl;

    } else {
        Tarea *aux = lista->t;
        Tarea *respaldo = aux;
        while (aux != NULL){

            respaldo = aux->sig;
            delete aux;
            aux = respaldo; // Borramos elemento por elemento de la lista
            
        }

        cout << "\n\nLa lista ha sido vaciada con exito!!." << endl;

        lista = NULL; // Reiniciamos la lista en su modo inicial.
    }
}

int BuscarTareaPorIndice(Lista *lista){ // Buscamos tareas por indice

    int indice = 0;

    if (lista == NULL){
        cout << "\n\nLa lista esta vacia" << endl;
    } else {

        cout << "\n\nIngrese indice: ";
        cin >> indice;

        if (indice > lista->longitud || indice < 0){
            cout << "\nIndice inexistente" << endl;
        } else {
            Tarea *aux = lista->t;

            int contador = 1;

            while (aux != NULL){

                if (contador == indice){

                    cout << "\n\nNombre: " << aux->nombreTarea << endl;
                    cout << "Descripcion: " << aux->descripcionTarea << endl;
                    if (aux->estado == false) {
                        cout << "Estado: Incompleta" << endl;
                    } else {
                        cout << "Estado: Completada" << endl;
                    } 

                    return 0;
                }

                contador++;
                aux = aux->sig;

            }
        }

    }
    return 0;

}

void menu(){ // Menu de todas las opciones

    system("clear");

    Lista *lista = NULL; // Inicializamos la lista en NULL
    int eleccion;
    bool continuar = true;

    while (continuar == true){

        cout << "\n---------------------------" << endl;
        cout << " 1. Agregar tareas" << endl;
        cout << " 2. Mostrar tareas" << endl;
        cout << " 3. Mostrar cantidad de tareas a realizar" << endl;
        cout << " 4. Mostrar tareas realizadas" << endl;
        cout << " 5. Buscar tareas por su indice" << endl;
        cout << " 6. Buscar tareas por su nombre" << endl;
        cout << " 7. Eliminar tarea" << endl;
        cout << " 8. Reiniciar lista" << endl;
        cout << " 9. Terminar tarea" << endl;
        cout << " 10. Mostrar tareas incompletas" << endl;
        cout << " 0. Salir del programa" << endl;
        cout << " Ingrese su eleccion: ";
        cin >> eleccion;

        switch(eleccion){
            case 1: 
                AgregarTarea(lista);
                break;
            case 2: 
                MostrarLista(lista);
                break;
            case 3: 
                MostrarPorTerminar(lista);
                break;
            case 4:
                MostrarTareasCompletadas(lista);
                break;
            case 5: 
                BuscarTareaPorIndice(lista);
                break;
            case 6:
                BuscarTareaPorNombre(lista);
                break;
            case 7: 
                EliminarTarea(lista);
                break;
            case 8:
                ReiniciarLista(lista);
                break;
            case 9: 
                TerminarTarea(lista);
                break;
            case 10:
                MostrarTareasIncompletas(lista);
                break;
            case 0:
                cout << "Saliendo" << endl;
                continuar = false;
                break;
            default:
                cout << "Opcion invalida" << endl;

        }
    }

}

int main(){

    menu();
    
    return 0;
}
