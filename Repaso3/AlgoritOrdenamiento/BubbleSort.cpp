/*
Pasos del algoritmo:
- Iniciar una pasada: Comienza desde el primer elemento de la lista. 
- Comparar elementos adyacentes: Toma un par de elementos consecutivos y compara sus valores. 
- Intercambiar si es necesario: Si los elementos no están en el orden correcto (por ejemplo, si el primer elemento es mayor que el segundo para un orden ascendente), intercámbialos de posición. 
- Continuar hasta el final: Repite los pasos 2 y 3 para todos los pares adyacentes de la lista, hasta llegar al final. Al final de esta primera pasada, el elemento más grande de toda la lista estará en su posición correcta al final. 
- Repetir el proceso: Vuelve a empezar desde el principio para la siguiente pasada. Sin embargo, ya no necesitas revisar el último elemento, ya que está en su lugar. En cada pasada sucesiva, el rango de elementos que necesitas comparar disminuye en uno. 
- Finalizar cuando no haya cambios: Si una pasada completa de la lista se realiza sin ningún intercambio, significa que la lista ya está ordenada y el algoritmo termina. 

*/

#include <iostream>
#include <cstdlib>
#include <ctime>

template<std::size_t N>
void IniciarArreglo(int(&array)[N]){ for(int i=0;i<N;i++)array[i]=std::rand()%100;}
template<std::size_t N>
void MostrarArreglo(int(&array)[N]){ for(int i=0;i<N;i++)std::cout<<array[i]<<(i+1<N?" , ":"\n"); }
inline void swap_int(int& a, int& b){ int tmp=a; a=b; b=tmp; } // Funcion para no usar std::swap

template<std::size_t N>
void BubbleSort(int(&array)[N]){
    for(int i=0;i<N-1;i++){
        bool swapped = false;
        for(int j=0;j<N-i-1;j++){
            if(array[j]>array[j+1]){
                swap_int(array[j], array[j+1]);
                swapped=true;
            }
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
    BubbleSort(array);
    std::cout<<"Arreglo despues: ";
    MostrarArreglo(array);
    return 0;
}