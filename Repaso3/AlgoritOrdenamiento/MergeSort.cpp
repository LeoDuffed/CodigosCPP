/*
1. Divide phase
 1- Start with the unsorted array.
 2- Find the midpoint of the array.
 3- Split the array into two smaller halves at the midpoint.
 4- Recursively apply this process to each half.
 5- Continue until every element is in its own sub-array. A sub-array of a single element is considered sorted. 

2. Merge phase
 1- Start with the single-element sub-arrays.
 2- Merge adjacent pairs of sub-arrays into a single, sorted array. This requires a temporary array to hold the merged result.
 3- To merge two sorted sub-arrays, compare the first elements of each sub-array and place the smaller one into the temporary array.
 4- Repeat the comparison, adding the smaller element to the temporary array and moving the corresponding pointer forward.
 5- Once one sub-array is empty, copy any remaining elements from the other sub-array into the temporary one.
 6- Copy the elements from the temporary array back into the original array's segment.
 7- Repeat the merging process with the larger, sorted sub-arrays until the entire array is combined into one final sorted array. 
*/

#include <iostream> 
#include <cstdlib>  
#include <ctime>    

template<std::size_t N>
void IniciarArreglo(int(&array)[N]){ for(std::size_t i = 0; i < N; i++) array[i] = std::rand() % 100; }

template<std::size_t N>
void MostrarArreglo(int(&array)[N]){ for(std::size_t i = 0; i < N; i++) std::cout << array[i]<<(i+1<N?" , ":"\n") ; }

/* MERGE: Fusiona dos subarreglos ordenados [l:m) y [m:r) dentro de 'array'
usando el buffer temporal 'tmp' (del mismo tamaño que 'array').
Rango [l, r) significa: l incluido, r excluido.
- l: inicio del bloque total
- m: separación entre izquierda y derecha (mitad)
- r: final del bloque total (excluido
*/
template<std::size_t N>
void merge(int (&array)[N], std::size_t l, std::size_t m, std::size_t r, int (&tmp)[N]){
    // i recorre la mitad izquierda [l, m)
    std::size_t i = l;
    // j recorre la mitad derecha [m, r)
    std::size_t j = m;
    // k es la posición de escritura en el buffer tmp dentro del rango [l, r)
    std::size_t k = l;

    // Mientras ambos subarreglos tengan elementos por comparar
    while(i < m && j < r){
        // Tomamos el menor entre array[i] y array[j] y lo copiamos a tmp[k]
        // Usar <= hace el algoritmo estable (si son iguales, se respeta el orden original)
        if(array[i] <= array[j]) tmp[k++] = array[i++]; // avanzamos en izquierda
        else tmp[k++] = array[j++]; // avanzamos en derecha
        // k++ avanzamos posición de escritura
    }

    // Si quedaron elementos en la mitad izquierda, los copiamos tal cual
    while(i < m){ tmp[k++] = array[i++ ]; }
    // Si quedaron elementos en la mitad derecha, los copiamos tal cual
    while(j < r){ tmp[k++] = array[j++]; }

    // Finalmente copiamos del buffer temporal de regreso al arreglo original
    // Solo en el rango que acabamos de fusionar [l, r)
    for(std::size_t p = l; p < r; ++p) array[p] = tmp[p]; 
}

/* mergeSortRec: Ordena recursivamente el rango [l, r) de 'array' usando 'tmp'.
Caso base: si el rango tiene 0 o 1 elemento, ya está ordenado.
Paso recursivo: ordenar la mitad izquierda y la derecha, luego fusionar.
*/
template<std::size_t N>
void mergeSortRec(int (&array)[N], std::size_t l, std::size_t r, int (&tmp)[N]){
    // Si el bloque tiene 0 o 1 elemento, no hay nada que ordenar
    if(r - l <= 1) return;

    // Calculamos la mitad evitando overflow: l + (r - l)/2
    std::size_t m = l + (r - l) / 2;
    // Ordenamos recursivamente la mitad izquierda [l, m)
    mergeSortRec(array, l, m, tmp);
    // Ordenamos recursivamente la mitad derecha [m, r)
    mergeSortRec(array, m, r, tmp);
    // Fusionamos ambas mitades ya ordenadas
    merge(array, l, m, r, tmp);
}

/* MergeSort (wrapper):
Crea un buffer temporal 'tmp' una sola vez y ordena todo el arreglo [0, N).
*/ 
template<std::size_t N>
void MergeSort(int(&array)[N]){
    // Buffer temporal del mismo tamaño que el arreglo.
    // Al estar en una función plantilla, N es constante en compilación y
    // esta declaración es válida como arreglo C de tamaño fijo.
    int tmp[N];
    // Llamamos a la función recursiva sobre todo el rango [0, N)
    mergeSortRec(array, 0, N, tmp);
}

int main(){
    std::srand(static_cast<unsigned>(std::time(nullptr)));
    int array[20];
    IniciarArreglo(array);
    std::cout << "Arreglo antes:\n";
    MostrarArreglo(array);
    MergeSort(array);
    std::cout << "Arreglo despues:\n";
    MostrarArreglo(array);
    return 0;
}
