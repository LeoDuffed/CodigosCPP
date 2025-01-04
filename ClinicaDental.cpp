// Creado por Leonardo Martinez Peña

#include <iostream> 
#include <thread>
#include <chrono>
using namespace std;

// Definimos los precios de los servicios (variables globales)
#define precioLimpieza 1500
#define precioBlamqueamiento 3000
#define precioExtraccion 2000
#define precioTapaduras 800

struct fecha{ // Fecha de la cita

    int anio;
    int mes;
    int dia;
    int hora;
    int min;

};

struct servicio{ // Tipos de servicio

    bool limpieza;
    bool blanqueamiento;
    int tapadura;
    int extraccion;
};

struct pacientes{ // Datos por persona

    string nombre;
    int edad;
    string sexo;
    int total;
    struct fecha atencion;
    struct servicio cita;

}lista[20];

void Mostrar(){

    for (int i = 0; i < 20; i++){
        
        cout << "\n\n*----------------------------------*" << endl;
        cout << "  Nombre: " << lista[i].nombre << endl;
        cout << "  Edad: " << lista[i].edad << endl;
        cout << "  Sexo: " << lista[i].sexo << endl;
        cout << "-----------------------------------" << endl;
        cout << "  Servicios realizados: \n" << endl;
        cout << "  Liempieza: " << lista[i].cita.limpieza << endl;
        cout << "  Blanqueamiento: " << lista[i].cita.blanqueamiento << endl;
        cout << "  Tapaduras realizadas: " << lista[i].cita.tapadura << endl;
        cout << "  Extracciones realizadas: " << lista[i].cita.extraccion << endl;
        cout << "\n  Fecha de cita: " << lista[i].atencion.dia << " / " << lista[i].atencion.mes << " / " << lista[i].atencion.anio << endl;
        cout << "  Hora de cita: " << lista[i].atencion.hora << " : " << lista[i].atencion.min << "0" << endl;
        cout << "\n-----------------------------------" << endl;
        cout << "  Total: $" << lista[i].total << endl;
        cout << "*----------------------------------*\n\n" << endl;



    }
}

void IniciarLista(){ // Inicializamos la lista, para que no tenga valores basura

    for (int i = 0; i < 20; i++){
        lista[i].nombre = " ";
        lista[i].edad = 0;
        lista[i].sexo = " ";
        lista[i].total = 0;
        lista[i].cita.limpieza = false;
        lista[i].cita.blanqueamiento = false;
        lista[i].cita.tapadura = 0;
        lista[i].cita.extraccion = 0;
        lista[i].atencion.anio = 2025;
        lista[i].atencion.mes = 1;
        lista[i].atencion.dia = 28;

        static int horaIni = 8, cont = 0; // El horario de la clinica empieza a las 8.

        if (cont == 2){

            horaIni++;
            if (horaIni == 13){
                horaIni++;
            }
            cont = 0;
        }

        lista[i].atencion.hora = horaIni;
        cont++;

        if (i%2 == 0){ // Para que se imprima la hora del horario a iniciando la hora a las 30.
            lista[i].atencion.min = 0; 

        } else {
            lista[i].atencion.min = 3;

        }

    }

}

int ValidarAgenda(){ // Verificamos si hay disponibilidad para una cita.
    
    for (int i = 0; i < 20; i++){
        if (lista[i].nombre == " "){
            return i;
        }
    }
    return -1;
}

int ValidarHora(int hora, int min){

    for (int i = 0; i < 20; i++){
        if (lista[i].atencion.hora == hora && lista[i].atencion.min == min){
            if (lista[i].nombre == " "){
                return i;
            } else {
                return -1; 
            }
        }
    }

    return 0;   

}

void Servicio(int indice){

    int eleccion = 0;

    while (eleccion != 5){

        cout << "\n\n1. Limpieza dental" << endl;
        cout << "2. Blanqueamineto dental" << endl;
        cout << "3. Tapadura dental" << endl;
        cout << "4. Extraccion dental" << endl;
        cout << "5. Ninguna de las anteriores " << endl;
        cout << "Ingrese el servicio a realizar: ";
        cin >> eleccion;

        switch(eleccion){
            case 1:
                cout << "\n\nHas seleccionado la limpieza dental";
                lista[indice].cita.limpieza = true;
                break;
            case 2: 
                cout << "\n\nHas seleccionado el blanqueamiendo dental";
                lista[indice].cita.blanqueamiento = true;
                break;
            case 3:
                cout << "\n\nHas sleccionado el tratamiento de tapaduras" << endl;
                cout << "Cuantas tapaduras deseas que se te pongan?: ";
                cin >> lista[indice].cita.tapadura;
                break;
            case 4:
                cout << "\n\nHas seleccionado el tratamiento de extracion" << endl;
                cout << "Cuantos dientes deseas que se te extraigan?: ";
                cin >> lista[indice].cita.extraccion;
                break;
            case 5:
                eleccion = 5;
                break;
            default:
                cout << "\nOpcion invalida, ingrese de nuevo " << endl;
                break;

        }

    }

}

