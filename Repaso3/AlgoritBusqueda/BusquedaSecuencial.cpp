/*
Funcionamiento del Algoritmo
- Inicialización: Comienza en el primer elemento de la lista. 
- Comparación: Compara el elemento actual con el valor que se busca. 
- Iteración: Si no hay coincidencia, avanza al siguiente elemento de la lista. 
- Resultado: El proceso continúa hasta que se encuentra el valor o hasta que se han revisado todos los elementos. 

*/

#include <iostream>
#include <cstdlib>
#include <ctime>

template <std::size_t N>
void IniciarArreglo(int (&array)[N]) { for (std::size_t i = 0; i < N; ++i) array[i] = std::rand() % 100; }

template <std::size_t N>
void MostrarArreglo(const int (&array)[N]) { // array es una referencia (&) a un arreglo ([N]) de int
    for (std::size_t i = 0; i < N; ++i) std::cout << array[i] << (i + 1 < N ? " , " : "\n");
}

template <std::size_t N>
int BusquedaSecuencial(const int (&array)[N], int num) {
    for (std::size_t i = 0; i < N; ++i) {
        if (array[i] == num) return static_cast<int>(i);
    }
    return -1;
}

int main() {
    std::srand(static_cast<unsigned>(std::time(nullptr)));
    int array[100];
    IniciarArreglo(array);
    MostrarArreglo(array);
    int num = std::rand() % 100;
    std::cout << "Numero buscado: " << num << "\n";
    int pos = BusquedaSecuencial(array, num);
    if (pos >= 0) std::cout << "Numero encontrado en la posicion: " << pos << "\n";
    else std::cout << "No se encontro el numero: " << num << "\n";
    return 0;
}