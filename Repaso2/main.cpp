#include "Vector.h"
#include <iostream> 

int main(){

    int xUno,yUno,zUno;

    Vector v1;
    std :: cout << "Vector 1: " << std :: endl;
    std :: cout << "Ingresa el valor de 'x': ";
    std :: cin >> xUno;
    v1.setX(xUno);
    std :: cout << "Ingresa el valor de 'y': ";
    std :: cin >> yUno;
    v1.setY(yUno);
    std :: cout << "Ingresa el valor de 'z': ";
    std :: cin >> zUno;
    v1.setZ(zUno);

    v1.MostrarVec();

    int xDos,yDos,zDos;

    Vector v2;
    std :: cout << "Vector 2: " << std :: endl;
    std :: cout << "Ingresa el valor de 'x': ";
    std :: cin >> xDos;
    v2.setX(xDos);
    std :: cout << "Ingresa el valor de 'y': ";
    std :: cin >> yDos;
    v2.setY(yDos);
    std :: cout << "Ingresa el valor de 'z': ";
    std :: cin >> zDos;
    v2.setZ(zDos);

    v2.MostrarVec();

    Vector resultadoSuma = v1.suma(v2.getX(),v2.getY(),v2.getZ());
    std :: cout << "\n\nResultado SUMA: " << std :: endl;
    resultadoSuma.MostrarVec();
    
    Vector resultadoResta = v1.resta(v2.getX(),v2.getY(),v2.getZ());
    std :: cout << "\n\nResultado RESTA: " << std :: endl;
    resultadoResta.MostrarVec();
 

}