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
        else max=halfNum;
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