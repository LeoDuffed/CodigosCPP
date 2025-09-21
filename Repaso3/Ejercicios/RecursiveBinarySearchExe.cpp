#include <iostream>

template <std::size_t N>
void InitiateArray(int(&array)[N]){
    for(int i = 0; i<N; i++) array[i] = static_cast<int>(i+1);
}

template <std::size_t N>
void ShowArray(int(&array)[N]){ for(int i=0;i<N;i++) std::cout<<array[i]<<(i+1<N ? " , ":" "); }

template<std::size_t N>
int BinarySearch(int(&array)[N], int start, int finish, int num){
    if(start > finish) return -1;
    int mid = start+(finish-start) / 2;
    if(array[mid] == num) return mid;
    if(array[mid] < num) return BinarySearch(array, mid+1, finish, num);
    return BinarySearch(array, start, mid-1, num);
}

template<std::size_t N>
void squema(int(&array)[N], int num){
    int start = 0, finish = static_cast<int>(N) - 1;
    int found = BinarySearch(array, start, finish, num);
    if(found>=0) std::cout<<"\nEl numero "<<num<<" se encontro en el inidice "<<found<<"\n";
    else std::cout<<"\nEl numero "<<num<<" no fue encontrado\n";
}

int main(){
    int array[20];
    int num=8;
    InitiateArray(array);
    ShowArray(array);
    squema(array, num);
    return 0;
}