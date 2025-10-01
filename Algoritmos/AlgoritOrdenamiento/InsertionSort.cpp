/*
Algorithm:
- Initialization: The first element of the array is considered to be a sorted sub-array. 
- Iteration: Starting from the second element (index 1), iterate through the array. 
- Key Selection: For each element in the unsorted portion, store it as key.
- Comparison and Shifting: Compare key with elements in the sorted sub-array from right to left. If an element in the sorted sub-array is greater than key, shift it one position to the right to make space for key. 
- Insertion: Insert key into its correct position in the sorted sub-array.
- Repeat: Continue this process for all remaining elements in the unsorted portion until the entire array is sorted.
*/

#include <iostream>
#include <cstdlib>
#include <ctime>

template<std::size_t N>
void IniciarArreglo(int (&array)[N]){ for(int i=0;i<N;i++) array[i]=std::rand()%100; }
template<std::size_t N>
void MostrarArreglo(int(&array)[N]){for(int i=0;i<N;i++)std::cout<<array[i]<<(i+1<N?" , ":"\n");}

template<std::size_t N>
void InsertionSort(int(&array)[N]){
    for(int i=1;i<N;i++){
        int aux=array[i];
        int j=i-1;
        while(j>=0 && array[j]>aux){
            array[j+1]=array[j];
            j=j-1;
        }
        array[j+1]=aux;
    }
}

int main(){
    std::srand(static_cast<unsigned>(std::time(nullptr)));
    int array[20];
    IniciarArreglo(array);
    std::cout<<"Arreglo antes: ";
    MostrarArreglo(array);
    InsertionSort(array);
    std::cout<<"Arreglo despues: ";
    MostrarArreglo(array);
    return 0;

}