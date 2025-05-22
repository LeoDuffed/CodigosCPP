// Creado por Leonardo Martínez Peña
// Hecho para ver como usar listas
// 20/12/2024

#include <iostream> 
using namespace std;


void MostrarTodoVentas(string nombre[4], string productos[5], int ventas[4][5]){

    cout << "\n\nTodas las ventas" << endl;

    int i = 0, j = 0;

    for (i = 0; i < 4; i++){
        for (j = 0; j < 5; j++){

            cout << "La cantidad vendida por la sucursal: "<< nombre[i]<< " para el articulo "<< productos[j]<< " es de "<< ventas[i][j] << " productos"<< endl;

        }
        cout << "\n" << endl;
        j = 0;
    }

}

void MostrarTodoStock(string nombre[4], string productos[5], int stock[4][5]){

    cout << "\n\nTodo el stock" << endl;

    int i = 0, j = 0;

    for (i = 0; i < 4; i++){
        for (j = 0; j < 4; j++){
            cout << "La stock disponible en la sucursal: "<< nombre[i]<< " para el articulo "<< productos[j] << " es de "<< stock[i][j] << " productos" << endl;
        }
        cout << "\n" << endl;
        j = 0; 
    }
}

void MostrarTodasLasVentas(string nombre[4], string productos[5], int ventas[4][5]){

    cout << "\n\nVentas de sucursal" << endl;

    int sucursal = 0;
    bool validar = false;

    while (validar == false){

        for(int i =0; i <=3 ; i++){
            cout << i+1 <<". " << nombre[i] << endl;
        }

        cout << "Ingrese el numero de la sucursal que desea ver: ";
        cin >> sucursal;
        if (sucursal >= 1 && sucursal <= 4){
            validar = true;
        }
    }

    cout << "Has ingresado en: "<< nombre[sucursal - 1] << endl;

    for (int i = 0; i <= 4; i++){
        cout << "La cantidad vendida del articulo " << productos[i] << " fue de: " << ventas[sucursal-1][i] << endl;
    }
}

void MostrarStockEnSucursal(string nombre[4], string productos[5], int stock[4][5]){

    cout << "\n\nStock de sucursal" << endl;

    int sucursal = 0; 
    bool validar = false;

    while(validar == false){

        for (int i = 0; i <= 3; i++){
            cout << i+1 << ". " << nombre[i] << endl;
        }

        cout << "Ingresa el numero de la sucursal que desea ver: ";
        cin >> sucursal;
        if (sucursal >= 1 && sucursal <= 4){
            validar = true;
        }
    }

    cout << "Has ingresado a la sucursal " << nombre[sucursal - 1] << endl;

    for (int i = 0; i <= 4; i++){
        cout << "El estock del producto " << productos[i] << " es de " << stock[sucursal-1][i] << endl;
    }

}

void MostrarVentaDeProducto(string nombre[4], string producto[5], int ventas[4][5]){

    cout << "\n\nVenta de productos en especifico" << endl;

    int sucursal = 0, item = 0;
    bool validar = false;

    while (validar == false){

        for (int i = 0; i <=3; i++){
            cout << i + 1 << ". " << nombre[i] << endl;
        }

        cout << "Ingresa el numero de la sucursal que desa ver: ";
        cin >> sucursal;

        if (sucursal >=1 && sucursal <= 4){
            validar = true;
        }
    }

    cout << "Has ingresado a la sucursal " << nombre[sucursal-1] << endl;

    validar = false;

    while (validar == false){

        for (int i = 0; i <= 4; i++){
            cout << i + 1 << ". Producto: " << producto[i] << endl;
        }

        cout << "Ingresa el numero del producto: ";
        cin >> item;

        if (item >=1 && item <= 5){
            validar = true;
        }
    }

    cout << "Has elegido el producto "<< producto[item -1] << " y se han vendido " << ventas [sucursal - 1][item - 1] << endl;


}

void MostrarStockDeProducto (string nombre[4], string producto[5], int stock[4][5]){

    cout << "\n\nVer el stock en sucursal pedida"<< endl;

    int sucursal = 0, item = 0; 
    bool validar = false;

    while (validar == false){
        for (int i = 0; i < 4; i++){
            cout << i + 1 << ". " << nombre[i] << endl;
        }

        cout << "Ingresa el numero de la sucursal a la que quiera ingresar: ";
        cin >> sucursal;

        if (sucursal >= 1 && sucursal <= 4){
            validar = true; 
        }
    }

    cout << "Has ingresado a la sucursal: " << nombre[sucursal - 1] << endl;

    validar = false;

    while (validar == false){
        for (int i = 0; i < 5; i++){
            cout << i + 1 << ". Producto -> " << producto[i] << endl;
        }

        cout << "Ingresa tu eleccion: ";
        cin >> item;

        if (item >= 1 && item <= 5){
            validar = true;
        }
    }

    cout << "Has elegido el producto " << producto [item - 1] << " y el stock es de: " << stock[sucursal-1][item-1] << endl;

}

void RecaudacionPorSucursal (string nombre[4], int precios[5],int ventas[4][5]){

    cout << "\n\nTodo el dinero recaudado en cada sucursal." << endl;

    int i = 0,j = 0, suma = 0;

    for (i = 0; i < 4; i++){ // i = Tienda
        for (j = 0; j < 5 ; j++ ){ // j = Producto

        suma = suma + (ventas[i][j]* precios[j]);

        if (j == 4){
            cout << "La recaudacion total de la sucursal " << nombre[i] << " es de: $" << suma << endl;
            suma = 0;
         }
        }
        j = 0;
    }

}

