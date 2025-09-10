/*
Quick Sort – Pasos del algoritmo:
1. Elegir un pivote
   - Seleccionar un elemento del arreglo (comúnmente el último o el primero).
   - El pivote servirá como referencia para dividir el arreglo.
2. Partición
   - Recorremos el arreglo comparando cada elemento con el pivote.
   - Si el elemento es menor o igual al pivote, lo colocamos a la izquierda.
   - Si es mayor, se queda a la derecha.
   - Al terminar, el pivote queda en su posición final ordenada.
3. Llamadas recursivas
   - Ordenamos recursivamente los dos subarreglos:
       a) Los elementos menores o iguales al pivote.
       b) Los elementos mayores al pivote.
4. Caso base
   - Cuando el subarreglo tiene 0 o 1 elemento, ya está ordenado y no se hace nada.
5. Complejidad
   - Promedio y mejor caso: O(n log n).
   - Peor caso: O(n^2) (si el pivote siempre es el mínimo o máximo).
   - Es un algoritmo “in-place”: no necesita arreglos auxiliares grandes.
*/


#include <iostream>
#include <cstdlib>
#include <ctime>

template<std::size_t N>
void IniciarArreglo(int(&array)[N]){ for(std::size_t i=0;i<N;i++) array[i]=std::rand()%100; }

template<std::size_t N>
void MostrarArreglo(int(&array)[N]){ for(std::size_t i=0;i<N;i++) std::cout<<array[i]<<(i+1<N?" , ":"\n"); }

/* Función de partición 
Elige el último elemento como pivote.
Reordena el arreglo de modo que todos los elementos <= pivote
queden a su izquierda, y los > pivote a su derecha.
Devuelve el índice final del pivote.
*/ 
template<std::size_t N>
int particion(int (&array)[N], int l, int r){
    int pivote = array[r]; // pivote = último elemento
    int i = l - 1;         // i marca la frontera de los <= pivote

    for(int j = l; j < r; j++){
        if(array[j] <= pivote){
            i++;
            // Intercambiamos array[i] y array[j]
            int temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
    }
    // Colocamos el pivote en su lugar correcto
    int temp = array[i+1];
    array[i+1] = array[r];
    array[r] = temp;

    return i + 1; // posición final del pivote
}

/* QuickSort recursivo
Ordena el rango [l, r] del arreglo (ambos incluidos).
*/
template<std::size_t N>
void quickSortRec(int (&array)[N], int l, int r){
    if(l < r){ 
        // Particionamos el rango
        int p = particion(array, l, r);
        // Ordenamos la parte izquierda (menores al pivote)
        quickSortRec(array, l, p - 1);
        // Ordenamos la parte derecha (mayores al pivote)
        quickSortRec(array, p + 1, r);
    }
}

/* Wrapper QuickSort
Ordena todo el arreglo llamando a quickSortRec en [0, N-1].
*/
template<std::size_t N>
void QuickSort(int(&array)[N]){
    quickSortRec(array, 0, N - 1);
}


int main(){
    std::srand(static_cast<unsigned>(std::time(nullptr)));
    int array[20];
    IniciarArreglo(array);
    std::cout << "Arreglo antes:\n";
    MostrarArreglo(array);
    QuickSort(array);
    std::cout << "Arreglo despues:\n";
    MostrarArreglo(array);
    return 0;
}
