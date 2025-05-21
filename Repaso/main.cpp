#include "Fracciones.h"
#include <iostream>
using namespace std;

int main(){

    Fracciones f1;

    int num, den;
    // Para el numerador
    while (!f1.setNumerador((cout << "Ingresa numerador: ", cin >> num, num))){
        cout << "Intenta de nuevo" << endl;
    }
    // Para el denominador
    while(!f1.setDenominador((cout << "Ingresa denominador: ", cin >> den, den))){
        cout << "Intenta de nuevo" << endl;
    }
    // Mouestra el denominador y numerador
    f1.simplificar();
    f1.mostrarFraccion();


    return 0;

}