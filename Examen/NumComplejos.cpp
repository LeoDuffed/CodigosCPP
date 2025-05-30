#include "NumComplejo.h"
#include <iostream> 

// Constructores
NumComplejo :: NumComplejo(){
    a = 1;
    b = 1;
}
NumComplejo :: NumComplejo(int a, int b){
    this -> a = a;
    this -> b = b;
}

// Setter
void NumComplejo :: setA(int a){
    this -> a = a;
}
void NumComplejo :: setB(int b){
    this -> b = b;
}

// Getters
int NumComplejo :: getA(){
    return a;
}
int NumComplejo :: getB(){
    return b;
}

// Funciones
void NumComplejo :: imprimir(){
    std :: cout << getA() << " + " << getB() << "i" << std :: endl; 
}
NumComplejo NumComplejo :: suma(int a2, int b2){
    int newA = a + a2;
    int newB = b + b2;

    return NumComplejo(newA, newB);
    
}
NumComplejo NumComplejo :: resta(int a2, int b2){
    int newA = a - a2;
    int newB = b - b2;

   return NumComplejo(newA, newB);

}