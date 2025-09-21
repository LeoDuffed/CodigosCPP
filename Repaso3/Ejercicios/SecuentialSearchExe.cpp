#include <iostream>

template<std::size_t N>
void InitiateArray(int(&array)[N]){ for(int i=0;i<N;i++)array[i]=i+1; }

template<std::size_t N>
void ShowArray(int(&array)[N]){ for(int i=0;i<N;i++)std::cout<<array[i]<<(i+1<N ? " , ":"\n"); }

template<std::size_t N>
int SecuentialSearch(int(&array)[N], int num){
    for(std::size_t i=0; i<N; i++) if(array[i] == num) return static_cast<int>(i);
    return -1;
}

int main(){
    int array[20];
    int num=8;
    InitiateArray(array);
    ShowArray(array);
    int found = SecuentialSearch(array, num);
    if(found >= 0) std::cout<<"El mumero "<<num<<" fue encontrado en el indice "<<found<<"\n";
    else std::cout<<"El numero "<<num<<" no fue encontrado\n";
    return 0;
}