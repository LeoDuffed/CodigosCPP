#include "Peliculas.h"

Pelicula* Peliculas :: CrearNodo(std :: string nombre, std :: string genero1, std :: string genero2, std :: string genero3, int hora, int min){
	
	// Le damos valores inciales a la lista.
    
	Pelicula *aux = new Pelicula;

    aux->nombre = nombre;

    aux->duracion = new Duracion;
    aux->duracion->horas = hora;
    aux->duracion->min = min;

    aux->genero.accion=false;
	aux->genero.animacion=false;
	aux->genero.aventura=false;
	aux->genero.cienciaFiccion=false;
	aux->genero.comedia=false;
	aux->genero.drama=false;
	aux->genero.fantasia=false;
	aux->genero.infantil=false;
	aux->genero.romance=false;
	aux->genero.terror=false;

    // Para que tipo de genero es
	if(genero1.compare("accion")==0 || genero2.compare("accion")==0 || genero3.compare("accion")==0)
		aux->genero.accion=true;
	if(genero1.compare("aventura")==0 || genero2.compare("aventura")==0 || genero3.compare("aventura")==0)
		aux->genero.aventura=true;
	if(genero1.compare("animacion")==0 || genero2.compare("animacion")==0 || genero3.compare("animacion")==0)
		aux->genero.animacion=true;
	if(genero1.compare("comedia")==0 || genero2.compare("comedia")==0 || genero3.compare("comedia")==0)
		aux->genero.comedia=true;
	if(genero1.compare("terror")==0 || genero2.compare("terror")==0 || genero3.compare("terror")==0)
		aux->genero.terror=true;
	if(genero1.compare("infantil")==0 || genero2.compare("infantil")==0 || genero3.compare("infantil")==0)
		aux->genero.infantil=true;
	if(genero1.compare("drama")==0 || genero2.compare("drama")==0 || genero3.compare("drama")==0)
		aux->genero.drama=true;
	if(genero1.compare("fantasia")==0 || genero2.compare("fantasia")==0 || genero3.compare("fantasia")==0)
		aux->genero.fantasia=true;
	if(genero1.compare("romance")==0 || genero2.compare("romance")==0 || genero3.compare("romance")==0)
		aux->genero.romance=true;
	if(genero1.compare("ciencia ficcion")==0 || genero2.compare("ciencia ficcion")==0 || genero3.compare("ciencia ficcion")==0)
		aux->genero.romance=true;

	aux->sig=NULL;
	aux->ant=NULL;

    return aux;
}



Peliculas :: Peliculas(){ // Constructor
    lista = new Catalogo;
    lista -> longitud = 0;
    lista -> pelicula = nullptr;
}