void SucursalConMayorVenta(string nombre[4], int ventas [4][5]){

    cout << "\n\nSucursal con mayor ventas." << endl;

    int i = 0, j = 0, suma = 0, mayor = 0, sucursal = 0; 

    for (i = 0; i < 4; i++){
        for (j = 0; j < 5; j++){

            suma = suma + ventas[i][j];
            if (j == 4){
                if (suma > mayor){
                    mayor = suma;
                    sucursal = i;
                }
                suma = 0;
            }
        }
        j = 0;

    }

    cout << "La sucursal con la mayour cantidad de unidades ventidas fue " << nombre[sucursal] << " con el total de: $" << mayor << endl;

}

void SucursalConMayorRecaudacion(string nombre[4],int precios[5], int ventas[4][5]){

    cout << "\n\nRecaudacion total de todas las sucursales."<< endl;

    int i = 0, j = 0, suma = 0, mayor = 0, sucursal = 0;

    for (i = 0; i < 4; i++){
        for (j = 0; j < 5; j++){

            suma = suma + (ventas[i][j] * precios[j]);

            if (j == 4){
                if (suma > mayor){
                    mayor = suma; 
                    sucursal = i;
                }
                suma = 0;
            }

        }
        j = 0;
    }

    cout << "La sucursal con la mayor recaudacion fue " << nombre[sucursal] << " con el total de: $" << mayor << endl;


}

void RecaudacionTotal(string nombre[4], int precios[5], int ventas[4][5]){

    int i = 0, j = 0, suma = 0, sumaTotal = 0;

    for (i = 0; i < 4; i++){
        for (j = 0; j < 5; j++){

            sumaTotal = sumaTotal + (ventas[i][j] * precios[j]);

        }
        j = 0;
    }

    cout << "La recaudacion total de todas las sucursales fue de: $" << sumaTotal << endl; 

}


void Menu(string nombre[4], string productos[5], int precios[5], int stock[4][5], int ventas[4][5]){

    int cont = 0, eleccion = 1;

    while (eleccion != 0 ){

        eleccion = 0;

		cout<<"1) Mostrar cantidad de articulos vendidos de cada articulo por cada sucursal\n";
		cout<<"2) Mostrar cantidad de articulos vendidos de cada articulo en  la sucursal indicada\n";
		cout<<"3) Mostrar cantidad del articulos vendido de un articulo dado de la sucursal indicada\n";
		
		cout<<"4) Mostrar cantidad de stock disponible de cada articulo en la sucursal dada v\n";
		cout<<"5) Mostrar el stock disponible de todos los articulos en cada sucursal\n";
		cout<<"6) Mostrar el stock disponible del articulo indicado en la sucursal dada\n";
		
		cout<<"7 )Mostrar la recaudacion total de cada sucursal\n";
		cout<<"8) Mostrar la sucursal con mayor numero de ventas\n";
		cout<<"9) Mostrar la sucursal de mayor recaudacion\n";
		cout<<"10) Mostrar la recaudacion total de la empresa\n";
		cout<<"0) Salir del programa\n";
		cout<<"Ingrese la opcion que desea realizar: ";

        cin >> eleccion;

        switch (eleccion){

            case 1:
                MostrarTodoVentas(nombre, productos, ventas); 
                break;
            case 2: 
                MostrarTodasLasVentas(nombre, productos, ventas); 
                break;
            case 3: 
                MostrarVentaDeProducto(nombre, productos, ventas); 
                break;
            case 4: 
                MostrarTodoStock(nombre, productos, stock); 
                break;
            case 5: 
                MostrarStockEnSucursal(nombre, productos, stock);
                break;
            case 6: 
                MostrarStockDeProducto(nombre, productos, stock); 
                break;
            case 7: 
                RecaudacionPorSucursal(nombre, precios, ventas);
                break;
            case 8: 
                SucursalConMayorVenta(nombre, ventas);
                break;
            case 9: 
                SucursalConMayorRecaudacion(nombre, precios, ventas);
                break;
            case 10: 
                RecaudacionTotal(nombre, precios, ventas);
                break;
            case 0: 
                cout << "Saliendo..." << endl; 
                break;
            default: 
                cout << "Opcion Invalida" << endl;
        } 
    }

}


int main(){

	string nombre[4]={"Tienda 1","Tienda 2","Tienda 3","Tienda 4"};
	string productos[5]={"Playera","Gorro","Pantalon","Chaleco","Sudadera"};
	int precios[5]={500,250,800,1200,1500};
	int stock[4][5]={{140,200,120,40,95},//sucursal 1, stocks//
					 {50,250,101,52,17},//sucursal 2, stocks
					 {120,90,12,28,93},//sucursal 3, stocks
					 {70,92,12,127,55} //sucursal 4,stocks
                     };

	int ventas[4][5]={{120,100,200,42,20},//sucursal 1, stocks//482
					 {50,70,12,48,20},//sucursal 2, stocks//200
					 {20,17,55,25,33},//sucursal 3, stocks//150
					 {70,42,32,57,45}//sucursal 4,stocks//246
                     };

    Menu(nombre, productos, precios, stock, ventas);

    return 0;
    
}