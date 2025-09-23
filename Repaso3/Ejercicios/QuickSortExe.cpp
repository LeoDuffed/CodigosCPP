#include <iostream>

template<std::size_t N>
void InitiateArray(int(&array)[N]){ for(int i=0;i<N;i++) array[i]=rand()%100; }

template<std::size_t N>
void ShowArray(int(&array)[N]){ for (int i=0;i<N;i++) std::cout<<array[i]<<(i+1<N?" , ":"\n"); }

inline void SwitchInt(int& a, int& b){ int tmp = a; a = b; b = tmp; }

template<std::size_t N>
int Particion(int(&array)[N], int start, int end){
    int pivot = array[end];
    int i = start - 1;
    for(int j = start; j < end; j++){
        if(array[j] <= pivot){
            i++;
            SwitchInt(array[i], array[j]);
        }
    }
    SwitchInt(array[i+1], array[end]);
    return i + 1;
}

template<std::size_t N>
void QuickSortRec(int(&array)[N], int start, int end){
    if(start < end){
        int p = Particion(array, start, end);
        QuickSortRec(array, start, p-1);
        QuickSortRec(array, p+1, end);
    }
}

template<std::size_t N>
void QuickSort(int(&array)[N]){ QuickSortRec(array, 0, N-1); }

int main(){
    int array[20];
    InitiateArray(array);
    std::cout<<"Array antes: ";
    ShowArray(array);
    QuickSort(array);
    std::cout<<"Array despues: ";
    ShowArray(array);
    return 0;
}