int Peliculas :: AgregarPelicula (std :: string nombre, std :: string genero1, std :: string genero2, std :: string genero3, int hora, int min){

    if (lista -> pelicula == nullptr){ // Para la primera pelicula
        lista = new Catalogo; // Pedimos memoria para crear una estructura de tipo Catologo.
        lista->longitud = 1;
        lista->pelicula = CrearNodo(nombre, genero1, genero2, genero3, hora, min);

    } else { // Vamos agregando las siguientes peliculas usando la funcion de tipo Catalogo

        Pelicula *aux = lista->pelicula; // Primer elemento de la lista (primera pelicula)
        while (aux != NULL){

			if (aux->sig == NULL){

			    aux->sig = CrearNodo(nombre, genero1, genero2, genero3, hora, min);
				aux->sig->ant = aux; // Creamos el doble enlace en la lista.
                lista -> longitud++;
				return 0;

			}

            aux = aux->sig;
        }

    }

	return 0;

}
void Peliculas :: BuscarPorGenero(std :: string genero){ // Metodo para buscar peliculas por genero

	Pelicula *aux = lista->pelicula;
	while (aux != NULL){

		if ((genero.compare("accion") == 0 || genero.compare("Accion") == 0) && aux->genero.accion){
			MostrarNodo(aux);
		}
		if ((genero.compare("animacion") == 0 || genero.compare("Animacion") == 0) && aux->genero.animacion){
			MostrarNodo(aux);
		}
		if ((genero.compare("aventura") == 0 || genero.compare("Aventura") == 0) && aux->genero.aventura){
			MostrarNodo(aux);
		}
		if ((genero.compare("ciencia ficcion") == 0 || genero.compare("Ciencia Ficcion") == 0) && aux->genero.cienciaFiccion){
			MostrarNodo(aux);
		}
		if ((genero.compare("comedia") == 0 || genero.compare("Comedia") == 0) && aux->genero.comedia){
			MostrarNodo(aux);
		}
		if ((genero.compare("drama") == 0 || genero.compare("Drama") == 0) && aux->genero.drama){
			MostrarNodo(aux);
		}
		if ((genero.compare("fantasia") == 0 || genero.compare("Fantasia") == 0) && aux->genero.fantasia){
			MostrarNodo(aux);
		}
		if ((genero.compare("infantil") == 0 || genero.compare("Infantil") == 0) && aux->genero.infantil){
			MostrarNodo(aux);
		}
		if ((genero.compare("romance") == 0 || genero.compare("Romance") == 0) && aux->genero.romance){
			MostrarNodo(aux);
		}
		if ((genero.compare("terror") == 0 || genero.compare("Terror") == 0) && aux->genero.terror){
			MostrarNodo(aux);
		}

		aux = aux->sig;
	}
}
void Peliculas :: MostrarNodo(Pelicula *aux){ // Metodo para mostrar cada elemento de la lista

	std :: cout << "\n\nNombre: " << aux->nombre << std :: endl;
	std :: cout<<"Generos: ";

	if(aux->genero.accion)
		std :: cout<<"\n ◊ accion ";
	if(aux->genero.animacion)
		std :: cout<<"\n ◊ animacion ";	
	if(aux->genero.aventura)
		std :: cout<<"\n ◊ aventura ";	
	if(aux->genero.cienciaFiccion)
		std :: cout<<"\n ◊ ciencia ficcion ";	
	if(aux->genero.comedia)
		std :: cout<<"\n ◊ comedia ";	
	if(aux->genero.drama)
		std :: cout<<"\n ◊ drama ";	
	if(aux->genero.fantasia)
		std :: cout<<"\n ◊ fantasia ";	
	if(aux->genero.infantil)
		std :: cout<<"\n ◊ infantil ";	
	if(aux->genero.romance)
		std :: cout<<"\n ◊ romance ";	
	if(aux->genero.terror)
		std :: cout<<"\n ◊ terror ";

	std :: cout << "\nDuracion: " << aux->duracion->horas << " horas, " << aux->duracion->min << " min" << std :: endl;
}
void Peliculas :: MostrarPorGenero(){ // Menu del metodo BuscarPorGenero
	std :: string genero;
	
	if (lista == NULL){
		std :: cout << "\nLa lista esta vacia" << std :: endl;
	} else {
		std :: cout << "\n\n --- Opciones: --- " << std :: endl;
		std :: cout << " ✦ Accion" << std :: endl;
		std :: cout << " ✦ Animacion" << std :: endl;
		std :: cout << " ✦ Aventura" << std :: endl;
		std :: cout << " ✦ Ciencia Ficcion" << std :: endl;
		std :: cout << " ✦ Comedia" << std :: endl;
		std :: cout << " ✦ Drama" << std :: endl;
		std :: cout << " ✦ Fantasia" << std :: endl;
		std :: cout << " ✦ Infantil" << std :: endl;
		std :: cout << " ✦ Romance" << std :: endl;
		std :: cout << " ✦ Terror" << std :: endl;
		std :: cout << "Ingrese el genero que desea buscar: ";

		fflush(stdin);
		std :: getline(std :: cin, genero);

		BuscarPorGenero(genero);
	}
}
void Peliculas :: MostrarLista(){ // Metodo para ir recorriendo la lista 

	if (lista == NULL){
		std :: cout << "La lista esta vacia" << std :: endl;
	} else {
        std::cout << "\nMostrando " << lista->longitud << " película(s):\n";
		Pelicula *aux = lista->pelicula;
		while (aux != NULL){
			MostrarNodo(aux); // Mandamos a llamar a otro metodo para mostrar la lista
			aux = aux->sig;
		}
	}
}
Pelicula* Peliculas :: BuscarPorNombre(){ // Funcion de tipo pelicula que buscar por nombre una pelicula en la lista

	std :: string nombre;

	if (lista == NULL){
		std :: cout << "\nLa lista esta vacia" << std :: endl;

	} else {

		std :: cout << "\n\nIngrese el nombre de la pelicula que estas buscando: ";
		fflush(stdin);
		std :: getline(std :: cin, nombre);
		Pelicula *aux = lista->pelicula;
		while (aux != NULL){

			if(nombre.compare(aux->nombre) == 0){
				MostrarNodo(aux);
				return aux; 
			}
			aux = aux->sig;
		}
	}

	std :: cout << "\nLa pelicula " << nombre << " no ha sido encontrada" << std :: endl;
	return NULL;

}