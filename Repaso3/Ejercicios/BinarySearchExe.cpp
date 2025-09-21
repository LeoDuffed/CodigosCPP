#include <iostream>

template <std::size_t N>
void InitiateArray(int(&array)[N]){
    for(int i = 0; i<N; i++) array[i] = static_cast<int>(i+1);
}

template <std::size_t N>
void ShowArray(int(&array)[N]){ for(int i=0;i<N;i++) std::cout<<array[i]<<(i+1<N ? " , ":" "); }

template<std::size_t N>
int BinarySearch(int(&array)[N], int num){
    std::size_t start=0, finish=N-1;
    while (start <= finish){
        std::size_t mid=start+(finish-start)/2;
        if(array[mid] == num) return static_cast<int>(mid);
        if(array[mid] < num) start=mid+1;
        else finish=mid-1;
    }
    return -1;
}

int main(){
    int array[20];
    int num=8;
    InitiateArray(array);
    ShowArray(array);
    int found=BinarySearch(array, num);
    if(found >= 0) std::cout<<"\nSe encontro el numero "<<num<<" en el indice "<<found<<"\n";
    else std::cout<<"\nNo se encontro el nuermo\n";
    return 0;
}