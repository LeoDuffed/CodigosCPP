#include <iostream>
#include "Peliculas.h"

int main(){

    Peliculas p;
    // Predefinimos las peliculas
	p.AgregarPelicula("La era del hielo","aventura","comedia"," ",1,30);
	p.AgregarPelicula("Titanic","romance","drama"," ",3,15);
	p.AgregarPelicula("Harry Potter y la piedra filosofal","fantasia","aventura"," ",2,32);
	p.AgregarPelicula("Avatar","animacion","aventura","drama",2,42);
	p.AgregarPelicula("El rey Leon","romance","drama","aventura",1,28);
	p.AgregarPelicula("Jurassic Park","aventura","accion","cienciaFiccion",2,7);
	p.AgregarPelicula("Toy Story","animacion","comedia"," ",1,21);
	p.AgregarPelicula("The Dark Knight","accion","drama"," ",2,32);
	p.AgregarPelicula("Finding Nemo","aventura","comedia","animacion",1,40);
	p.AgregarPelicula("Inception","cienciaFiccion","accion"," ",2,28);
	p.AgregarPelicula("Coco","animacion","infantil"," ",1,45);
	p.AgregarPelicula("Interstellar","cienciaFiccion","drama","aventura",2,49);
	p.AgregarPelicula("Shrek","comedia","aventura","animacion",1,35);
	p.AgregarPelicula("Avatar","cienciaFiccion","aventura","fantasia",2,42);
	p.AgregarPelicula("The Lion King","animacion","drama"," ",1,29);

	int eleccion = 1;

	while (eleccion != 0){

		eleccion = 0;

		std :: cout << "\n\n\n --- Bienvenido al catalogo de peliculas --- \n" << std :: endl;
		std :: cout << " 1. Mostrar catalogo" << std :: endl;
		std :: cout << " 2. Buscar pelicula por nombre" << std :: endl;
		std :: cout << " 3. Buscar por genero" << std :: endl;
		std :: cout << " 0. Salir" << std :: endl;
		std :: cout << " \nIngrese su eleccion: ";
		std :: cin >> eleccion;

		switch(eleccion){

			case 1:
				p.MostrarLista();
				break;
			case 2:
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				p.BuscarPorNombre();
				break;
			case 3:
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
                p.MostrarPorGenero();
				break;
			case 0:
				std :: cout << "Saliendo..." << std :: endl;
				break;
			default:
				std :: cout << "Opcion invalida" << std :: endl;
		}
	}
    return 0;
}