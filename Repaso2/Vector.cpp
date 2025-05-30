#include "Vector.h"
#include <iostream> 

Vector :: Vector(){
    x = 0;
    y = 0;
    z = 0;
}

Vector :: Vector(int x, int y, int z){
    this -> x = x;
    this -> y = y;
    this -> z = z;
}

// Setters
void Vector :: setX(int x){
    this -> x = x;
}
void Vector :: setY(int y){
    this -> y = y;
}
void Vector :: setZ(int z){
    this -> z = z;
}

// Getters

int Vector :: getX(){
    return x;
}
int Vector :: getY(){
    return y;
}
int Vector :: getZ(){
    return z;
}

// Funciones y Metodos
void Vector :: MostrarVec(){
    std :: cout << "[ " << x << " , " << y << " , " << z << " ]" << std :: endl;
}
Vector Vector :: suma(int xDos, int yDos, int zDos){
    int newX = x + xDos;
    int newY = y + yDos;
    int newZ = z + zDos;

    return Vector(newX, newY, newZ);
}
Vector Vector :: resta(int xDos, int yDos, int zDos){
    int newX = x - xDos;
    int newY = y - yDos;
    int newZ = z - zDos;

    return Vector(newX, newY, newZ);
}