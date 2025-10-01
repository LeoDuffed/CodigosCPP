#include "MatFrac.h"
#include "Fracciones.h"
#include <iostream>
using namespace std;

int main(){

    // Clase Fracciones 

    // Fraccion 1
    Fracciones f1;
    int num, den;
    cout << "\nFraccion 1: " << endl;
    // Para el numerador
    while (!f1.setNumerador((cout << "\nIngresa numerador: ", cin >> num, num))){
        cout << "Intenta de nuevo" << endl;
    }
    // Para el denominador
    while(!f1.setDenominador((cout << "Ingresa denominador: ", cin >> den, den))){
        cout << "Intenta de nuevo" << endl;
    }
    // Muestra el denominador y numerador
    f1.simplificar();

    // Fraccion dos
    Fracciones f2;
    int num2, den2;
    cout << "\nFraccion 2: " << endl;
    // Para el numerador
    while (!f2.setNumerador((cout << "\nIngresa numerador: ", cin >> num2, num2))){
        cout << "Intenta de nuevo" << endl;
    }
    // Para el denominador
    while(!f2.setDenominador((cout << "Ingresa denominador: ", cin >> den2, den2))){
        cout << "Intenta de nuevo" << endl;
    }
    // Muestra el denominador y numerador
    f2.simplificar();
    
    // Operaciones
    f1.suma(f2.getNumerador(), f2.getDenominador());
    f1.resta(f2.getNumerador(), f2.getDenominador());
    f1.mult(f2.getNumerador(), f2.getDenominador());
    f1.div(f2.getNumerador(), f2.getDenominador());

    // Clase MatFrac

    MatFrac m1, m2;

    if(!m1.leeArchivos("matrizUno.txt")){
        cout << "No se pudo leer el archivo" << endl;
        return 0;
    }

    if(!m2.leeArchivos("matrizDos.txt")){
        cout << "No se pudo leer el archivo" << endl;
        return 0;
    }

    cout << "\nMatriz 1" << endl;
    m1.Mostrar();
    cout << " + " << endl;
    cout << "Matriz 2" << endl;
    m2.Mostrar();
    cout << " = " << endl;

    MatFrac resulado = m1.suma(m2);
    resulado.Mostrar();

    string newArchivo;
    cout << "Nombre del archivo: ";
    cin >> newArchivo;
    resulado.guardarEnArchivo(newArchivo);
    cout << "Archivo guardado" << endl;

    return 0;

}