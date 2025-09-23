#include <iostream>

template<std::size_t N>
void InitiateArray(int(&array)[N]){ for(int i=0;i<N;i++) array[i]=std::rand()%100; }

template<std::size_t N>
void ShowArray(int(&array)[N]){ for(int i=0;i<N;i++) std::cout<<array[i]<<(i+1<N?" , ":"\n"); }

inline void SwitchPlace(int& a, int& b){ int tmp=a; a=b; b=tmp; }

template<std::size_t N>
void SelectionSort(int(&array)[N]){
    for(int i=0;i<N-1;i++){
        int min=i;
        for(int j=i+1;j<N;j++){
            if(array[j]<array[min]){
                min=j;
            }
        }
        if(min!=i){
            SwitchPlace(array[i], array[min]);
        }
    }
}

int main(){
    int array[20];
    InitiateArray(array);
    std::cout<<"Array antes: ";
    ShowArray(array);
    SelectionSort(array);
    std::cout<<"Array despues: ";
    ShowArray(array);
    return 0;

}