void TotalPagar(int indice){

    if(lista[indice].cita.limpieza == true){
        lista[indice].total = lista[indice].total + precioLimpieza;
    }

    if(lista[indice].cita.blanqueamiento == true){
        lista[indice].total = lista[indice].total + precioBlamqueamiento;

    }

    lista[indice].total =((lista[indice].cita.tapadura) * precioTapaduras) + lista[indice].total;
    lista[indice].total =((lista[indice].cita.extraccion) * precioExtraccion) + lista[indice].total;

}

void ImprimirCita(int indice){

    cout << "\n\n           Cita Guardada";
    cout << "*----------------------------------*" << endl;
    cout << "  Nombre: " << lista[indice].nombre << endl;
    cout << "  Edad: " << lista[indice].edad << endl;
    cout << "  Sexo: " << lista[indice].sexo << endl;
    cout << "-----------------------------------" << endl;
    cout << "  Servicios realizados: \n" << endl;
    cout << "  Liempieza: " << lista[indice].cita.limpieza << endl;
    cout << "  Blanqueamiento: " << lista[indice].cita.blanqueamiento << endl;
    cout << "  Tapaduras realizadas: " << lista[indice].cita.tapadura << endl;
    cout << "  Extracciones realizadas: " << lista[indice].cita.extraccion << endl;
    cout << "\n  Fecha de cita: " << lista[0].atencion.dia << " / " << lista[0].atencion.mes << " / " << lista[0].atencion.anio << endl;
    cout << "  Hora de cita: " << lista[indice].atencion.hora << " : " << lista[indice].atencion.min << "0" << endl;
    cout << "\n-----------------------------------" << endl;
    cout << "  Total: $" << lista[indice].total << endl;
    cout << "*----------------------------------*\n\n" << endl;

}

void AgregarElemento(){ // Si hay disponivilidad pedimos la hora a la que quiere la cita.

    int indice = ValidarAgenda();

    if (indice == -1){
        cout << "\nLa agenda esta llena para este dia" << endl;
    } else {

        bool NoSalir = false;

        while (NoSalir == false ){
            int hora = 0, min = 0;

            cout << "\nA que hora desea el horario de su cita?" << endl;
            cout << "Ingrese la hora: ";
            cin >> hora;
            cout << "Ingrese el min: ";
            cin >> min;
            min = min / 10;

            indice = ValidarHora(hora, min);

            if (indice == -1){
                cout << "\n\nLa hora ingresada ya esta recerbada \n" << endl;
                NoSalir = false;
            } else {

                cout << "\nIngrese el nombre completo del paciente: ";
                fflush(stdin);
                getline(cin, lista[indice].nombre);
                cout << "Ingrese la edad del paciente: ";
                fflush(stdin);
                cin >> lista[indice].edad;
                cout << "Ingrese el sexo del paciente: ";
                fflush(stdin);
                getline(cin, lista[indice].sexo);
                Servicio(indice);
                TotalPagar(indice);

                ImprimirCita(indice);
                
                NoSalir = true;
                
            }
        }
    }

}

int Buscar(){

    string nombre;
    cout << "Ingrese nombre: ";
    fflush(stdin);
    getline(cin, nombre);

    for (int i = 0; i < 20; i++){
        if (nombre.compare(lista[i].nombre) == 0){

            cout << "\n\n*----------------------------------*" << endl;
            cout << "  Nombre: " << lista[i].nombre << endl;
            cout << "  Edad: " << lista[i].edad << endl;
            cout << "  Sexo: " << lista[i].sexo << endl;
            cout << "-----------------------------------" << endl;
            cout << "  Servicios realizados: \n" << endl;
            cout << "  Liempieza: " << lista[i].cita.limpieza << endl;
            cout << "  Blanqueamiento: " << lista[i].cita.blanqueamiento << endl;
            cout << "  Tapaduras realizadas: " << lista[i].cita.tapadura << endl;
            cout << "  Extracciones realizadas: " << lista[i].cita.extraccion << endl;
            cout << "\n  Fecha de cita: " << lista[i].atencion.dia << " / " << lista[i].atencion.mes << " / " << lista[i].atencion.anio << endl;
            cout << "  Hora de cita: " << lista[i].atencion.hora << " : " << lista[i].atencion.min << "0" << endl;
            cout << "\n-----------------------------------" << endl;
            cout << "  Total: $" << lista[i].total << endl;
            cout << "*----------------------------------*\n\n" << endl;

            return 0;

        } 
    }

    cout << "El nombre no se encontro en la base de datos" << endl;

    return 0;

}

