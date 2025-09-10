/*
Pasos detallados del Selection Sort:
1. Encuentra el mínimo:
El algoritmo comienza en el primer elemento de la lista y busca el elemento más pequeño en toda la lista. 
2. Intercambia:
Una vez que se encuentra el elemento más pequeño, se intercambia con el elemento que está en la primera posición de la lista. 
3. Repite el proceso:
El algoritmo repite este proceso, pero ahora considera la lista a partir del segundo elemento. Busca el siguiente elemento más pequeño en la parte restante y lo intercambia con el segundo elemento. 
4. Continúa hasta el final:
Se repite este proceso hasta que todos los elementos de la lista estén en su posición correcta, creando así la lista ordenada. 
*/

#include <iostream>
#include <cstdlib>
#include <ctime>

template<std::size_t N>
void IniciarArreglo(int(&array)[N]){ for(int i=0;i<N;i++)array[i]=std::rand()%100; }
template<std::size_t N>
void MostrarArreglo(int(&array)[N]){ for(int i=0;i<N;i++)std::cout<<array[i]<<(i<N-1?" , ":"\n");}
inline void switch_place(int& a, int&b){ int tmp=a; a=b; b=tmp; } 

template<std::size_t N>
// Complejidad: O(N^2) comparaciones y O(1) memoria. No es estable.
void SelectionSort(int(&array)[N]){ 
    // Índice del elemento mínimo dentro de la porción no ordenada
    int min;
    // i delimita el inicio de la parte no ordenada [i..N)
    for(int i=0;i<N-1;i++){
        // Suponemos que el mínimo está en la posición i
        min=i;
        //'swapped' intenta una salida temprana. En Selection Sort,
        // que el mínimo esté ya en 'i' NO garantiza que el resto esté
        // ordenado, por lo que romper aquí puede dejar el arreglo sin ordenar.
        bool swapped=false;
        // Buscar el índice del menor elemento en el rango [i+1..N)
        for(int j=i+1;j<N;j++){
            if(array[j]<array[min]){
                min=j; // Actualiza el índice del mínimo encontrado
            }
        }
        // Si el mínimo está en otra posición, intercámbialo con la posición i
        if(min!=i){
            switch_place(array[i], array[min]);
            swapped=true;
        }

        if(!swapped) break;
    }

}

int main(){
    std::srand(static_cast<unsigned>(std::time(nullptr)));
    int array[20];
    IniciarArreglo(array);
    std::cout<<"Arreglo antes: ";
    MostrarArreglo(array);
    SelectionSort(array);
    std::cout<<"Arreglo despues: ";
    MostrarArreglo(array);
    return 0;
}
