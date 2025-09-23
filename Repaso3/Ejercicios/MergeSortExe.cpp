#include <iostream>

template<std::size_t N>
void InitiateArray(int(&array)[N]){ for(int i=0;i<N;i++) array[i]=std::rand()%100; }

template<std::size_t N>
void ShowArray(int(&array)[N]){ for(int i=0;i<N;i++) std::cout<<array[i]<<(i+1<N?" , ":"\n"); }

template<std::size_t N>
void Merge(int(&array)[N], std::size_t start, std::size_t mid, std::size_t end, int(&tmp)[N]){
    std::size_t i = start;
    std::size_t j = mid;
    std::size_t k = start;
    while(i < mid && j < end){
        if(array[i] <= array[j]) tmp[k++] = array[i++];
        else tmp[k++] = array[j++];
    }
    while(i < mid){ tmp[k++] = array[i++]; }
    while(j < end){ tmp[k++] = array[j++]; }
    for(std::size_t p = start; p < end; p++) array[p] = tmp[p];
}

template<std::size_t N>
void MergeSortRec(int(&array)[N], std::size_t start, std::size_t end, int(&tmp)[N]){
    if(end - start <= 1) return;
    std::size_t mid = start+(end - start)/2;
    MergeSortRec(array, start, mid, tmp);
    MergeSortRec(array, mid, end, tmp);
    Merge(array, start, mid, end, tmp);
}

template<std::size_t N>
void MergeSort(int(&array)[N]){
    int tmp[N];
    MergeSortRec(array, 0, N, tmp);
}

int main(){
    int array[20];
    InitiateArray(array);
    std::cout<<"Arreglo antes: ";
    ShowArray(array);
    MergeSort(array);
    std::cout<<"Arreglo despues: ";
    ShowArray(array);
    return 0;
}