int BorrarPaciente(){

    string nombre;
    cout << "Ingrese el nombre del pasiente que desese borrar: ";
    fflush(stdin);
    getline(cin, nombre);

    for (int i = 0; i < 20; i++){
        if (nombre.compare(lista[i].nombre) == 0){

            cout << "El pasiente " << nombre << " fue eliminado" << endl;
            lista[i].nombre = " ";
            lista[i].edad = 0;
            lista[i].sexo = " ";
            lista[i].total = 0;
            lista[i].cita.limpieza = false;
            lista[i].cita.blanqueamiento = false;
            lista[i].cita.tapadura = 0;
            lista[i].cita.extraccion = 0;
            lista[i].atencion.anio = 2025;
            lista[i].atencion.mes = 1;
            lista[i].atencion.dia = 28;

            return 0;
        }
    }

    cout << "El nombre del pasiente ingresado no fue encontrado." << endl;

    return 0;

}

void Menu(){
    int eleccion = 1;

    while (eleccion != 0){

        eleccion = 0;

        cout << "Bienvenido a la clinica dental DuffedLOL\n" << endl;
        cout << "1. Registrar paciente para cita" << endl;
        cout << "2. Buscar paciente en el registro" << endl;
        cout << "3. Borrar paciente del registro" << endl;
        cout << "4. Todos los pasientes del dia" << endl;
        cout << "0. Salir" << endl;
        cout << "Ingrese su eleccion: ";
        cin >> eleccion;

        switch(eleccion){

            case 1:
                AgregarElemento();
                break;
            case 2: 
                Buscar();
                break;
            case 3:
                BorrarPaciente();
                break;
            case 4:
                Mostrar();
                break;
            case 0:
                cout << "Saliendo..." << endl;
                break;
            default:
                cout << "Opcion invalida, ingrese de nuevo " << endl;

        }
    }
}

int main(){

    IniciarLista();

    // Inicializamos varias personas: 
    lista[2].nombre = "Carlos Gómez";
    lista[2].edad = 45;
    lista[2].sexo = "Hombre";
    lista[2].cita.limpieza = true;
    lista[2].cita.blanqueamiento = false;
    lista[2].cita.tapadura = 5;
    TotalPagar(2);

    lista[4].nombre = "Fernanda Torres";
    lista[4].edad = 32;
    lista[4].sexo = "Mujer";
    lista[4].cita.limpieza = true;
    lista[4].cita.blanqueamiento = true;
    TotalPagar(4);

    lista[7].nombre = "Juan Pérez";
    lista[7].edad = 28;
    lista[7].sexo = "Hombre";
    lista[7].cita.limpieza = false;
    lista[7].cita.blanqueamiento = true;
    lista[7].cita.tapadura = 6;
    TotalPagar(7);

    lista[9].nombre = "Laura Fernández";
    lista[9].edad = 54;
    lista[9].sexo = "Mujer";
    lista[9].cita.limpieza = true;
    lista[9].cita.blanqueamiento = true;
    lista[9].cita.tapadura = 4;
    TotalPagar(9);

    lista[11].nombre = "Santiago Rivera";
    lista[11].edad = 41;
    lista[11].sexo = "Hombre";
    lista[11].cita.limpieza = false;
    lista[11].cita.blanqueamiento = false;
    lista[11].cita.tapadura = 3;
    TotalPagar(11);

    lista[14].nombre = "Valeria Ruiz";
    lista[14].edad = 22;
    lista[14].sexo = "Mujer";
    lista[14].cita.limpieza = true;
    lista[14].cita.blanqueamiento = true;
    TotalPagar(14);

    lista[16].nombre = "Adrián Mendoza";
    lista[16].edad = 38;
    lista[16].sexo = "Hombre";
    lista[16].cita.limpieza = true;
    lista[16].cita.blanqueamiento = false;
    lista[16].cita.tapadura = 2;
    TotalPagar(16);

    lista[18].nombre = "María López";
    lista[18].edad = 50;
    lista[18].sexo = "Mujer";
    lista[18].cita.limpieza = true;
    lista[18].cita.blanqueamiento = true;
    TotalPagar(18);

    lista[19].nombre = "Rodrigo Sánchez";
    lista[19].edad = 35;
    lista[19].sexo = "Hombre";
    lista[19].cita.limpieza = false;
    lista[19].cita.blanqueamiento = true;
    lista[19].cita.tapadura = 4;
    TotalPagar(19);

    lista[1].nombre = "Gabriela Castro";
    lista[1].edad = 29;
    lista[1].sexo = "Mujer";
    lista[1].cita.limpieza = true;
    lista[1].cita.blanqueamiento = false;
    TotalPagar(1);

    Menu();

    return 0;
}