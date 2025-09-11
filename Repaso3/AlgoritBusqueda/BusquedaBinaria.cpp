/*
Cómo funciona la búsqueda binaria:
1. Requiere una lista ordenada:
Este es el requisito fundamental del algoritmo. 
2. Comparación con el medio:
Se empieza comparando el valor que se busca con el elemento que se encuentra en el centro de la lista. 
3. Reducción del intervalo:
Si el valor buscado es igual al elemento central, se ha encontrado el elemento y el proceso termina. 
Si el valor buscado es menor que el elemento central, la búsqueda continúa en la mitad izquierda de la lista. 
Si el valor buscado es mayor que el elemento central, la búsqueda continúa en la mitad derecha de la lista. 
4. Repetición:
Se repite este proceso de división y comparación en la sección restante hasta encontrar el elemento o hasta que la sección de búsqueda quede vacía (lo que indica que el elemento no está presente). 
*/

#include <iostream>

template <std::size_t N>
void IniciarArray(int (&array) [N]){for(int i=0;i<N;i++)array[i]=static_cast<int>(i+1);}

template <std::size_t N>
int BusquedaBinaria(const int (&array) [N], int num){
    std::size_t min=0, max=N;
    while(min < max){
        std::size_t halfNum=min+(max-min)/2;
        if(array[halfNum]==num)return static_cast<int>(halfNum);
        if(array[halfNum]<num)min=halfNum+1;
        else max=halfNum-1;
    }
    return -1;
}

int main(){
    int array[20], num=10;
    IniciarArray(array);
    int found=BusquedaBinaria(array, num);
    if(found>=0)std::cout<<"Encontrado en indice: "<<found<<"\n";
    else std::cout<<"No se encontro el numero\n";
    return 0;
}