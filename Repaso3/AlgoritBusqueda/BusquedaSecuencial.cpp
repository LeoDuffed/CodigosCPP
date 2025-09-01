#include <iostream>
#include <cstdlib>
#include <ctime>

void IniciarArreglo(int array[100]){ for(int i=0;i<100;i++) array[i]=rand()%100; }
void MostrarArreglo(int array[100]){ for(int i=0;i<100;i++) std::cout<<array[i]<<" , ";}
void BusquedaSecuencial(int num, int array[100]){
    for(int i=0;i<100;i++){
        if(array[i]==num){
            std::cout<<"Numero encontrado en la posicion: "<<i<<"\n";
            break;
        } 
    }
    std::cout<<"No se encontro el numero: "<<num<<"\n";
}

int main(){
    
    int array[100], num=rand()%100;
    IniciarArreglo(array);
    MostrarArreglo(array);
    std::cout<<"Numero buscado: "<<num<<"\n";
    BusquedaSecuencial(num, array);
    return 0;
}