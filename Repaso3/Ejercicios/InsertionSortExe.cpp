#include <iostream>

template<std::size_t N>
void InitiateArray(int(&array)[N]){ for(int i=0;i<N;i++) array[i]=std::rand()%100; }

template<std::size_t N>
void ShowArray(int(&array)[N]){ for(int i=0;i<N;i++) std::cout<<array[i]<<(i+1<N?" , ":"\n"); }

template<std::size_t N>
void InsertionSort(int(&array)[N]){
    for(int i=1;i<N;i++){
        int aux = array[i];
        int j = i-1;
        while (j>=0 && array[j]>aux){
            array[j+1] = array[j];
            j=j-1;
        }
        array[j+1] = aux;
    }
}

int main(){
    int array[20];
    InitiateArray(array);
    std::cout<<"Array antes: ";
    ShowArray(array);
    InsertionSort(array);
    std::cout<<"Array despues: ";
    ShowArray(array);
    return 0;
}