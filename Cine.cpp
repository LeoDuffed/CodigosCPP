// Programa con listas doblemente enlazadas
// Creado por Leonardo Martínez Peña

#include <iostream> 
using namespace std;

struct Genero{ // Generos posibles de cada pelicula

	bool accion;
	bool aventura;
	bool comedia;
	bool fantasia;
	bool terror;
	bool infantil;
	bool drama;
	bool cienciaFiccion;
	bool romance;
	bool animacion;

};

struct Estreno{ 

    int anio;
    int mes;
    int dia;

};

struct Duracion{

    int horas;
    int min;

};

struct Pelicula{

    string nombre;
    int precio;
    int asientos;
    struct Duracion *duracion;
    struct Estreno *estreno;
    struct Genero genero;
    struct Pelicula *ant, *sig; // Todas las peliculas estan enlazadas entre si (variables para el doble enlace).

};

struct Catalogo{ // Estructura mas grande

    int longitud;
    struct Pelicula *pelicula;
};

Catalogo *lista = NULL; // Inicializamos la lista en NULL (vacia)

Pelicula *CrearNodo(string nombre, int precio, string genero1, string genero2, string genero3, int anio, int mes, int dia, int hora, int min){
	
	// Le damos valores inciales a la lista.
    
	Pelicula *aux = new Pelicula;

    aux->nombre = nombre;
    aux->precio = precio;
    aux->asientos = 150;

    aux->duracion = new Duracion;
    aux->duracion->horas = hora;
    aux->duracion->min = min;

    aux->estreno = new Estreno;
    aux->estreno->anio = anio;
    aux->estreno->mes = mes;
    aux->estreno->dia = dia;

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

int AgregarPelicula (string nombre, int precio, string genero1, string genero2, string genero3, int anio, int mes, int dia, int hora, int min){

    if (lista == NULL){ // Para la primera pelicula
        lista = new Catalogo; // Pedimos memoria para crear una estructura de tipo Catologo.
        lista->longitud = 1;
        lista->pelicula = CrearNodo(nombre, precio, genero1, genero2, genero3, anio, mes, dia, hora, min);

    } else { // Vamos agregando las siguientes peliculas usando la funcion de tipo Catalogo

        Pelicula *aux = lista->pelicula; // Primer elemento de la lista (primera pelicula)
        while (aux != NULL){

			if (aux->sig == NULL){

			    aux->sig = CrearNodo(nombre, precio, genero1, genero2, genero3, anio, mes, dia, hora, min);
				aux->sig->ant = aux; // Creamos el doble enlace en la lista.
				return 0;

			}

            aux = aux->sig;
        }

    }

	return 0;

}

void MostrarNodo(Pelicula *aux){ // Metodo para mostrar cada elemento de la lista

	cout << "\n\nNombre: " << aux->nombre << endl;
	cout << "Precio: $" << aux->precio << endl;
	cout << "Asientos: " << aux->asientos << endl;
	cout<<"Generos: ";

	if(aux->genero.accion)
		cout<<"\n ◊ accion ";
	if(aux->genero.animacion)
		cout<<"\n ◊ animacion ";	
	if(aux->genero.aventura)
		cout<<"\n ◊ aventura ";	
	if(aux->genero.cienciaFiccion)
		cout<<"\n ◊ ciencia ficcion ";	
	if(aux->genero.comedia)
		cout<<"\n ◊ comedia ";	
	if(aux->genero.drama)
		cout<<"\n ◊ drama ";	
	if(aux->genero.fantasia)
		cout<<"\n ◊ fantasia ";	
	if(aux->genero.infantil)
		cout<<"\n ◊ infantil ";	
	if(aux->genero.romance)
		cout<<"\n ◊ romance ";	
	if(aux->genero.terror)
		cout<<"\n ◊ terror ";

	cout << "\nDuracion: " << aux->duracion->horas << " horas, " << aux->duracion->min << " min" << endl;
	cout << "Fecha de estreno: " << aux->estreno->dia << " / " << aux->estreno->mes<< " / " << aux->estreno->anio << endl;
}

void MostrarLista(){ // Metodo para ir recorriendo la lista 

	if (lista == NULL){
		cout << "La lista esta vacia" << endl;
	} else {
		Pelicula *aux = lista->pelicula;
		while (aux != NULL){
			MostrarNodo(aux); // Mandamos a llamar a otro metodo para mostrar la lista
			aux = aux->sig;
		}
	}
}

Pelicula *BuscarPorNombre(){ // Funcion de tipo pelicula que buscar por nombre una pelicula en la lista

	string nombre;

	if (lista == NULL){
		cout << "\nLa lista esta vacia" << endl;

	} else {

		cout << "\n\nIngrese el nombre de la pelicula que estas buscando: ";
		fflush(stdin);
		getline(cin, nombre);
		Pelicula *aux = lista->pelicula;
		while (aux != NULL){

			if(nombre.compare(aux->nombre) == 0){
				MostrarNodo(aux);
				return aux; 
			}
			aux = aux->sig;
		}
	}

	cout << "\nLa pelicula " << nombre << " no ha sido encontrada" << endl;
	return NULL;

}

Pelicula *BuscarPorNombreParaBorrar(){

	string nombre;

	cout << "\nIngresa el nombre de la pelicula que deseas borrar: ";
	fflush(stdin);
	getline(cin, nombre);
	Pelicula *aux = lista->pelicula;
	while (aux != NULL){

		if (nombre.compare(aux->nombre) == 0){
			return aux;
		}
		aux = aux->sig;
	}
	
	cout << "\nLa pelicula " << nombre << " no ha sido encontrada" << endl;
	return 0;
}	


int EliminarPelicula(){ // Metodo para eliminar peliculas en la lista

	if (lista == NULL){
		cout << "La lista esta vacia" << endl;
	} else {

		Pelicula *aux = BuscarPorNombreParaBorrar();

		if (aux != NULL){

			if (lista->pelicula->sig == NULL){ // Si la lista solo tiene un elemento

				delete aux;
				lista = NULL;
				cout << "La pelicula " << aux->nombre << " ha sido eliminada con exito" << endl;
				return 0;

			} else { // Si la lista > 1
			 		
				// Cambiando la direccion de a donde puntas la pelicula anterior y siguiente
				aux->ant->sig = aux->sig; 
				aux->sig->ant = aux->ant;
				delete aux;
				lista->longitud = (lista->longitud - 1);
				cout << "La pelicula " << aux->nombre << " ha sido elimindada con exito" << endl;
				return 0;
				
			}
		}
	}

	return 0;
}

void BuscarPorGenero(string genero){

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

void MostrarPorGenero(){

	string genero;
	
	if (lista == NULL){
		cout << "\nLa lista esta vacia" << endl;
	} else {
		cout << "\n\n --- Opciones: --- " << endl;
		cout << " ✦ Accion" << endl;
		cout << " ✦ Animacion" << endl;
		cout << " ✦ Aventura" << endl;
		cout << " ✦ Ciencia Ficcion" << endl;
		cout << " ✦ Comedia" << endl;
		cout << " ✦ Drama" << endl;
		cout << " ✦ Fantasia" << endl;
		cout << " ✦ Infantil" << endl;
		cout << " ✦ Romance" << endl;
		cout << " ✦ Terror" << endl;
		cout << "Ingrese el genero que desea buscar: ";

		fflush(stdin);
		getline(cin, genero);

		BuscarPorGenero(genero);
	}
}

void PrecioEntradas(){

	if (lista == NULL){
		cout << "La lista esta vacia" << endl;
	} else {
		int cantidad = 0;
		string resp;
		cout << "Ingrese el nombre de la pelicula: ";

		BuscarPorNombre();

		Pelicula *aux = BuscarPorNombre();

		if (aux != NULL){

			cout << "El precio de la pelicula " << aux->nombre << " es de: $" << aux->precio << endl;
			cout << "Deseas comprar entradas (s/n): ";
			cin >> resp;

			if (resp == "S" || resp == "s"){

				cout << "Cuantas entradas deseas comprar: ";
				cin >> cantidad;
				bool validar = ValidadDisponibilidadAsientos(cantidad);


			}

		}

	}
}

void Menu(){
	int eleccion = 1;

	while (eleccion != 0){

		eleccion = 0;

		cout << "\n\n\nBienvenido al catalogo de peliculas" << endl;
		cout << "1. Mostrar catalogo" << endl;
		cout << "2. Buscar pelicula por nombre" << endl;
		cout << "3. Eliminar pelicula" << endl;
		cout << "4. Buscar por genero" << endl;
		cout << "0. Salir" << endl;
		cout << "Ingrese su eleccion: ";
		cin >> eleccion;

		switch(eleccion){

			case 1:
				MostrarLista();
				break;
			case 2:
				BuscarPorNombre();
				break;
			case 3:
				BuscarPorNombreParaBorrar();
				break;
			case 4:
				MostrarPorGenero();
				break;
			case 0:
				cout << "Saliendo..." << endl;
				break;
			default:
				cout << "Opcion invalida" << endl;
		}
	}

}

int main(){

    // Predefinimos las peliculas
	AgregarPelicula("La era del hielo",200,"aventura","comedia"," ",2022,11,4,1,30);
	AgregarPelicula("Titanic",140,"romance","drama"," ",1997,12,19,3,15);
	AgregarPelicula("Harry Potter y la piedra filosofal",130,"fantasia","aventura"," ",2001,11,16,2,32);
	AgregarPelicula("Avatar",104,"animacion","aventura","drama",2009,12,18,2,42);
	AgregarPelicula("El rey Leon",140,"romance","drama","aventura",1994,6,15,1,28);
	AgregarPelicula("Jurassic Park",200,"aventura","accion","cienciaFiccion",1993,6,11,2,7);
	AgregarPelicula("Toy Story",200,"animacion","comedia"," ",1995,11,22,1,21);
	AgregarPelicula("The Dark Knight",200,"accion","drama"," ",2008,7,18,2,32);
	AgregarPelicula("Finding Nemo",200,"aventura","comedia","animacion",2003,5,30,1,40);
	AgregarPelicula("Inception",200,"cienciaFiccion","accion"," ",2010,7,16,2,28);
	AgregarPelicula("Coco",200,"animacion","infantil"," ",2017,11,22,1,45);
	AgregarPelicula("Interstellar",200,"cienciaFiccion","drama","aventura",2014,11,7,2,49);
	AgregarPelicula("Shrek",200,"comedia","aventura","animacion",2001,5,18,1,35);
	AgregarPelicula("Avatar",200,"cienciaFiccion","aventura","fantasia",2009,12,18,2,42);
	AgregarPelicula("The Lion King",200,"animacion","drama"," ",1994,6,24,1,29);

	Menu();

    return 0;
}