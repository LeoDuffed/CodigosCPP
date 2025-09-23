#include <iostream>

template <std::size_t N>
void InitiateArray(int(&array)[N]){ for(int i=0;i<N;i++) array[i]=std::rand()%100; }

template <std::size_t N>
void ShowArray(int(&array)[N]){ for(int i=0;i<N;i++) std::cout<<array[i]<<(i+1<N?" , ":"\n"); }

inline void SwapNum(int& a, int& b){ int tmp=a; a=b; b=tmp; }

template <std::size_t N>
void BubbleSort(int(&array)[N]){
    for(int i=0;i<N-1;i++){
        bool swapped = false;
        for(int j=0;j<N-i-1;j++){
            if(array[j]>array[j+1]){
                SwapNum(array[j], array[j+1]);
                swapped = true;
            }
        }
        if(!swapped) break;
    }
}

int main(){
    int array[20];
    InitiateArray(array);
    std::cout<<"Array antes: ";
    ShowArray(array);
    BubbleSort(array);
    std::cout<<"Array despues: ";
    ShowArray(array);
    return 0;
}